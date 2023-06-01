#include <ros/ros.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>


class AddRvizObstacles
{
   public:
      void addBoxCollisionObject(const std::string& frame_id, const std::string& id,
                                 const double& dimension_x, const double& dimension_y, const double& dimension_z,
                                 const Eigen::Matrix<double,3,1>& position,
                                 const Eigen::Quaterniond& orientation);
      void addCylinderCollisionObject( const std::string& frame_id, const std::string& id,
                                       const double& height, const double& radius, 
                                       const Eigen::Matrix<double,3,1>& position,
                                       const Eigen::Quaterniond& orientation);
      void addSphereCollisionObject(const std::string& frame_id, const std::string& id,
                                    const double& radius, 
                                    const Eigen::Matrix<double,3,1>& position);

      std::vector<moveit_msgs::CollisionObject> collision_objects_;

   private:
      // moveit_msgs::CollisionObject box_;
      // shape_msgs::SolidPrimitive box_primitive_;
      // geometry_msgs::Pose box_pose_;

      // moveit_msgs::CollisionObject cylinder_;
      // shape_msgs::SolidPrimitive cylinder_primitive_;
      // geometry_msgs::Pose cylinder_pose_;

      // moveit_msgs::CollisionObject sphere_;
      // shape_msgs::SolidPrimitive sphere_primitive_;
      // geometry_msgs::Pose sphere_pose_;
};
