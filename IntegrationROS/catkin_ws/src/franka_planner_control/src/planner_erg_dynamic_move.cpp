#include <ros/ros.h>

#include <chrono>
#include <ctime>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <franka_planner_control/MoveItTime.h>

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>

#include <add_rviz_obstacles.h>

#include <std_msgs/Int8.h>

/* Setup MoveIt planning_interface */
bool success; 
moveit::planning_interface::MoveGroupInterface::Plan my_plan_;
moveit::core::RobotStatePtr current_state_;
std::vector<double> joint_group_positions_;

/* in RVIZ objects are defined w.r.t. the robot, but we see them in the world frame (= table orientation) */
Eigen::Matrix3d elementary_zrotation_robot2world_; 
Eigen::Quaterniond quat_robot2world_;

/* target pose */
geometry_msgs::Pose target_pose_;
geometry_msgs::Pose xe_r_;

/* ROS time and durations */
ros::Time start_time_;
ros::Duration elapsed_time_;

/* chrono */
std::chrono::time_point<std::chrono::system_clock> start_planning_, end_planning_;
std::chrono::duration<double> moveittime_planning_;

/* ROS publishers */ 
ros::Publisher robot_trajectory_publisher_;
ros::Publisher moveittime_publisher_;
ros::Publisher planner_reference_publisher_;
ros::Publisher rviz_orientation_problem_publisher_;

/* ROS messages */  
moveit_msgs::RobotTrajectory robottraj_msg_;
franka_planner_control::MoveItTime moveittime_msg_;
geometry_msgs::Pose planner_reference_msg_;
std_msgs::Int8 rviz_orientation_problem_msg_;

void publishData(){
  robottraj_msg_ = my_plan_.trajectory_;
  robot_trajectory_publisher_.publish(robottraj_msg_);
  
  moveittime_planning_ = end_planning_ - start_planning_;
  moveittime_msg_.planning_time = moveittime_planning_.count();
  moveittime_msg_.time = (ros::Time::now() - start_time_).toSec();
  moveittime_publisher_.publish(moveittime_msg_);

  planner_reference_msg_ = xe_r_; 
  planner_reference_publisher_.publish(planner_reference_msg_);

  rviz_orientation_problem_publisher_.publish(rviz_orientation_problem_msg_);
}

