#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "carthesian_path_algorithm");
    ros::NodeHandle nh;

    ros::AsyncSpinner spin(1);
    spin.start();

    /* This sleep is ONLY to allow Rviz to come up */
    sleep(2.0);

    // We obtain the current planning scene and wait until everything is up
    // and running, otherwise the request won't succeed
    moveit::planning_interface::PlanningSceneInterface current_scene;
    moveit::planning_interface::MoveGroupInterface group("panda_arm");
    moveit::planning_interface::MoveGroupInterface::Plan plan;


    ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
    ROS_INFO("End effector link: %s", group.getEndEffectorLink().c_str());

    // set the reference frame for the end effector pose
    group.setPoseReferenceFrame("panda_link0");

    // Set maximum velocity scaling factor
    group.setMaxVelocityScalingFactor(0.1);  // Set the factor to 0.1 (10% of maximum velocity)
    
    // Set the joint angles for the robot arm
    std::vector<double> joint_group_positions = {0, -0.785, 0, -2.356, 0, 1.571, 0.785};

    group.setJointValueTarget(joint_group_positions);

    moveit::planning_interface::MoveItErrorCode success = group.plan(plan);
    ROS_INFO("Visualizing plan - initial %s",success.val ? "":"FAILED");   
    sleep(1.0);
    ROS_INFO("Motion initial planned");
    group.execute(plan);
    ROS_INFO("Motion initial executed");

    ros::shutdown();

    return 0;
}

