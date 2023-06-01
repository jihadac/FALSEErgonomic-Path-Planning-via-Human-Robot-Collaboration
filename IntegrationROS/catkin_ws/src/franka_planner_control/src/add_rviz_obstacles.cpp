/*#include <ros/ros.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>


std::vector<moveit_msgs::CollisionObject> collision_objects_;

moveit_msgs::CollisionObject box_;
shape_msgs::SolidPrimitive box_primitive_;
geometry_msgs::Pose box_pose_;

moveit_msgs::CollisionObject cylinder_;
shape_msgs::SolidPrimitive cylinder_primitive_;
geometry_msgs::Pose cylinder_pose_;

moveit_msgs::CollisionObject sphere_;
shape_msgs::SolidPrimitive sphere_primitive_;
geometry_msgs::Pose sphere_pose_;

void addBoxCollisionObject( const std::string& frame_id, const std::string& id,
                            const double& dimension_x, const double& dimension_y, const double& dimension_z,
                            const Eigen::Matrix<double,3,1>& position,
                            const Eigen::Quaterniond& orientation)
{
  box_.header.frame_id = frame_id;
  box_.id = id;

  box_primitive_.type = box_primitive_.BOX;
  box_primitive_.dimensions.resize(3);
  box_primitive_.dimensions[0] = dimension_x;
  box_primitive_.dimensions[1] = dimension_y;
  box_primitive_.dimensions[2] = dimension_z;

  box_pose_.position.x = position[0]; 
  box_pose_.position.y = position[1]; 
  box_pose_.position.z = position[2]; 
  box_pose_.orientation.x = orientation.coeffs()[0]; 
  box_pose_.orientation.y = orientation.coeffs()[1];  
  box_pose_.orientation.z = orientation.coeffs()[2];  
  box_pose_.orientation.w = orientation.coeffs()[3]; 

  box_.primitives.push_back(box_primitive_);
  box_.primitive_poses.push_back(box_pose_);
  box_.operation = box_.ADD;

  collision_objects_.push_back(box_);
}

void addCylinderCollisionObject( const std::string& frame_id, const std::string& id,
                                 const double& height, const double& radius, 
                                 const Eigen::Matrix<double,3,1>& position,
                                 const Eigen::Quaterniond& orientation)
{
  cylinder_.header.frame_id = frame_id;
  cylinder_.id = id;

  cylinder_primitive_.type = cylinder_primitive_.CYLINDER;
  cylinder_primitive_.dimensions.resize(2);
  cylinder_primitive_.dimensions[0] = height;
  cylinder_primitive_.dimensions[1] = radius;

  cylinder_pose_.position.x = position[0]; 
  cylinder_pose_.position.y = position[1]; 
  cylinder_pose_.position.z = position[2];
  cylinder_pose_.orientation.x = orientation.coeffs()[0]; 
  cylinder_pose_.orientation.y = orientation.coeffs()[1];  
  cylinder_pose_.orientation.z = orientation.coeffs()[2];  
  cylinder_pose_.orientation.w = orientation.coeffs()[3]; 

  cylinder_.primitives.push_back(cylinder_primitive_);
  cylinder_.primitive_poses.push_back(cylinder_pose_);
  cylinder_.operation = cylinder_.ADD;

  collision_objects_.push_back(cylinder_);
}

void addSphereCollisionObject(const std::string& frame_id, const std::string& id,
                              const double& radius, 
                              const Eigen::Matrix<double,3,1>& position)
{                               
  sphere_.header.frame_id = frame_id;
  sphere_.id = id;

  sphere_primitive_.type = sphere_primitive_.SPHERE;
  sphere_primitive_.dimensions.resize(1);
  sphere_primitive_.dimensions[0] = radius;

  sphere_pose_.position.x = position[0]; 
  sphere_pose_.position.y = position[1]; 
  sphere_pose_.position.z = position[2];
  sphere_pose_.orientation.x = 1;
  sphere_pose_.orientation.y = 0;
  sphere_pose_.orientation.z = 0;
  sphere_pose_.orientation.w = 0;

  sphere_.primitives.push_back(sphere_primitive_);
  sphere_.primitive_poses.push_back(sphere_pose_);
  sphere_.operation = sphere_.ADD;

  collision_objects_.push_back(sphere_);
}


*/



