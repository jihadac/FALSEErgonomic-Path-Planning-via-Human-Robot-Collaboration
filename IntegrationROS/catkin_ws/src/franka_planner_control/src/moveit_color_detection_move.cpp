 
#include <ros/ros.h>

#include <zed_interfaces/Object.h>
#include <zed_interfaces/ObjectsStamped.h>
#include <zed_interfaces/Skeleton3D.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_listener.h>

#include <add_rviz_obstacles.h>



geometry_msgs::Pose pose;
geometry_msgs::TransformStamped zed2panda;
std::string source_frameid = "zed2_left_camera_frame";
std::string target_frameid = "panda_link0";
std::vector<moveit_msgs::CollisionObject> collision_objects;

void getTransformation(tf::TransformListener& tf){
    try{
        tf::StampedTransform echo_transform;
        tf.lookupTransform(target_frameid, source_frameid, ros::Time(), echo_transform);
        tf::Vector3 v = echo_transform.getOrigin();
        zed2panda.transform.translation.x = v.getX();
        zed2panda.transform.translation.y = v.getY();
        zed2panda.transform.translation.z = v.getZ();
        tf::Quaternion q = echo_transform.getRotation();
        zed2panda.transform.rotation.x = q.getX();
        zed2panda.transform.rotation.y = q.getY();
        zed2panda.transform.rotation.z = q.getZ();
        zed2panda.transform.rotation.w = q.getW();
    }
    catch (tf::TransformException &ex) {
        ROS_WARN("%s",ex.what());
        //ROS_INFO_STREAM(zed2panda.transform.rotation.x);
        //ros::Duration(1.0).sleep();
    }
}

void colorDetectionCallback(const visualization_msgs::Marker::ConstPtr& msg){
    pose = msg -> pose;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "moveit_color_detection_move");
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


/* add table */
    Eigen::Matrix3d elementary_zrotation_robot2world_; // define rotation matrix from robot to world frame
    Eigen::Quaterniond quat_robot2world_;
    elementary_zrotation_robot2world_ = Eigen::AngleAxisd(-140*M_PI/180, Eigen::Vector3d::UnitZ()); 
  quat_robot2world_ = Eigen::Quaterniond(elementary_zrotation_robot2world_);
  Eigen::Matrix<double,3,1> table_dimensions = {1.0, 2.0, 0.05};
  double table_dimension_x = 1.0; 
  double table_dimension_y = 2.0;
  double table_dimension_z = 0.05;
  Eigen::Matrix<double,3,1> table_position_wrt_world = {-0.2, 0.5, -0.03}; 
  Eigen::Matrix<double,3,1> table_position_wrt_robot = elementary_zrotation_robot2world_ * table_position_wrt_world;
  AddRvizObstacles rviz_obstacle_tool;

    rviz_obstacle_tool.addBoxCollisionObject("panda_link0","table", 
                          table_dimension_x, table_dimension_y, table_dimension_z,
                          table_position_wrt_robot, quat_robot2world_);

     planning_scene_interface.addCollisionObjects(rviz_obstacle_tool.collision_objects_);

  /* color detection topic subscriber */
    ros::Subscriber subColorDetection;
    subColorDetection  = node_handle.subscribe("detected_color_marker", 1, colorDetectionCallback);
    tf::TransformListener tf;
    tf.waitForTransform(source_frameid, target_frameid, ros::Time(), ros::Duration(1.0));

    while(ros::ok()){
        visual_tools.prompt(". . .");
        getTransformation(tf);
        geometry_msgs::Pose obj_pose_in_robot_frame;
        tf2::doTransform(pose, obj_pose_in_robot_frame, zed2panda);
        
        obj_pose_in_robot_frame.position.z += 0.2;
        obj_pose_in_robot_frame.orientation.x =1;
        obj_pose_in_robot_frame.orientation.y =0;
        obj_pose_in_robot_frame.orientation.z =0;
        obj_pose_in_robot_frame.orientation.w =0;
        move_group.setPoseTarget(obj_pose_in_robot_frame);

        visual_tools.deleteAllMarkers();
        visual_tools.publishAxisLabeled(obj_pose_in_robot_frame, "target pose");
        success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
        visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
        visual_tools.trigger();

        visual_tools.prompt("execute");
        move_group.execute(my_plan);
        current_state = move_group.getCurrentState();
        current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
        move_group.setStartState(*move_group.getCurrentState());
        visual_tools.trigger();
 

    }
}