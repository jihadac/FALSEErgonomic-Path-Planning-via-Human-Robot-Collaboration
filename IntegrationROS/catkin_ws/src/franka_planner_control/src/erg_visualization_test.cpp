#include <erg_visualization.h>
#include <zed_interfaces/ObjectsStamped.h>
#define PI 3.1415926

ros::Publisher marker_array_pub;

void skeletonTrackingCallback(const zed_interfaces::ObjectsStamped::ConstPtr& msg, ERGVisualization *visualisation_rviz) {
   visualisation_rviz -> addAllSkeletons(msg -> objects);
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "erg_vis_test");
    ros::NodeHandle n;
    ros::Rate r(10);
    marker_array_pub = n.advertise<visualization_msgs::MarkerArray>("erg_visualization", 10);
    
    /* initialize spheres */
    const uint number_of_spheres = 2;
    Eigen::Matrix<double, 3, number_of_spheres> sphere_centers;
    Eigen::Matrix<double, 1, number_of_spheres> sphere_radii;

    {
        Eigen::Matrix<double, 3, 1> c1 = {0.3, 0.3, 0.65};
        Eigen::Matrix<double, 3, 1> c2 = {1.6, 1.6, 0.25};
        sphere_centers.block(0,0,3,1) = c1;
        sphere_centers.block(0,1,3,1) = c2;
        sphere_radii(0) = 0.1;
        sphere_radii(1) = 0.2;
    }

    /* initialize walls */
    const uint number_of_walls = 4;
    Eigen::Matrix<double, 3, number_of_walls> wall_normals;
    Eigen::Matrix<double, 1, number_of_walls> wall_distances;
    Eigen::Matrix<double, 1, number_of_walls> wall_heights;
    Eigen::Matrix<double, 1, number_of_walls> wall_lengths;
    Eigen::Matrix<double, 1, number_of_walls> wall_widths;
    Eigen::Matrix<double, 4, number_of_walls> wall_quaternions;

    {

        double wall1_rotationangleaboutz = (40+270)*PI/180;
        Eigen::Matrix3d elementary_zrotation_wall1;
        elementary_zrotation_wall1 = Eigen::AngleAxisd(wall1_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
        Eigen::Matrix<double, 3, 1> wall1_normal =elementary_zrotation_wall1.col(0);
        Eigen::Quaterniond quat_wall1;
        quat_wall1 = Eigen::Quaterniond(elementary_zrotation_wall1);
        wall_normals.block(0,0,3,1) = wall1_normal; 
        wall_quaternions.block(0,0,4,1) = quat_wall1.coeffs();
        wall_distances(0) = 0.55;
        wall_heights(0) = 0.90;
        wall_lengths(0) = 0.90;
        wall_widths(0) = 0.01;
    }
    {
        double wall2_rotationangleaboutz = (40+90)*PI/180;
        Eigen::Matrix3d elementary_zrotation_wall2;
        elementary_zrotation_wall2 = Eigen::AngleAxisd(wall2_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
        Eigen::Matrix<double, 3, 1> wall2_normal =elementary_zrotation_wall2.col(0);
        Eigen::Quaterniond quat_wall2;
        quat_wall2 = Eigen::Quaterniond(elementary_zrotation_wall2);
        wall_normals.block(0,1,3,1) = wall2_normal; 
        wall_quaternions.block(0,1,4,1) = quat_wall2.coeffs();
        wall_distances(1) = 0.5;
        wall_heights(1) = 0.45;
        wall_lengths(1) = 0.90;
        wall_widths(1) = 0.02;
    }

    {
        double wall3_rotationangleaboutz = (40+180)*PI/180;
        Eigen::Matrix3d elementary_zrotation_wall3;
        elementary_zrotation_wall3 = Eigen::AngleAxisd(wall3_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
        Eigen::Matrix<double, 3, 1> wall3_normal =elementary_zrotation_wall3.col(0);
        Eigen::Quaterniond quat_wall3;
        quat_wall3 = Eigen::Quaterniond(elementary_zrotation_wall3);
        wall_normals.block(0,2,3,1) = wall3_normal; 
        wall_quaternions.block(0,2,4,1) = quat_wall3.coeffs();
        wall_distances(2) = 0.5;
        wall_heights(2) = 0.45;
        wall_lengths(2) = 0.90;
        wall_widths(2) = 0.02;
    }
    {
        double wall4_rotationangleaboutz =  40*PI/180;
        Eigen::Matrix3d elementary_zrotation_wall4;
        elementary_zrotation_wall4 = Eigen::AngleAxisd(wall4_rotationangleaboutz, Eigen::Vector3d::UnitZ()); 
        Eigen::Matrix<double, 3, 1> wall4_normal =elementary_zrotation_wall4.col(0);
        Eigen::Quaterniond quat_wall4;
        quat_wall4 = Eigen::Quaterniond(elementary_zrotation_wall4);
        wall_normals.block(0,3,3,1) = wall4_normal; 
        wall_quaternions.block(0,3,4,1) = quat_wall4.coeffs();
        wall_distances(3) = 0.5;
        wall_heights(3) = 0.45;
        wall_lengths(3) = 0.90;
        wall_widths(3) = 0.02;
    }

    /* initialize cylinders*/
    const uint number_of_cylinders = 3;
    Eigen::Matrix<double, 6, number_of_cylinders> cylinder_startendpoints; 
    Eigen::Matrix<double, 1, number_of_cylinders> cylinder_radii;

    {
        double obst_cylinder1_radius = 0.10;
        Eigen::Matrix<double, 3, 1> obst_cylinder1_startpoint = {0.5, -0.3, 0.0}; // defined in robot base frame
        Eigen::Matrix<double, 3, 1> obst_cylinder1_endpoint = {0.5, -0.3, 0.35}; // defined in robot base frame
        cylinder_radii[0] = obst_cylinder1_radius;
        cylinder_startendpoints.block(0,0,3,1) = obst_cylinder1_startpoint; 
        cylinder_startendpoints.block(3,0,3,1) = obst_cylinder1_endpoint; 

        double obst_cylinder2_radius = 0.10;
        Eigen::Matrix<double, 3, 1> obst_cylinder2_startpoint = {0.0, 0.6, 0.0}; // defined in robot base frame
        Eigen::Matrix<double, 3, 1> obst_cylinder2_endpoint = {0.0, 0.6, 0.8}; // defined in robot base frame
        cylinder_radii[1] = obst_cylinder2_radius;
        cylinder_startendpoints.block(0,1,3,1) = obst_cylinder2_startpoint; 
        cylinder_startendpoints.block(3,1,3,1) = obst_cylinder2_endpoint; 

        Eigen::Matrix<double, 6, 1> cylinder3_endstart;
        cylinder3_endstart << 0.,0.,0.,0.5,0.5,0.5;
        cylinder_startendpoints.block(0,2,6,1) = cylinder3_endstart;
        cylinder_radii[2] = 0.05;

    }

    ERGVisualization visualisation_rviz("panda_link0"); //map is the frame in whiich you want to add your objects it is panda_link0 for the erg program
  
    /* skeleton tracking callback */
    ros::Subscriber subObjList;
    boost::function<void (const zed_interfaces::ObjectsStamped::ConstPtr&)> f = boost::bind(skeletonTrackingCallback, _1, &visualisation_rviz);
    subObjList = n.subscribe("/zed2/zed_node/obj_det/objects", 1, f);

    /* change the color of the futur marker you want to add
    visualisation_rviz.changeMarkersColor(red, green, blue, alpha)*/
    visualisation_rviz.changeSkeletonsMarkersColor(0, 1, 1, 0.7);
    visualisation_rviz.changeMarkersColor(0, 1, 0, 0.7);

    /* add all spheres*/
    for (uint i = 0; i < number_of_spheres; i++){
         visualisation_rviz.addOneSphere(sphere_centers.block(0,i,3,1), 
                                         sphere_radii.block(0,i,1,1), 
                                         i, 
                                         "spheres");
    }


    visualisation_rviz.changeMarkersColor(0, 0, 1, 0.7);
    /* add all walls*/
    for (uint i = 0; i < number_of_walls; i++){
        visualisation_rviz.addOneWall(wall_normals.block(0,i,3,1),
                                      wall_distances.block(0,i,1,1), 
                                      wall_heights.block(0,i,1,1), 
                                      wall_lengths.block(0,i,1,1), 
                                      wall_widths.block(0,i,1,1),
                                      wall_quaternions.block(0,i,4,1), 
                                      i,
                                      "walls");
    }

    visualisation_rviz.changeMarkersColor(1, 0, 0, 0.7);
    for (uint i = 0; i < number_of_cylinders; i++){
        visualisation_rviz.addOneCylinder(cylinder_startendpoints.block(0,i,6,1),
                                          cylinder_radii.block(0,i,1,1),
                                          i,
                                          "cylinders");
    }

    visualisation_rviz.updateSkeletonsPoses(true);
    std::vector<std::vector<Eigen::Matrix<double, 3, 1>>> joints_poses;
    
    while(ros::ok()){
        visualisation_rviz.publishMarkers(marker_array_pub);
        ros::spinOnce();
        joints_poses = visualisation_rviz.getJointsPositions();
        if (joints_poses.size()){
            ROS_INFO_STREAM(joints_poses[0][4][0] << "," << joints_poses[0][4][1] << "," << joints_poses[0][4][2] << "\n");
        }
            
        r.sleep();
        
    }
    ros::shutdown();
    
}