int main(int argc, char** argv)
{ 
  ros::init(argc, argv, "planner_erg_static_move");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  /* iterations in reference part */
  int iter1 = 0;
  int iter2 = 0;
  int iter3 = 0;
  int iter4 = 0;
  int iter5 = 0;
  bool executing_plan = false;

  /* initialize ROS publisher */
  robot_trajectory_publisher_ = node_handle.advertise<moveit_msgs::RobotTrajectory>("/Panda/RobotTrajectory", 50); // topic name = /Panda/RobotTrajectory
  moveittime_publisher_ = node_handle.advertise<franka_planner_control::MoveItTime>("/Panda/MoveItTime", 1); // topic name = /Panda/MoveItTime
  planner_reference_publisher_ = node_handle.advertise<geometry_msgs::Pose>("/Panda/PlannerReference", 1); // topic name = /Panda/PlannerReference
  rviz_orientation_problem_publisher_ = node_handle.advertise<std_msgs::Int8>("Panda/RvizOrientationProblem",1); 

  /* Setup (same as move_group_interface_tutorial.cpp)
     ++++++++++++++++++++++++++++++++++++++++++++++++++ */ 
  static const std::string PLANNING_GROUP = "panda_arm";
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  const robot_state::JointModelGroup* joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  move_group.setStartState(*move_group.getCurrentState());
  move_group.setPlanningTime(0.2); 
  move_group.setMaxVelocityScalingFactor(0.5); //(0.75);
  move_group.setMaxAccelerationScalingFactor(0.5); //(0.75);
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
  elementary_zrotation_robot2world_ = Eigen::AngleAxisd(-130*M_PI/180, Eigen::Vector3d::UnitZ()); 
  quat_robot2world_ = Eigen::Quaterniond(elementary_zrotation_robot2world_);


  /* 1) Add obstacles to the environment
     +++++++++++++++++++++++++++++++++++ */

  /* add table */
  double table_dimension_x = 0.8; 
  double table_dimension_y = 1.5;
  double table_dimension_z = 0.05;
  Eigen::Matrix<double,3,1> table_position_wrt_world = {-0.2, 0.5, -0.03}; 
  Eigen::Matrix<double,3,1> table_position_wrt_robot = elementary_zrotation_robot2world_ * table_position_wrt_world;
  AddRvizObstacles rviz_obstacle_tool;

  rviz_obstacle_tool.addBoxCollisionObject("panda_link0","table", 
                          table_dimension_x, table_dimension_y, table_dimension_z,
                          table_position_wrt_robot, quat_robot2world_);

  ROS_INFO_NAMED("tutorial", "Included the table on which the Panda is mounted");
  planning_scene_interface.addCollisionObjects(rviz_obstacle_tool.collision_objects_);

  /* add wall */ 
  double wall_dimension_x = 0.9; 
  double wall_dimension_y = 0.02;
  double wall_dimension_z = 0.45;
  Eigen::Matrix<double,3,1> wall_position_wrt_world = {-0.2, 0.74, wall_dimension_z/2}; 
  Eigen::Matrix<double,3,1> wall_position_wrt_robot = elementary_zrotation_robot2world_ * wall_position_wrt_world;

  rviz_obstacle_tool.addBoxCollisionObject("panda_link0", "wall", 
                          wall_dimension_x, wall_dimension_y, wall_dimension_z,
                          wall_position_wrt_robot, quat_robot2world_);

  ROS_INFO_NAMED("tutorial", "Included the wall constraint");
  planning_scene_interface.addCollisionObjects(rviz_obstacle_tool.collision_objects_);

  /* add two cylinders */
  double cylinder1_height = 0.25; //0.21;
  double cylinder1_radius = 0.13; //0.10;
  Eigen::Matrix<double,3,1> cylinder1_position_wrt_world = {-0.12, 0.46 /*0.44*/, cylinder1_height/2}; 
  Eigen::Matrix<double,3,1> cylinder1_position_wrt_robot = elementary_zrotation_robot2world_ * cylinder1_position_wrt_world;
  rviz_obstacle_tool.addCylinderCollisionObject( "panda_link0","cylinder1", cylinder1_height, cylinder1_radius, 
                              cylinder1_position_wrt_robot, quat_robot2world_);

  double cylinder2_height = 0.32; //0.28;
  double cylinder2_radius = 0.13; //0.10;
  Eigen::Matrix<double,3,1> cylinder2_position_wrt_world = {-0.41, -0.05, cylinder2_height/2}; 
  Eigen::Matrix<double,3,1> cylinder2_position_wrt_robot = elementary_zrotation_robot2world_ * cylinder2_position_wrt_world;
  rviz_obstacle_tool.addCylinderCollisionObject( "panda_link0","cylinder2", cylinder2_height, cylinder2_radius, 
                              cylinder2_position_wrt_robot, quat_robot2world_);

  ROS_INFO_NAMED("tutorial", "Included two cylindrical obstacles");
  planning_scene_interface.addCollisionObjects(rviz_obstacle_tool.collision_objects_);

  xe_r_.position.x = 0.306977;  
  xe_r_.position.y = 0.0;
  xe_r_.position.z = 0.590409;
  xe_r_.orientation.x = 1.0;
  xe_r_.orientation.y = 0.0;
  xe_r_.orientation.z = 0.0;
  xe_r_.orientation.w = 0.0;
  visual_tools.publishAxis(xe_r_);
  visual_tools.trigger();

  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to start the planning ");
  start_time_ = ros::Time::now();
  
  while(ros::ok()){
    elapsed_time_ = ros::Time::now() - start_time_;

    /* target pose */
    if(elapsed_time_.toSec() <= 2.0){
      // stay where you are 
      xe_r_.position.x = 0.306977;  
      xe_r_.position.y = 0.0;
      xe_r_.position.z = 0.590409;
      xe_r_.orientation.x = 1.0;
      xe_r_.orientation.y = 0.0;
      xe_r_.orientation.z = 0.0;
      xe_r_.orientation.w = 0.0;

      rviz_orientation_problem_msg_.data = 0; // false 
    }
    else if(elapsed_time_.toSec() > 2.0 && elapsed_time_.toSec() <= 10.0){
      target_pose_.position.x = 0.6; 
      target_pose_.position.y = -0.34; 
      target_pose_.position.z = 0.25; 
      target_pose_.orientation.x = 0.7071068; 
      target_pose_.orientation.y = -0.7071068;  
      target_pose_.orientation.z = 0;
      target_pose_.orientation.w = 0;

      move_group.setPoseTarget(target_pose_);

      xe_r_ = target_pose_; 
      rviz_orientation_problem_msg_.data = 1; // true 
    }
    else if(elapsed_time_.toSec() > 10.0 && elapsed_time_.toSec() <= 18.0){
      target_pose_.position.x = 0.35;
      target_pose_.position.y = 0.05; 
      target_pose_.position.z = 0.25; 
      target_pose_.orientation.x = 1;
      target_pose_.orientation.y = 0; 
      target_pose_.orientation.z = 0; 
      target_pose_.orientation.w = 0; 

      move_group.setPoseTarget(target_pose_);

      xe_r_ = target_pose_; 
      rviz_orientation_problem_msg_.data = 1; // true 
    }
    else if(elapsed_time_.toSec() > 18.0 && elapsed_time_.toSec() <= 26.0){
      target_pose_.position.x = 0.22; 
      target_pose_.position.y = -0.44; 
      target_pose_.position.z = 0.25;
      target_pose_.orientation.x = 1;
      target_pose_.orientation.y = 0; 
      target_pose_.orientation.z = 0; 
      target_pose_.orientation.w = 0; 

      move_group.setPoseTarget(target_pose_);

      xe_r_ = target_pose_; 
      rviz_orientation_problem_msg_.data = 1; // true 
    }
    else if(elapsed_time_.toSec() > 26.0 && elapsed_time_.toSec() <= 34.0){
      target_pose_.position.x = 0.24; 
      target_pose_.position.y = 0.34; 
      target_pose_.position.z = 0.55; 
      target_pose_.orientation.x = 1;
      target_pose_.orientation.y = 0; 
      target_pose_.orientation.z = 0; 
      target_pose_.orientation.w = 0; 

      move_group.setPoseTarget(target_pose_);

      xe_r_ = target_pose_; 
      rviz_orientation_problem_msg_.data = 1; // true 
    }
    else{
      joint_group_positions_[0] = -1.13434e-05;    // radians
      joint_group_positions_[1] = -0.786148;       // radians
      joint_group_positions_[2] = -0.000365677;    // radians
      joint_group_positions_[3] = -2.35475;        // radians
      joint_group_positions_[4] = 0.000670376;     // radians
      joint_group_positions_[5] = 1.57193;         // radians
      joint_group_positions_[6] = 0.784775;        // radians
      
      move_group.setJointValueTarget(joint_group_positions_);

      target_pose_.position.x = 0.306977;  
      target_pose_.position.y = 0.0;
      target_pose_.position.z = 0.590409; 
      target_pose_.orientation.x = 1.0;
      target_pose_.orientation.y = 0.0; 
      target_pose_.orientation.z = 0.0; 
      target_pose_.orientation.w = 0.0; 

      xe_r_ = target_pose_;
      rviz_orientation_problem_msg_.data = 0; // false  
    }
    if(elapsed_time_.toSec() <= 2.0){
      planner_reference_msg_ = xe_r_; 
      planner_reference_publisher_.publish(planner_reference_msg_);
    }
    if(elapsed_time_.toSec() > 2.0){
      /* Get the current robot state */
      current_state_ = move_group.getCurrentState();
      current_state_->copyJointGroupPositions(joint_model_group, joint_group_positions_);
      move_group.setStartState(*move_group.getCurrentState());

      /* plan */
      start_planning_ = std::chrono::system_clock::now();  // chrono
      success = (move_group.plan(my_plan_) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
      end_planning_ = std::chrono::system_clock::now();  // chrono
      
      /* visualize plan */
      // ROS_INFO_NAMED("tutorial", "Visualizing plan (pose goal) %s", success ? "" : "FAILED");
      visual_tools.deleteAllMarkers();
      visual_tools.publishAxis(target_pose_);
      // visual_tools.publishTrajectoryLine(my_plan_.trajectory_, joint_model_group);
      visual_tools.trigger();

      /* publish data */
      publishData();
    }
  }

  ros::shutdown();
  return 0;
}
