// Copyright (c) 2017 Franka Emika GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#pragma once

#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/TransformStamped.h>

#include <franka_planner_control/explicit_reference_governor.h>

namespace franka_planner_control {

class ErgStaticMoveController : public franka_planner_control::ExplicitReferenceGovernor{
 public:
  bool init(hardware_interface::RobotHW* robot_hw, ros::NodeHandle& node_handle) override;
  void starting(const ros::Time& ) override;
  void update(const ros::Time& , const ros::Duration& period) override;

  /* receive skeleton information from ZED 2 camera */
  ros::Subscriber skeleton_objects_sub_;
  void skeletonTrackingCallback(const zed_interfaces::ObjectsStamped::ConstPtr& msg);
  
  /* receive robot trajectory from planner node */
  ros::Subscriber robot_trajectory_sub_;
  void robotTrajectoryCallback(const moveit_msgs::RobotTrajectory& msg);

  /* receive robot reference pose from planner node */
  ros::Subscriber planner_reference_sub_;
  void plannerReferenceCallback(const geometry_msgs::Pose& msg); 

 private:
  /* threads */
  std::thread threadNF_;
  std::thread threadDSM_;
  std::thread threadVisualizationRviz_;

  /* robot end-effector pose : reference, applied reference, current */ 
  geometry_msgs::Pose xe_r_; 
  geometry_msgs::Pose xe_v_; 
  geometry_msgs::Pose xe_; 

  /* joint states */
  std::array<double, 7> q_init_;
  std::array<double,7> q_r_;
  std::array<double,7> q_v_;
  std::array<double,7> q_v_check_;  

  /* joint commands */
  std::array<double,7> tau_commanded_;
  std::array<double,7> tau_desired_g_;
  std::array<double,7> tau_desired_full_;

  /* robot dynamic parameters */
  std::array<double, 49> mass_;
  std::array<double, 7> gravity_; 
  std::array<double, 7> friction_;
  std::array<double, 7> inertialtorque_;

};

}  // namespace franka_planner_control
