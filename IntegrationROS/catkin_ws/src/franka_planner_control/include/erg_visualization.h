

#include <ros/ros.h>
#include <ros/time.h>
#include <visualization_msgs/MarkerArray.h>
#include <Eigen/Dense>
#include <Eigen/QR>
#include <Eigen/Geometry>
#include <string>
#include <zed_interfaces/Skeleton3D.h>
#include <zed_interfaces/Object.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_listener.h>

class ERGVisualization{
    private:
        visualization_msgs::MarkerArray static_marker_array;
        visualization_msgs::MarkerArray skeleton_marker_array;
        visualization_msgs::MarkerArray reference_frame_marker_array;
        std::string frame_id;
        std::string skeleton_frame_id;;
        std_msgs::ColorRGBA color;
        std_msgs::ColorRGBA skeleton_color;
        tf::TransformListener tf;
        geometry_msgs::TransformStamped camera2robotTransfo;
        std::vector<std::vector<Eigen::Matrix<double, 3, 1>>> joints_positions;
        bool update_pose;
        void getTransformation();
        void addOneSkeleton(const zed_interfaces::Skeleton3D &skeleton_3d, int id);
        void addSkeletonCylinder(const Eigen::Matrix<double, 3, 1> &p1,const Eigen::Matrix<double, 3, 1> &p2, const double &r, int skeleton_id, int id);
        void addSkeletonSphere(const Eigen::Matrix<double, 3, 1>&, double, int,int);
        void addJointsPositions(const zed_interfaces::Skeleton3D &skeleton_3d);

    public:
        ERGVisualization(std::string frame);
        ERGVisualization();
        void addOneSphere(const Eigen::Matrix<double, 3, 1>& sphere_center,
                          const Eigen::Matrix<double, 1, 1>& sphere_radii, 
                          int id, 
                          const std::string& ns);
        void addOneWall(const Eigen::Matrix<double, 3, 1>& wall_normal,
                        const Eigen::Matrix<double, 1, 1>& wall_distance, 
                        const Eigen::Matrix<double, 1, 1>& wall_height, 
                        const Eigen::Matrix<double, 1, 1>& wall_length, 
                        const Eigen::Matrix<double, 1, 1>& wall_width,
                        const Eigen::Matrix<double, 4, 1>& wall_quaternion, 
                        int id,
                        const std::string& ns);
        void addOneCylinder(const Eigen::Matrix<double, 6, 1>& cylinder_startendpoint,
                            const Eigen::Matrix<double, 1, 1>& cylinder_radii,
                            int id,
                            const std::string& ns);
        void publishMarkers(ros::Publisher);

        void changeMarkersColor(float r, float g, float b, float a);

        void changeSkeletonsMarkersColor(float r, float g, float b, float a);
        
        void addAllSkeletons(const std::vector<zed_interfaces::Object> &objects);
        
        void deleteAllMarkers();

        void deleteAllSkeletonMarkers();

        void changeSkeletonsFrame(const std::string& frame);

        void changeRobotFrame(const std::string& frame);
        std::vector<std::vector<Eigen::Matrix<double, 3, 1>>> getJointsPositions();

        void updateSkeletonsPoses(bool b);

        void addEndEffectorReferenceFrame(const geometry_msgs::Pose& x_ee, int& rviz_orientation_problem, const std::string& ns);
};