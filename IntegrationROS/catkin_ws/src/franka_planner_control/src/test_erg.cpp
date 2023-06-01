// Copyright (c) 2017 Franka Emika GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <franka_planner_control/test_erg.h>

#include <cmath>
#include <memory>

#include <controller_interface/controller_base.h>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>

#include <franka/robot_state.h>

#include "pseudo_inversion.h"

#include <ros/package.h>
#define PI 3.14159265

namespace franka_planner_control {

void TestErg::skeletonTrackingCallback(const zed_interfaces::ObjectsStamped::ConstPtr& msg){
  rviz_visualization.addAllSkeletons(msg -> objects);
}

bool TestErg::init(hardware_interface::RobotHW* robot_hw,
                                           ros::NodeHandle& node_handle) {
  std::string arm_id;
  if (!node_handle.getParam("arm_id", arm_id)) {
    ROS_ERROR("TestErg: Could not read parameter arm_id");
    return false;
  }

  std::vector<std::string> joint_names;
  if (!node_handle.getParam("joint_names", joint_names) || joint_names.size() != 7) {
    ROS_ERROR(
        "TestErg: Invalid or no joint_names parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("Kp", Kp_) || Kp_.size() != 7) {
    ROS_ERROR(
        "TestErg:  Invalid or no k_gain parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("Kd", Kd_) || Kd_.size() != 7) {
    ROS_ERROR(
        "TestErg:  Invalid or no d_gain parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("joint_friction_1", joint_friction_1_) || joint_friction_1_.size() != 7) {
    ROS_ERROR(
        "PandaJointEffortControlPredictions:  Invalid or no joint_friction_1 parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("joint_friction_2", joint_friction_2_) || joint_friction_2_.size() != 7) {
    ROS_ERROR(
        "PandaJointEffortControlPredictions:  Invalid or no joint_friction_2 parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("joint_friction_3", joint_friction_3_) || joint_friction_3_.size() != 7) {
    ROS_ERROR(
        "PandaJointEffortControlPredictions:  Invalid or no joint_friction_3 parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("pred_samples", pred_samples_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no pred_samples parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("pred_samplingtime", pred_samplingtime_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no pred_samplingtime parameter provided, aborting "
        "controller init!");
    return false;
  }
  if (!node_handle.getParam("pred_interval", pred_interval_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no pred_interval parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("tau_limit", tau_limit_) || tau_limit_.size() != 7) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no tau_limit_ parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_tau", kappa_tau_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_tau parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_tau", delta_tau_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_tau parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("dotq_limit", dotq_limit_) || dotq_limit_.size() != 7) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no dotq_limit_ parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_dotq", kappa_dotq_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_dotq parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_dotq", delta_dotq_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_dotq parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("q_lowerlimit", q_lowerlimit_) || q_lowerlimit_.size() != 7) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no q_lowerlimit parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("q_upperlimit", q_upperlimit_) || q_upperlimit_.size() != 7) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no q_upperlimit parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_q", kappa_q_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_q parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_q", delta_q_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_q parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("eta", eta_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no eta parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("zeta_q", zeta_q_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no zeta_q parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("dotp_EE_limit", dotp_EE_limit_) || dotp_EE_limit_.size() != 2) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no dotp_EE_limit parameters provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_dotp_EE", kappa_dotp_EE_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_dotp_EE parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_dotp_EE", delta_dotp_EE_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_dotp_EE parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("energy_limit", energy_limit_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no energy_limit parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_energy", kappa_energy_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_energy parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_wall", kappa_wall_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_wall parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_wall", delta_wall_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_wall parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("zeta_wall", zeta_wall_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no zeta_wall parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_sphere", kappa_sphere_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_sphere parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_sphere", delta_sphere_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_sphere parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("zeta_sphere", zeta_sphere_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no zeta_sphere parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("kappa_cylinder", kappa_cylinder_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no kappa_cylinder parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("delta_cylinder", delta_cylinder_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no delta_cylinder parameter provided, aborting "
        "controller init!");
    return false;
  }

  if (!node_handle.getParam("zeta_cylinder", zeta_cylinder_)) {
    ROS_ERROR(
        "ErgStaticMove:  Invalid or no zeta_cylinder parameter provided, aborting "
        "controller init!");
    return false;
  }

  double publish_rate(100.0);
  if (!node_handle.getParam("publish_rate", publish_rate)) {
    ROS_INFO_STREAM("TestErg: publish_rate not found. Defaulting to "
                    << publish_rate);
  }

  auto* model_interface = robot_hw->get<franka_hw::FrankaModelInterface>();
  if (model_interface == nullptr) {
    ROS_ERROR_STREAM(
        "TestErg: Error getting model interface from hardware");
    return false;
  }
  try {
    model_handle_ = std::make_unique<franka_hw::FrankaModelHandle>(
        model_interface->getHandle(arm_id + "_model"));
  } catch (hardware_interface::HardwareInterfaceException& ex) {
    ROS_ERROR_STREAM(
        "TestErg: Exception getting model handle from interface: "
        << ex.what());
    return false;
  } 

	auto* effort_joint_interface = robot_hw->get<hardware_interface::EffortJointInterface>();
  if (effort_joint_interface == nullptr) {
    ROS_ERROR_STREAM(
        "TestErg: Error getting effort joint interface from hardware");
    return false;
  }
  for (size_t i = 0; i < 7; ++i) {
    try {
      joint_handles_.push_back(effort_joint_interface->getHandle(joint_names[i]));
    } catch (const hardware_interface::HardwareInterfaceException& ex) {
      ROS_ERROR_STREAM(
          "TestErg: Exception getting joint handles: " << ex.what());
      return false;
    }
  }

  auto* state_interface = robot_hw->get<franka_hw::FrankaStateInterface>();
  if (state_interface == nullptr) {
    ROS_ERROR("TestErg: Could not get state interface from hardware");
    return false;
  }
  try {
    state_handle_ = std::make_unique<franka_hw::FrankaStateHandle>(
      state_interface->getHandle(arm_id + "_robot"));
  } catch (const hardware_interface::HardwareInterfaceException& e) {
    ROS_ERROR_STREAM(
        "TestErg: Exception getting state handle: " << e.what());
    return false;
  }

  /* ROS data publishers */
  distancetoconstraints_publisher_ = node_handle.advertise<franka_planner_control::DistanceToConstraints>("/Panda/distance_to_constraints", 50);
  trajpredictions_publisher_ = node_handle.advertise<franka_planner_control::TrajectoryPredictions>("/Panda/trajectory_predictions",1000);
  DSM_publisher_ = node_handle.advertise<franka_planner_control::DSM>("/Panda/DSM", 50);
  computationaltime_publisher_ = node_handle.advertise<franka_planner_control::ComputationalTime>("/Panda/computation_time",50);

  /* RViz visualization */
  rviz_visualization.changeRobotFrame("panda_link0");
  marker_array_publisher_ = node_handle.advertise<visualization_msgs::MarkerArray>("visualization_markers",10);  
  skeleton_objects_sub_ = node_handle.subscribe("/zed2/zed_node/obj_det/objects", 10, &TestErg::skeletonTrackingCallback, this);
  rviz_visualization.changeSkeletonsMarkersColor(0.9, 0.65, 0.5, 0.7);
  number_of_walls_ = 0; // try with 4
  number_of_spheres_ = 0; // try with 1
  number_of_cylinders_ = 2; // try with 2

  /* define wall constraints  - normals should be unit vectors */
  {
    double wall1_rotationangleaboutz = (40+270)*PI/180;
    Eigen::Matrix3d elementary_zrotation_wall1;
    elementary_zrotation_wall1 = Eigen::AngleAxisd(wall1_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
    Eigen::Matrix<double, 3, 1> wall1_normal =elementary_zrotation_wall1.col(0);
    Eigen::Quaterniond quat_wall1;
    quat_wall1 = Eigen::Quaterniond(elementary_zrotation_wall1);
    wall_normals_.block(0,0,3,1) = wall1_normal; 
    wall_quaternions_.block(0,0,4,1) = quat_wall1.coeffs();
    wall_distances_(0) = 0.55;
    wall_heights_(0) = 0.90; //0.45;
    wall_lengths_(0) = 0.90;
    wall_widths_(0) = 0.01; //0.02;

    double wall2_rotationangleaboutz = (40+90)*PI/180;
    Eigen::Matrix3d elementary_zrotation_wall2;
    elementary_zrotation_wall2 = Eigen::AngleAxisd(wall2_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
    Eigen::Matrix<double, 3, 1> wall2_normal =elementary_zrotation_wall2.col(0);
    Eigen::Quaterniond quat_wall2;
    quat_wall2 = Eigen::Quaterniond(elementary_zrotation_wall2);
    wall_normals_.block(0,1,3,1) = wall2_normal; 
    wall_quaternions_.block(0,1,4,1) = quat_wall2.coeffs();
    wall_distances_(1) = 0.5;
    wall_heights_(1) = 0.45;
    wall_lengths_(1) = 0.90;
    wall_widths_(1) = 0.02;

    double wall3_rotationangleaboutz = (40+180)*PI/180;
    Eigen::Matrix3d elementary_zrotation_wall3;
    elementary_zrotation_wall3 = Eigen::AngleAxisd(wall3_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
    Eigen::Matrix<double, 3, 1> wall3_normal =elementary_zrotation_wall3.col(0);
    Eigen::Quaterniond quat_wall3;
    quat_wall3 = Eigen::Quaterniond(elementary_zrotation_wall3);
    wall_normals_.block(0,2,3,1) = wall3_normal; 
    wall_quaternions_.block(0,2,4,1) = quat_wall3.coeffs();
    wall_distances_(2) = 0.5;
    wall_heights_(2) = 0.45;
    wall_lengths_(2) = 0.90;
    wall_widths_(2) = 0.02;

    double wall4_rotationangleaboutz =  40*PI/180;
    Eigen::Matrix3d elementary_zrotation_wall4;
    elementary_zrotation_wall4 = Eigen::AngleAxisd(wall4_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
    Eigen::Matrix<double, 3, 1> wall4_normal =elementary_zrotation_wall4.col(0);
    Eigen::Quaterniond quat_wall4;
    quat_wall4 = Eigen::Quaterniond(elementary_zrotation_wall4);
    wall_normals_.block(0,3,3,1) = wall4_normal; 
    wall_quaternions_.block(0,3,4,1) = quat_wall4.coeffs();
    wall_distances_(3) = 0.5;
    wall_heights_(3) = 0.45;
    wall_lengths_(3) = 0.90;
    wall_widths_(3) = 0.02;

    rviz_visualization.changeMarkersColor(0, 1, 0, 0.7);
    for(int i=0; i <number_of_walls_; i++){
      rviz_visualization.addOneWall( wall_normals_.block(0,i,3,1), 
                                wall_distances_.block(0,i,1,1),
                                wall_heights_.block(0,i,1,1),
                                wall_lengths_.block(0,i,1,1),
                                wall_widths_.block(0,i,1,1),
                                wall_quaternions_.block(0,i,4,1),
                                i, 
                                "walls");
    }     
  }

  /* define spherical obstacles */
  {
    double obst_sphere1_radius = 0.10;
    Eigen::Matrix<double, 3, 1> obst_sphere1_center = {0.3, 0.3, 0.65};
    sphere_centers_.block(0,0,3,1) = obst_sphere1_center;
    sphere_radii_(0) = obst_sphere1_radius;

    double obst_sphere2_radius = 0.15;
    Eigen::Matrix<double, 3, 1> obst_sphere2_center = {-0.3, -0.3, 0.65};
    sphere_centers_.block(0,1,3,1) = obst_sphere2_center;
    sphere_radii_(1) = obst_sphere2_radius;

    rviz_visualization.changeMarkersColor(1, 0, 0, 0.7);
    for(int i=0; i <number_of_spheres_; i++){
      rviz_visualization.addOneSphere(sphere_centers_.block(0,i,3,1), 
                                      sphere_radii_.block(0,i,1,1),
                                      i, 
                                      "spheres");
    }     
  }

  /* define cylindrical obstacles */
  {
    double obst_cylinder1_radius = 0.10;
    Eigen::Quaterniond obst_cylinder1_quaternion; 
    obst_cylinder1_quaternion = {1.0, 0.0, 0.0, 0.0}; 
    Eigen::Matrix<double, 3, 1> obst_cylinder1_startpoint = {0.5, -0.3, 0.0}; // defined in robot base frame
    Eigen::Matrix<double, 3, 1> obst_cylinder1_endpoint = {0.5, -0.3, 0.35}; // defined in robot base frame
    cylinder_radii_[0] = obst_cylinder1_radius;
    cylinder_quaternions_.block(0,0,4,1) = obst_cylinder1_quaternion.coeffs(); // Quaternion coefficients: x, y, z, w
    cylinder_startendpoints_.block(0,0,3,1) = obst_cylinder1_startpoint; 
    cylinder_startendpoints_.block(3,0,3,1) = obst_cylinder1_endpoint; 
    cylinder_centers_.block(0,0,3,1) = (obst_cylinder1_startpoint+obst_cylinder1_endpoint)/2;
    cylinder_heights_[0] = (obst_cylinder1_startpoint-obst_cylinder1_endpoint).norm();
  
    double obst_cylinder2_radius = 0.10;
    Eigen::Quaterniond obst_cylinder2_quaternion;
    obst_cylinder2_quaternion = {1.0, 0.0, 0.0, 0.0}; 
    Eigen::Matrix<double, 3, 1> obst_cylinder2_startpoint = {0.0, 0.6, 0.0}; // defined in robot base frame
    Eigen::Matrix<double, 3, 1> obst_cylinder2_endpoint = {0.0, 0.6, 0.8}; // defined in robot base frame
    cylinder_radii_[1] = obst_cylinder2_radius;
    cylinder_quaternions_.block(0,1,4,1) = obst_cylinder2_quaternion.coeffs(); // Quaternion coefficients: x, y, z, w
    cylinder_startendpoints_.block(0,1,3,1) = obst_cylinder2_startpoint; 
    cylinder_startendpoints_.block(3,1,3,1) = obst_cylinder2_endpoint; 
    cylinder_centers_.block(0,1,3,1) = (obst_cylinder2_startpoint+obst_cylinder2_endpoint)/2;
    cylinder_heights_[1] = (obst_cylinder2_startpoint-obst_cylinder2_endpoint).norm();
  
    rviz_visualization.changeMarkersColor(0, 0, 1, 0.7);
    for(int i=0; i <number_of_cylinders_; i++){
      rviz_visualization.addOneCylinder( cylinder_startendpoints_.block(0,i,6,1), 
                                    cylinder_radii_.block(0,i,1,1),
                                    i, 
                                    "cylinders");
    }     
  }

  rviz_visualization.updateSkeletonsPoses(true);

  return true;
}

void TestErg::starting(const ros::Time& /*time*/ ) {
  q_init_ = state_handle_->getRobotState().q;
  q_v_ = q_init_; 
  q_r_ = q_init_;

  elapsed_time_ = ros::Duration(0.0);
  elapsed_time_trajpred_ = ros::Duration(0.0);  
}

void TestErg::update(const ros::Time& /*time*/,
                                             const ros::Duration& period) {
  elapsed_time_ += period;
  elapsed_time_trajpred_ += period;

  franka::RobotState robot_state = state_handle_->getRobotState();
  mass_ = model_handle_->getMass();
  gravity_ = model_handle_->getGravity();
  inertialtorque_ = {0, 0, 0, 0, 0, 0, 0};

  /* ERG RATE + RVIZ RATE = every 10ms 
  +++++++++++++++++++++++++++++++++++++  */

  /* start ERG loop very first time 
  ----------------------------------  */
  if(elapsed_time_.toSec()== 0.0){
    computationaltime_msg_.time = elapsed_time_.toSec();
    
    /* update references in ERG class */
    setReferences(q_r_,q_v_); 

    /* get skeleton joint positions data to use in ERG */
    skeleton_joint_positions_ = rviz_visualization.getJointsPositions(); 
    if(skeleton_joint_positions_.size() >0){
      addSkeletonsToObstaclesInERG();
    }

    /* start NF and DSM threads to compute new applied reference q_v_ */
    threadNF_ = std::thread(&TestErg::navigationField, this);
    threadDSM_ = std::thread(&TestErg::trajectoryBasedDSM, this);

    /* visualize the obstacles in RViz */
    rviz_visualization.publishMarkers(marker_array_publisher_);
  }

  /* after 10ms, receive ERG data to compute new applied reference 
  ---------------------------------------------------------------- */
  if(elapsed_time_trajpred_.toSec()>= 0.01 /*pred_interval_*/){
    /* receive rho_ and DSM_ */
    threadNF_.join();
    threadDSM_.join();

    /* start ERG (i.e. compute new q_v_) chrono */ 
    start_ERG_ = std::chrono::system_clock::now(); 

    /* safety check for when the updated applied reference would collide with the table 
    if it won't collide: update q_v_ 
    if is will collide: keep q_v_ same as in previous iteration */
    for(int i=0; i<7; i++){
      q_v_check_[i] = q_v_[i] + DSM_ * rho_[i] * period.toSec();
    } 
    double zpos_qv_endeffector = model_handle_->getPose(franka::Frame::kEndEffector, q_v_check_, state_handle_->getRobotState().F_T_EE , state_handle_->getRobotState().EE_T_K)[14]; // position of end-effector in z-direction
    if (zpos_qv_endeffector > 0.15){ // if zpos > 0.10m
      for(int i=0; i<7; i++){
        q_v_[i] = q_v_check_[i];
      }
    }
    else {
      ROS_WARN_STREAM("zpos_qv_endeffector: " << zpos_qv_endeffector);
      for(int i=0; i<7; i++){
        q_v_[i] = q_v_[i];
      }
    }

    /* end the ERG chrono and compute the ERG computational time */
    end_ERG_ = std::chrono::system_clock::now(); 
    computationaltime_ERG_ = end_ERG_ - start_ERG_;
    computationaltime_msg_.ERG = computationaltime_ERG_.count();

    /* publish the computationaltime message */
    computationaltime_publisher_.publish(computationaltime_msg_);


    /* start new ERG loop 
    ---------------------- */
    elapsed_time_trajpred_ = ros::Duration(0.0);
    computationaltime_msg_.time = elapsed_time_.toSec();
    
    /* update references in ERG class */
    setReferences(q_r_,q_v_); 

    /* get skeleton joint positions data to use in ERG */
    skeleton_joint_positions_ = rviz_visualization.getJointsPositions(); 
    if(skeleton_joint_positions_.size() >0){
      addSkeletonsToObstaclesInERG();
    }

    /* start NF and DSM threads to compute new applied reference q_v_ */
    threadNF_ = std::thread(&TestErg::navigationField, this);
    threadDSM_ = std::thread(&TestErg::trajectoryBasedDSM, this);

    /* visualize the obstacles in RViz */
    rviz_visualization.publishMarkers(marker_array_publisher_); 
  }

  
  /* CLOSED LOOP RATE: every 1ms 
  ++++++++++++++++++++++++++++++++ */
  /* STEP REFERENCES */
  if (elapsed_time_.toSec() <= 2.0) {
    q_r_ = q_init_;
  }
  else if(elapsed_time_.toSec() > 2.0 && elapsed_time_.toSec() <= 6.0){
    q_r_ = {-0.178625,0.390126,-0.383354,-1.55827,0.200258,2.00751,0.812685};
  }
  else if(elapsed_time_.toSec() > 6.0){
    q_r_ = q_init_;
  }


  /* PD + g control */
  for(size_t i=0; i<7; ++i) {
    tau_commanded_[i] = Kp_[i]*(q_v_[i] - robot_state.q[i]) - Kd_[i]*robot_state.dq[i];
    // tau_commanded_[i] = Kp_[i]*(q_r_[i] - robot_state.q[i]) - Kd_[i]*robot_state.dq[i];
    tau_desired_g_[i] = tau_commanded_[i] + gravity_[i];
    for(size_t j=0; j<7; ++j) {
      inertialtorque_[i] += mass_[i+7*j]*robot_state.ddq_d[i];
    }
    friction_[i] = joint_friction_1_[i]/(1+exp(-joint_friction_2_[i]*(robot_state.dq[i]+joint_friction_3_[i])))
                - joint_friction_1_[i]/(1+exp(-joint_friction_2_[i]*joint_friction_3_[i]));
    tau_desired_full_[i] = tau_commanded_[i] + gravity_[i] + friction_[i] + inertialtorque_[i];
    joint_handles_[i].setCommand(tau_commanded_[i]); // gravity already included
  }
	jointstates_publisher_.publish(jointstates_msg_);
}


}  // namespace franka_planner_control

PLUGINLIB_EXPORT_CLASS(franka_planner_control::TestErg,
                       controller_interface::ControllerBase)