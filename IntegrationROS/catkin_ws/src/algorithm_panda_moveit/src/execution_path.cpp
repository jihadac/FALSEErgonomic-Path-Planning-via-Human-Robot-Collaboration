#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <iostream>
#include <fstream>

#include <moveit/robot_trajectory/robot_trajectory.h>
#include <moveit/trajectory_processing/iterative_time_parameterization.h>

// Move robot to start_node and let it then follow the planned path

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "execution_path");
    ros::NodeHandle nh;

    ros::AsyncSpinner spin(1);
    spin.start();

    /* This sleep is ONLY to allow Rviz to come up */
    sleep(2.0);

    // We obtain the current planning scene and wait until everything is up
    // and running, otherwise the request won't succeed
    moveit::planning_interface::PlanningSceneInterface current_scene;
    moveit::planning_interface::MoveGroupInterface group("panda_arm");

    ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
    ROS_INFO("End effector link: %s", group.getEndEffectorLink().c_str());

    // set the reference frame for the end effector pose
    group.setPoseReferenceFrame("panda_link0");

    // Set maximum velocity scaling factor
    group.setMaxVelocityScalingFactor(0.1);  // Set the factor to 0.1 (10% of maximum velocity)

    // Get the current pose of the end effector
    geometry_msgs::PoseStamped current_pose = group.getCurrentPose();

    // Create a pose to move the robot to the start_node
    geometry_msgs::Pose tpose;  
        
    std::ifstream infile("/home/mainuser/Jihad/catkin_ws/src/algorithm/src/paths/path8.txt");
    std::string line;

    std::getline(infile, line);
    std::istringstream iss(line);

    // New pose target has the same orientation as the current pose, but a different position
    if (iss >> tpose.position.x >> tpose.position.y >> tpose.position.z) {
        tpose.orientation = current_pose.pose.orientation;
        // set the new pose target
        group.setPoseTarget(tpose);

        }

    moveit::planning_interface::MoveGroupInterface::Plan plan1;
    moveit::planning_interface::MoveItErrorCode success = group.plan(plan1); 
    ROS_INFO("Visualizing plan 1 - move to start_node %s",success.val ? "":"FAILED");   
    ROS_INFO("Motion planned");
    group.execute(plan1);
    ROS_INFO("Motion executed");
    
    sleep(4.0);
    // Define waypoints to execute planned path as a cartesian path
    std::vector<geometry_msgs::Pose> waypoints;

    while (std::getline(infile, line)) {  // Read the file line by line
        std::istringstream iss(line);

        // Plan a Cartesian path by specifying a list of waypoints for the end-effector to go trough
        if (iss >> tpose.position.x >> tpose.position.y >> tpose.position.z) {
            waypoints.push_back(tpose);
        }
    }

    // Print the number of lines and waypoints
    std::cout << "Number of waypoints: " << waypoints.size() << std::endl;

    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0; // Disabling jump treshold
    const double eef_step = 0.01; // Max step in Cartesian translation, Interpolate the Cartesian path at resolution of 1 cm
    double fraction = group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
    ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% achieved)", fraction * 100.0);

    // Create a RobotTrajectory object from your cartesian path
    robot_trajectory::RobotTrajectory r_trajec(group.getCurrentState()->getRobotModel(), "panda_arm");
    r_trajec.setRobotTrajectoryMsg(*group.getCurrentState(), trajectory);

    // Apply velocity constraints
    trajectory_processing::IterativeParabolicTimeParameterization iptp;
    iptp.computeTimeStamps(r_trajec, 0.1);

    // Get the time-stamped trajectory as a MoveIt! message
    moveit_msgs::RobotTrajectory result_traj;
    r_trajec.getRobotTrajectoryMsg(result_traj);

    moveit::planning_interface::MoveGroupInterface::Plan plan;

    plan.trajectory_ = result_traj;
    sleep(2.0);
    group.execute(plan);
    ROS_INFO("Trajectory is executed");

    ros::shutdown();

    return 0;
}