#include <ros/ros.h>

#include <zed_interfaces/Skeleton3D.h>
#include <zed_interfaces/Object.h>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_listener.h>
//#include "point_3D.h" // REMOVE THIS CLASS

/* TO INCLUDE */
#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>

class SkeletonTracker{
    private:
        geometry_msgs::TransformStamped zed2pandaTransfo;
        std::string tracked_id;
        std::string source_frame;
        std::string target_frame;
        bool collision_avoidance;
        tf::TransformListener tf;
        void getTransformation();
        std::vector<Eigen::Matrix<double, 3, 1>> tracked_joints_pose;
        bool id_toggle;
        void addCylinderCollisionObject(moveit_msgs::CollisionObject& ,const Eigen::Matrix<double, 3, 1> &p1,const Eigen::Matrix<double, 3, 1> &p2, const double &r);    
        void addSphereCollisionObject(moveit_msgs::CollisionObject&, const Eigen::Matrix<double, 3, 1> &p, const double & r); 
        void addSkeletonCollisionObject(const zed_interfaces::Skeleton3D& ,std::vector<moveit_msgs::CollisionObject>&, const std::string&);

    public:
        std::vector<std::string> collision_object_ids;
        SkeletonTracker(std::string source_frame, std::string target_frame, bool collision_avoidance);
        geometry_msgs::Pose getJointPosition(int joint_id);
        void setTrackedId(const std::string&);
        void trackAllSkeletons(const std::vector<zed_interfaces::Object> &objects, std::vector<moveit_msgs::CollisionObject>&);

};