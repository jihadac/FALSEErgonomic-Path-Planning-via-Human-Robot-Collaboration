#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "find_reachable_points_robot_workspace");
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
    
    // Set the joint angles for the robot arm
    std::vector<double> joint_group_positions = {0, -0.785, 0, -2.356, 0, 1.571, 0.785};

    // get the current pose of the end effector
    geometry_msgs::Pose tpose = group.getCurrentPose(group.getEndEffectorLink()).pose;
    moveit::planning_interface::MoveGroupInterface::Plan plan;

    std::ifstream infile("/home/mainuser/Jihad/catkin_ws/src/algorithm/src/tuples.txt"); // Read file
    std::string line;
    int count = 0;

    std::ofstream outfile("/home/mainuser/Jihad/catkin_ws/src/algorithm/src/unreachable_points.txt"); // Write file
    int count_unreachable = 0;

    while (std::getline(infile, line)) {  // Read the file line by line
        count++;  // Increment the line count
        std::istringstream iss(line);

        // Let robot go to every point stored in tuples.txt
        if (iss >> tpose.position.x >> tpose.position.y >> tpose.position.z) {
            // set the new pose target
            group.setPoseTarget(tpose);
        }

        moveit::planning_interface::MoveItErrorCode success = group.plan(plan);
        ROS_INFO("Visualizing plan - point %s",success.val ? "":"FAILED");   
        sleep(1.0);

        // If point cannot be reached by robot, add it the unreachable_points.txt file
        if (success != moveit::planning_interface::MoveItErrorCode::SUCCESS) {
        outfile << tpose.position.x << " " << tpose.position.y << " " << tpose.position.z << std::endl;
        count_unreachable++;
        }
        ROS_INFO("Motion planned");
        ROS_INFO("Target pose: x=%f, y=%f, z=%f", tpose.position.x, tpose.position.y, tpose.position.z);
        group.execute(plan);
        ROS_INFO("Motion executed");

        // Let robot go back to initial configuration
        group.setJointValueTarget(joint_group_positions);
        success = group.plan(plan); 
        ROS_INFO("Visualizing plan - initial %s",success.val ? "":"FAILED");   
        sleep(1.0);
        ROS_INFO("Motion initial planned");
        group.execute(plan);
        ROS_INFO("Motion initial executed");
    }

    // Print the number of candidate points and the number of unreachable points
    std::cout << "Number of lines in the file: " << count << std::endl;
    std::cout << "Number of points unreachable for robot: " << count_unreachable << std::endl;

    outfile.close();
   
    ros::shutdown();

    return 0;
}