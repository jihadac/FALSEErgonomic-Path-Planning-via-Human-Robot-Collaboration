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

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>

#include <skeleton_tracker.h>
#include "franka_grasp.cpp"
#include <add_rviz_obstacles.h>

Eigen::Matrix3d elementary_zrotation_robot2world_; // define rotation matrix from robot to world frame
Eigen::Quaterniond quat_robot2world_;
std::vector<moveit_msgs::CollisionObject> collision_objects;

void skeletonTrackingCallback(const zed_interfaces::ObjectsStamped::ConstPtr& msg, SkeletonTracker *skeleton_tracker, moveit::planning_interface::PlanningSceneInterface* planning_scene_interface) {
   collision_objects.clear();
   std::vector<std::string> last_collision_object_ids = skeleton_tracker -> collision_object_ids;
   skeleton_tracker -> trackAllSkeletons(msg -> objects, collision_objects);
   planning_scene_interface -> addCollisionObjects(collision_objects);
   planning_scene_interface -> removeCollisionObjects(last_collision_object_ids);
   
}


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

  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to add all obstacles");
  AddRvizObstacles rviz_obstacle_tool;
    elementary_zrotation_robot2world_ = Eigen::AngleAxisd(-140*M_PI/180, Eigen::Vector3d::UnitZ()); 
  quat_robot2world_ = Eigen::Quaterniond(elementary_zrotation_robot2world_);
   /* add two cubes */
   // Eigen::Matrix<double,3,1> cube1_position_wrt_robot = {0.6, -0.3, 0.025}; 
   // rviz_obstacle_tool.addBoxCollisionObject( "panda_link0","cube1", 
   //                        0.05, 0.05, 0.05,
   //                        cube1_position_wrt_robot, quat_robot2world_);

   // Eigen::Matrix<double,3,1> cube2_position_wrt_robot = {0.4, 0., 0.025}; 
   // rviz_obstacle_tool.addBoxCollisionObject( "panda_link0","cube2", 
   //                        0.05, 0.05, 0.05,
   //                        cube2_position_wrt_robot, quat_robot2world_);

  planning_scene_interface.addCollisionObjects(rviz_obstacle_tool.collision_objects_);
  visual_tools.publishText(text_pose, "Included all obstacles to the environment", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();



   /* Start skeleton tracking */
   SkeletonTracker skeleton_tracker("zed2_left_camera_frame", "panda_link0", true);
   // subscriber
   ros::Subscriber subObjList;
   boost::function<void (const zed_interfaces::ObjectsStamped::ConstPtr&)> f = boost::bind(skeletonTrackingCallback, _1, &skeleton_tracker, &planning_scene_interface);
   subObjList = node_handle.subscribe("/zed2/zed_node/obj_det/objects", 1, f);

   //visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to zzzzzzzzzz");

   std::cout << "\
0 - Print commands\n\
i - Set person id\n\
s - Set right wrist pose as target pose for the robot\n\
p - Plan to the set pose\n\
e - execute the plan\n\
g - grasp object\n\
r - release object\n\
q - quit\n";
   std::string command;
   geometry_msgs::Pose target_pose;
   moveit::planning_interface::MoveGroupInterface::Plan plan;

   while(ros::ok){
      std::cout << "command: ";
      std::cin >> command;

      if(command == "0"){
         std::cout << "\
0 - Print commands\n\
i - Set person id\n\
s - Set right wrist pose as target pose for the robot\n\
p - Plan to the set pose\n\
e - execute the plan\n\
g - grasp object\n\
r - release object\n\
q - quit\n";
      }

      if(command == "i"){
         std::string tracked_id;
         std::cout << "id: ";
         std::cin >> tracked_id;
         skeleton_tracker.setTrackedId(tracked_id);
      }

      if(command == "s"){
         target_pose = skeleton_tracker.getJointPosition(4);
         std::cout << target_pose;
         move_group.setPoseTarget(target_pose);
         visual_tools.deleteAllMarkers();
         visual_tools.publishAxisLabeled(target_pose, "target pose");
         visual_tools.trigger();
      }
      if(command == "p"){
         visual_tools.deleteAllMarkers();
         visual_tools.publishAxisLabeled(target_pose, "target pose");
         success = (move_group.plan(plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
         visual_tools.publishTrajectoryLine(plan.trajectory_, joint_model_group);
         visual_tools.trigger();
      }
      if(command == "e"){
         move_group.execute(plan);
         current_state = move_group.getCurrentState();
         current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
         move_group.setStartState(*move_group.getCurrentState());
         visual_tools.trigger();
      }

      if(command == "g"){
         target_pose.position.z = 0.15;
         move_group.setPoseTarget(target_pose);
         move_group.move();

         if (frankaGraspCube() == -1){
            ROS_ERROR("cannot grasp cube");
         }
      }
      if(command == "r"){
         frankaRelease();
      }

      if(command == "q"){
         break;
      }

      if(command == "o"){
         std::string orientation;
         std::cout << "change orientation: ";
         std::cin >> orientation;
         if (orientation == "1"){
            target_pose.orientation.x = 0.7071068; 
            target_pose.orientation.y = -0.7071068;  
            target_pose.orientation.z = 0;
            target_pose.orientation.w = 0;
            move_group.setPoseTarget(target_pose);
         }
         else{
            target_pose.orientation.x = 1; 
            target_pose.orientation.y = 0;  
            target_pose.orientation.z = 0;
            target_pose.orientation.w = 0;
            move_group.setPoseTarget(target_pose);
         }


      }
      

   }

   ros::shutdown();
   return 0;
}
