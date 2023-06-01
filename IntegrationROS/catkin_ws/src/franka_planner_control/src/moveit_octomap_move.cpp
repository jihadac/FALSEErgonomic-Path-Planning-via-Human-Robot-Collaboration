#include <ros/ros.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>


Eigen::Matrix3d elementary_zrotation_robot2world_; // define rotation matrix from robot to world frame
Eigen::Quaterniond quat_robot2world_;


int main(int argc, char** argv)
{
  ros::init(argc, argv, "moveit_static_move");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  /* Setup (same as move_group_interface_tutorial.cpp)
     ++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
  bool success; 
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  moveit::core::RobotStatePtr current_state;
  std::vector<double> joint_group_positions;

  static const std::string PLANNING_GROUP = "panda_arm";
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  const robot_state::JointModelGroup* joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  move_group.setStartState(*move_group.getCurrentState());
  move_group.setPlanningTime(0.2); 
  move_group.setMaxVelocityScalingFactor(0.5);
  move_group.setMaxAccelerationScalingFactor(0.5);
  move_group.setNumPlanningAttempts(10);

  /* Set plannerId */
//   const std::string plannerId = "PRMkConfigDefault";
//   const std::string plannerId = "RRTstarkConfigDefault";
  const std::string plannerId = "RRTConnectkConfigDefault";
  // const std::string plannerId = "TRRTkConfigDefault";
  move_group.setPlannerId(plannerId);  


  /* Visualization (same as move_group_interface_tutorial.cpp)
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("panda_link0");
  visual_tools.deleteAllMarkers();
  visual_tools.loadRemoteControl();

  Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
  text_pose.translation().z() = 1.0;
  visual_tools.publishText(text_pose, "Plan a path with MoveIt and execute it", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();


  /* Getting Basic Information (same as move_group_interface_tutorial.cpp)
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group.getPlanningFrame().c_str());
  ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());
  ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
  std::copy(move_group.getJointModelGroupNames().begin(), move_group.getJointModelGroupNames().end(),
            std::ostream_iterator<std::string>(std::cout, ", "));

  std::cout<<move_group.getCurrentPose().pose<<std::endl;


  /* Transformation from world (table) frame to robot frame
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
  elementary_zrotation_robot2world_ = Eigen::AngleAxisd(-140*M_PI/180, Eigen::Vector3d::UnitZ()); 
  quat_robot2world_ = Eigen::Quaterniond(elementary_zrotation_robot2world_);


  /* 1) Add obstacles to the environment
     +++++++++++++++++++++++++++++++++++ */


  /* 2) Plan to the first pose goal and execute trajectory
     +++++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to plan to the pose where we will pick up object 1");

  /* Get the current robot state*/
  current_state = move_group.getCurrentState();
  current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
  move_group.setStartState(*move_group.getCurrentState());

  geometry_msgs::Pose target_pose1;
  target_pose1.position.x = 0.6; 
  target_pose1.position.y = -0.3; 
  target_pose1.position.z = 0.15; 
  target_pose1.orientation.x = 0.7071068; 
  target_pose1.orientation.y = -0.7071068;  
  target_pose1.orientation.z = 0;
  target_pose1.orientation.w = 0;
  move_group.setPoseTarget(target_pose1);

  success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "" : "FAILED");
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
  visual_tools.publishAxisLabeled(target_pose1, "pose1");
  visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools.trigger();

  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to execute this plan");
  move_group.execute(my_plan);

  /* 3) Plan to the second pose goal and execute trajectory
     +++++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to plan to the pose where we will place object 1");

   /* Get the current robot state*/
   current_state = move_group.getCurrentState();
   current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
   move_group.setStartState(*move_group.getCurrentState());
   
   geometry_msgs::Pose target_pose2;
   target_pose2.position.x = 0.4;
   target_pose2.position.y = -0.2;
   target_pose2.position.z = 0.35; 
   target_pose2.orientation.x = 0.7071068;
   target_pose2.orientation.y = -0.7071068; 
   target_pose2.orientation.z = 0; 
   target_pose2.orientation.w = 0; 
   move_group.setPoseTarget(target_pose2);

   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
   ROS_INFO_NAMED("tutorial", "Visualizing plan 2 (pose goal) %s", success ? "" : "FAILED");
   ROS_INFO_NAMED("tutorial", "Visualizing plan 2 as trajectory line");
   visual_tools.deleteAllMarkers();
   visual_tools.publishAxisLabeled(target_pose2, "pose2");
   visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
   visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
   visual_tools.trigger();

   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to execute this plan");
   move_group.execute(my_plan);


   /* 4) Plan to the third pose goal and execute trajectory
     +++++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to plan to the pose where we will pick up object 2");

   /* Get the current robot state*/
   current_state = move_group.getCurrentState();
   current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
   move_group.setStartState(*move_group.getCurrentState());
   
   geometry_msgs::Pose target_pose3;
   target_pose3.position.x = 0.4;
   target_pose3.position.y = 0.0;
   target_pose3.position.z = 0.15; 
   target_pose3.orientation.x = 1;
   target_pose3.orientation.y = 0; 
   target_pose3.orientation.z = 0; 
   target_pose3.orientation.w = 0; 
   move_group.setPoseTarget(target_pose3);

   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
   ROS_INFO_NAMED("tutorial", "Visualizing plan 3 (pose goal) %s", success ? "" : "FAILED");
   ROS_INFO_NAMED("tutorial", "Visualizing plan 3 as trajectory line");
   visual_tools.deleteAllMarkers();
   visual_tools.publishAxisLabeled(target_pose3, "pose3");
   visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
   visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
   visual_tools.trigger();

   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to execute this plan");
   move_group.execute(my_plan);


   /* 5) Plan to the fourth pose goal and execute trajectory
     +++++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to plan to the pose where we will place object 2");

   /* Get the current robot state*/
   current_state = move_group.getCurrentState();
   current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
   move_group.setStartState(*move_group.getCurrentState());
   
   geometry_msgs::Pose target_pose4;
   target_pose4.position.x = 0.35;
   target_pose4.position.y = 0.25;
   target_pose4.position.z = 0.4; 
   target_pose4.orientation.x = 1;
   target_pose4.orientation.y = 0; 
   target_pose4.orientation.z = 0; 
   target_pose4.orientation.w = 0; 
   move_group.setPoseTarget(target_pose4);

   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
   ROS_INFO_NAMED("tutorial", "Visualizing plan 3 (pose goal) %s", success ? "" : "FAILED");
   ROS_INFO_NAMED("tutorial", "Visualizing plan 3 as trajectory line");
   visual_tools.deleteAllMarkers();
   visual_tools.publishAxisLabeled(target_pose4, "pose4");
   visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
   visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
   visual_tools.trigger();

   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to execute this plan");
   move_group.execute(my_plan);


   /* 6) Planning to the initial joint-space goal (without obstacles in the workspace)
      ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to go to the initial robot configuration");

   /* Get the current set of joint values for the group.*/
   current_state = move_group.getCurrentState();
   current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
   move_group.setStartState(*move_group.getCurrentState());

   /* Modify the joints */
   joint_group_positions[0] = -1.13434e-05;    // radians
   joint_group_positions[1] = -0.786148;       // radians
   joint_group_positions[2] = -0.000365677;    // radians
   joint_group_positions[3] = -2.35475;        // radians
   joint_group_positions[4] = 0.000670376;     // radians
   joint_group_positions[5] = 1.57193;         // radians
   joint_group_positions[6] = 0.784775;        // radians
   move_group.setJointValueTarget(joint_group_positions);

   /* Plan to the new joint space goal */
   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
   ROS_INFO_NAMED("tutorial", "Visualizing plan (joint space goal) %s", success ? "" : "FAILED");

   /* Visualize the plan in RVIZ */
   visual_tools.deleteAllMarkers();
   visual_tools.publishText(text_pose, "Joint Space Goal", rvt::WHITE, rvt::XLARGE);
   visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
   visual_tools.trigger();

   visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to move the robot to its initial configuration");
   move_group.execute(my_plan);


   ros::shutdown();
   return 0;
}