/* UNCOMMENT THE PART BELOW IF WE MAKE A CLASS OF ADDRVIZOBSTACLES */

#include <add_rviz_obstacles.h>

void AddRvizObstacles::addBoxCollisionObject( const std::string& frame_id, const std::string& id,
                                              const double& dimension_x, const double& dimension_y, const double& dimension_z,
                                              const Eigen::Matrix<double,3,1>& position,
                                              const Eigen::Quaterniond& orientation)
{
  moveit_msgs::CollisionObject box_;
  shape_msgs::SolidPrimitive box_primitive_;
  geometry_msgs::Pose box_pose_;
  box_.header.frame_id = frame_id;
  box_.id = id;

  box_primitive_.type = box_primitive_.BOX;
  box_primitive_.dimensions.resize(3);
  box_primitive_.dimensions[0] = dimension_x;
  box_primitive_.dimensions[1] = dimension_y;
  box_primitive_.dimensions[2] = dimension_z;

  box_pose_.position.x = position[0]; 
  box_pose_.position.y = position[1]; 
  box_pose_.position.z = position[2]; 
  box_pose_.orientation.x = orientation.coeffs()[0]; 
  box_pose_.orientation.y = orientation.coeffs()[1];  
  box_pose_.orientation.z = orientation.coeffs()[2];  
  box_pose_.orientation.w = orientation.coeffs()[3]; 

  box_.primitives.push_back(box_primitive_);
  box_.primitive_poses.push_back(box_pose_);
  box_.operation = box_.ADD;

  collision_objects_.push_back(box_);
}


void AddRvizObstacles::addCylinderCollisionObject( const std::string& frame_id, const std::string& id,
                                                  const double& height, const double& radius, 
                                                  const Eigen::Matrix<double,3,1>& position,
                                                  const Eigen::Quaterniond& orientation)
{
  moveit_msgs::CollisionObject cylinder_;
  shape_msgs::SolidPrimitive cylinder_primitive_;
  geometry_msgs::Pose cylinder_pose_;
  cylinder_.header.frame_id = frame_id;
  cylinder_.id = id;

  cylinder_primitive_.type = cylinder_primitive_.CYLINDER;
  cylinder_primitive_.dimensions.resize(2);
  cylinder_primitive_.dimensions[0] = height;
  cylinder_primitive_.dimensions[1] = radius;

  cylinder_pose_.position.x = position[0]; 
  cylinder_pose_.position.y = position[1]; 
  cylinder_pose_.position.z = position[2];
  cylinder_pose_.orientation.x = orientation.coeffs()[0]; 
  cylinder_pose_.orientation.y = orientation.coeffs()[1];  
  cylinder_pose_.orientation.z = orientation.coeffs()[2];  
  cylinder_pose_.orientation.w = orientation.coeffs()[3]; 

  cylinder_.primitives.push_back(cylinder_primitive_);
  cylinder_.primitive_poses.push_back(cylinder_pose_);
  cylinder_.operation = cylinder_.ADD;

  collision_objects_.push_back(cylinder_);
}

void AddRvizObstacles::addSphereCollisionObject(const std::string& frame_id, const std::string& id,
                                                const double& radius, 
                                                const Eigen::Matrix<double,3,1>& position)
{     
  moveit_msgs::CollisionObject sphere_;
  shape_msgs::SolidPrimitive sphere_primitive_;
  geometry_msgs::Pose sphere_pose_;                     
  sphere_.header.frame_id = frame_id;
  sphere_.id = id;

  sphere_primitive_.type = sphere_primitive_.SPHERE;
  sphere_primitive_.dimensions.resize(1);
  sphere_primitive_.dimensions[0] = radius;

  sphere_pose_.position.x = position[0];
  sphere_pose_.position.y = position[1];
  sphere_pose_.position.z = position[2];
  sphere_pose_.orientation.x = 1;
  sphere_pose_.orientation.y = 0;
  sphere_pose_.orientation.z = 0;
  sphere_pose_.orientation.w = 0;

  sphere_.primitives.push_back(sphere_primitive_);
  sphere_.primitive_poses.push_back(sphere_pose_);
  sphere_.operation = sphere_.ADD;

  collision_objects_.push_back(sphere_);
}
