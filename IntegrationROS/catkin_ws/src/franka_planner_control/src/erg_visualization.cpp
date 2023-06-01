#include <erg_visualization.h>

void ERGVisualization::addOneSphere(const Eigen::Matrix<double, 3, 1>& sphere_center,
                                    const Eigen::Matrix<double, 1, 1>& sphere_radii,
                                    int id,
                                    const std::string& ns){
  
    visualization_msgs::Marker marker_sphere;
    marker_sphere.header.frame_id = frame_id;
    marker_sphere.header.stamp = ros::Time::now();
    marker_sphere.ns = ns;
    marker_sphere.id = id;
    marker_sphere.type = visualization_msgs::Marker::SPHERE; 
    marker_sphere.action = visualization_msgs::Marker::ADD;
    marker_sphere.pose.position.x = sphere_center(0,0); 
    marker_sphere.pose.position.y = sphere_center(1,0); 
    marker_sphere.pose.position.z = sphere_center(2,0);  
    marker_sphere.pose.orientation.x = 0.0;
    marker_sphere.pose.orientation.y = 0.0;
    marker_sphere.pose.orientation.z = 0.0;
    marker_sphere.pose.orientation.w = 1.0;
    marker_sphere.scale.x = 2*sphere_radii[0]; 
    marker_sphere.scale.y = 2*sphere_radii[0]; 
    marker_sphere.scale.z = 2*sphere_radii[0]; 
    marker_sphere.color.r = color.r;
    marker_sphere.color.g = color.g;
    marker_sphere.color.b = color.b;
    marker_sphere.color.a = color.a;
    marker_sphere.lifetime = ros::Duration();
    static_marker_array.markers.push_back(marker_sphere);

}

void ERGVisualization::addOneWall(const Eigen::Matrix<double, 3, 1>& wall_normal,
                                  const Eigen::Matrix<double, 1, 1>& wall_distance, 
                                  const Eigen::Matrix<double, 1, 1>& wall_height, 
                                  const Eigen::Matrix<double, 1, 1>& wall_length, 
                                  const Eigen::Matrix<double, 1, 1>& wall_width,
                                  const Eigen::Matrix<double, 4, 1>& wall_quaternion, 
                                  int id,
                                  const std::string& ns
                                  ){
    visualization_msgs::Marker marker_wall;
    marker_wall.header.frame_id = frame_id;
    marker_wall.header.stamp = ros::Time::now();
    marker_wall.ns = ns;
    marker_wall.id = id;
    marker_wall.type = visualization_msgs::Marker::CUBE; 
    marker_wall.action = visualization_msgs::Marker::ADD;
    marker_wall.pose.position.x = (wall_distance(0)+wall_width(0)/2)*wall_normal(0,0);
    marker_wall.pose.position.y = (wall_distance(0)+wall_width(0)/2)*wall_normal(1,0); 
    marker_wall.pose.position.z = wall_height(0)/2; 
    marker_wall.pose.orientation.x = wall_quaternion(0,0);
    marker_wall.pose.orientation.y = wall_quaternion(1,0);
    marker_wall.pose.orientation.z = wall_quaternion(2,0); //-0.3826843; //0.0;
    marker_wall.pose.orientation.w = wall_quaternion(3,0); //0.9238792; //1.0;
    marker_wall.scale.x = wall_width(0);
    marker_wall.scale.y = wall_length(0); 
    marker_wall.scale.z = wall_height(0); 
    marker_wall.color.r = color.r;
    marker_wall.color.g = color.g;
    marker_wall.color.b = color.b;
    marker_wall.color.a = color.a;
    marker_wall.lifetime = ros::Duration();
    static_marker_array.markers.push_back(marker_wall);

}


void ERGVisualization::addOneCylinder(const Eigen::Matrix<double, 6, 1>& cylinder_startendpoint,
                                      const Eigen::Matrix<double, 1, 1>& cylinder_radii,
                                      int id,
                                      const std::string& ns){
    visualization_msgs::Marker marker_cylinder;
    Eigen::Matrix<double, 3, 1> cylinder_startpoint = cylinder_startendpoint.block(0,0,3,1);
    Eigen::Matrix<double, 3, 1> cylinder_endpoint = cylinder_startendpoint.block(3,0,3,1);
    Eigen::Matrix<double, 3, 1> cylinder_center = (cylinder_startpoint + cylinder_endpoint)*0.5;


    marker_cylinder.header.frame_id = frame_id;
    marker_cylinder.header.stamp = ros::Time::now();
    marker_cylinder.ns = ns;
    marker_cylinder.id = id;
    marker_cylinder.type = visualization_msgs::Marker::CYLINDER; 
    marker_cylinder.action = visualization_msgs::Marker::ADD;
    marker_cylinder.pose.position.x = cylinder_center[0]; 
    marker_cylinder.pose.position.y = cylinder_center[1];
    marker_cylinder.pose.position.z = cylinder_center[2];


    Eigen::Vector3d cylinder_z_direction(cylinder_startpoint-cylinder_endpoint);
    Eigen::Vector3d origin_z_direction(0., 0., 1.);
    cylinder_z_direction.normalize();
    Eigen::Vector3d axis;
    axis = origin_z_direction.cross(cylinder_z_direction);
    axis.normalize();
    double angle = acos(cylinder_z_direction.dot(origin_z_direction));
    double qx = axis.x() * sin(angle/2);
    double qy = axis.y() * sin(angle/2);
    double qz = axis.z() * sin(angle/2);
    double qw = cos(angle/2);
    double qnorm = sqrt(qx*qx + qy*qy + qz*qz + qw *qw);
    marker_cylinder.pose.orientation.x = qx/qnorm;
    marker_cylinder.pose.orientation.y = qy/qnorm;
    marker_cylinder.pose.orientation.z = qz/qnorm;
    marker_cylinder.pose.orientation.w = qw/qnorm;
    

    marker_cylinder.scale.x = 2.0*cylinder_radii[0];
    marker_cylinder.scale.y = 2.0*cylinder_radii[0];
    marker_cylinder.scale.z = (cylinder_startpoint - cylinder_endpoint).norm();
    marker_cylinder.color.r = color.r;
    marker_cylinder.color.g = color.g;
    marker_cylinder.color.b = color.b;
    marker_cylinder.color.a = color.a;
    marker_cylinder.lifetime = ros::Duration();
    static_marker_array.markers.push_back(marker_cylinder);

}

void ERGVisualization::changeMarkersColor(float r, float g, float b, float a){
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}

void ERGVisualization::changeSkeletonsMarkersColor(float r, float g, float b, float a){
    skeleton_color.r = r;
    skeleton_color.g = g;
    skeleton_color.b = b;
    skeleton_color.a = a;
}

void ERGVisualization::publishMarkers(ros::Publisher publisher){
    visualization_msgs::MarkerArray publish_marker_array = static_marker_array;
    for (uint i=0;i<reference_frame_marker_array.markers.size();i++){
        publish_marker_array.markers.push_back(reference_frame_marker_array.markers[i]);
    } 
    for (uint i=0;i<skeleton_marker_array.markers.size();i++){
        publish_marker_array.markers.push_back(skeleton_marker_array.markers[i]);
    } 
    publisher.publish(publish_marker_array);
    skeleton_marker_array.markers.clear();
    reference_frame_marker_array.markers.clear();
}

ERGVisualization::ERGVisualization(std::string frame){
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 0.8;
    skeleton_color.r = 1;
    skeleton_color.g = 0;
    skeleton_color.b = 0;
    skeleton_color.a = 0.8;
    frame_id = frame;
    skeleton_frame_id = "zed2_left_camera_frame";
    tf.waitForTransform(skeleton_frame_id, frame_id, ros::Time(), ros::Duration(1.0));
}

ERGVisualization::ERGVisualization(){
    color.r = 1;
    color.g = 0;
    color.b = 0;
    color.a = 0.8;
    skeleton_color.r = 1;
    skeleton_color.g = 0;
    skeleton_color.b = 0;
    skeleton_color.a = 0.8;
    frame_id = "panda_link0";
    skeleton_frame_id = "zed2_left_camera_frame";
    tf.waitForTransform(skeleton_frame_id, frame_id, ros::Time(), ros::Duration(1.0));
}

void ERGVisualization::deleteAllMarkers(){
    static_marker_array.markers.clear();
    skeleton_marker_array.markers.clear();
}

void ERGVisualization::deleteAllSkeletonMarkers(){
    skeleton_marker_array.markers.clear();
}


void ERGVisualization::addSkeletonCylinder(const Eigen::Matrix<double, 3, 1> &cylinder_startpoint,const Eigen::Matrix<double, 3, 1> &cylinder_endpoint, const double &r, int skeleton_id,int id){
    Eigen::Matrix<double,3,1> center = (cylinder_startpoint+cylinder_endpoint)*0.5;
    visualization_msgs::Marker marker_cylinder;
    marker_cylinder.header.frame_id = skeleton_frame_id;
    marker_cylinder.header.stamp = ros::Time::now();
    marker_cylinder.ns = "skeleton";
    marker_cylinder.id = skeleton_id*100+id;
    marker_cylinder.type = visualization_msgs::Marker::CYLINDER; 
    marker_cylinder.action = visualization_msgs::Marker::ADD;
    marker_cylinder.pose.position.x = center[0]; 
    marker_cylinder.pose.position.y = center[1];
    marker_cylinder.pose.position.z = center[2];
    Eigen::Vector3d cylinder_z_direction(cylinder_startpoint-cylinder_endpoint);
    Eigen::Vector3d origin_z_direction(0., 0., 1.);
    cylinder_z_direction.normalize();
    Eigen::Vector3d axis;
    axis = origin_z_direction.cross(cylinder_z_direction);
    axis.normalize();
    double angle = acos(cylinder_z_direction.dot(origin_z_direction));
    double qx = axis.x() * sin(angle/2);
    double qy = axis.y() * sin(angle/2);
    double qz = axis.z() * sin(angle/2);
    double qw = cos(angle/2);
    double qnorm = sqrt(qx*qx + qy*qy + qz*qz + qw *qw);
    marker_cylinder.pose.orientation.x = qx/qnorm;
    marker_cylinder.pose.orientation.y = qy/qnorm;
    marker_cylinder.pose.orientation.z = qz/qnorm;
    marker_cylinder.pose.orientation.w = qw/qnorm;
    marker_cylinder.scale.x = 2.0*r;
    marker_cylinder.scale.y = 2.0*r;
    marker_cylinder.scale.z = (cylinder_startpoint - cylinder_endpoint).norm();
    marker_cylinder.color.r = skeleton_color.r;
    marker_cylinder.color.g = skeleton_color.g;
    marker_cylinder.color.b = skeleton_color.b;
    marker_cylinder.color.a = skeleton_color.a;
    marker_cylinder.lifetime = ros::Duration(0.5);
    skeleton_marker_array.markers.push_back(marker_cylinder);
}

void ERGVisualization::addSkeletonSphere(const Eigen::Matrix<double, 3, 1>& sphere_center, double r, int skeleton_id,int id){
    visualization_msgs::Marker marker_sphere;
    marker_sphere.header.frame_id = skeleton_frame_id;
    marker_sphere.header.stamp = ros::Time::now();
    marker_sphere.ns = "skeleton";
    marker_sphere.id = skeleton_id*100+id;
    marker_sphere.type = visualization_msgs::Marker::SPHERE; 
    marker_sphere.action = visualization_msgs::Marker::ADD;
    marker_sphere.pose.position.x = sphere_center[0]; 
    marker_sphere.pose.position.y = sphere_center[1]; 
    marker_sphere.pose.position.z = sphere_center[2];  
    marker_sphere.pose.orientation.x = 0.0;
    marker_sphere.pose.orientation.y = 0.0;
    marker_sphere.pose.orientation.z = 0.0;
    marker_sphere.pose.orientation.w = 1.0;
    marker_sphere.scale.x = 2*r; 
    marker_sphere.scale.y = 2*r; 
    marker_sphere.scale.z = 2*r; 
    marker_sphere.color.r = skeleton_color.r;
    marker_sphere.color.g = skeleton_color.g;
    marker_sphere.color.b = skeleton_color.b;
    marker_sphere.color.a = skeleton_color.a;
    marker_sphere.lifetime = ros::Duration(0.5);
    skeleton_marker_array.markers.push_back(marker_sphere);
}


void ERGVisualization::addOneSkeleton(const zed_interfaces::Skeleton3D &skeleton_3d, int id){

    std::vector<Eigen::Matrix<double, 3, 1>> points(18);
    double hand_radius = 0.07;
    for(int j=0; j<18; j++){
        points[j][0] = skeleton_3d.keypoints[j].kp[0];
        points[j][1] = skeleton_3d.keypoints[j].kp[1];
        points[j][2] = skeleton_3d.keypoints[j].kp[2];
    }

    /* head */
    addSkeletonSphere((points[16]+points[17])*0.5, (points[0]-points[1]).norm(), id, 0);
    
    /* body */
    addSkeletonCylinder(points[1], (points[8]+points[11])*0.5, 0.15, id, 1);

    /* upper right arm */
    addSkeletonCylinder(points[2], points[3], 0.05, id, 2);

    /* lower right arm */
    addSkeletonCylinder(points[3], points[4], 0.05, id, 3);

    /* right hand */
    Eigen::Matrix<double, 3, 1> p2;
    double inv_d2 = 1/((points[3]-points[4]).norm());
    p2 = points[4] + (points[4]-points[3])*inv_d2*hand_radius;

    addSkeletonSphere( p2, hand_radius, id, 4);

    /* upper left arm */
    addSkeletonCylinder( points[5], points[6], 0.05, id, 5);

    /* lower left arm */
    addSkeletonCylinder(points[6], points[7], 0.05, id, 6);

    /* left hand */
    Eigen::Matrix<double, 3, 1> p1;
    double inv_d1 = 1/((points[6]-points[7]).norm());
    p1 = points[7] + (points[7]-points[6])*inv_d1*hand_radius;
    addSkeletonSphere(p1, hand_radius, id, 7);

    /* upper right leg */
    // addSkeletonCylinder(points[8], points[9], 0.1, id, 8);

    /* lower right leg */
    // addSkeletonCylinder(points[9], points[10], 0.1, id, 9);

    /* upper left leg */
    // addSkeletonCylinder(points[11], points[12], 0.1, id, 10);

    /* lower left leg */
    // addSkeletonCylinder(points[12], points[13], 0.1, id, 11);

}

void ERGVisualization::addAllSkeletons(const std::vector<zed_interfaces::Object> &objects){
    joints_positions.clear();
    for(int i=0; i < objects.size();i++){
      zed_interfaces::Object obj = objects[i];
      if (!obj.skeleton_available)
         return;
      if (obj.label == "Person"){
         addOneSkeleton(obj.skeleton_3d, obj.label_id);
         if(update_pose)
            addJointsPositions(obj.skeleton_3d);
      }
   }
}

void ERGVisualization::changeSkeletonsFrame(const std::string& frame){
    skeleton_frame_id = frame;
}

void ERGVisualization::getTransformation(){
    try{
        tf::StampedTransform echo_transform;
        tf.lookupTransform(frame_id, skeleton_frame_id, ros::Time(), echo_transform);
        tf::Vector3 v = echo_transform.getOrigin();
        camera2robotTransfo.transform.translation.x = v.getX();
        camera2robotTransfo.transform.translation.y = v.getY();
        camera2robotTransfo.transform.translation.z = v.getZ();
        tf::Quaternion q = echo_transform.getRotation();
        camera2robotTransfo.transform.rotation.x = q.getX();
        camera2robotTransfo.transform.rotation.y = q.getY();
        camera2robotTransfo.transform.rotation.z = q.getZ();
        camera2robotTransfo.transform.rotation.w = q.getW();
    }
    catch (tf::TransformException &ex) {
        ROS_WARN("%s",ex.what());
    }
}

void ERGVisualization::addJointsPositions(const zed_interfaces::Skeleton3D &skeleton_3d){
    std::vector<Eigen::Matrix<double, 3, 1>> joints(18); // joints of one skeleton
    Eigen::Matrix<double, 3, 1> joint;
    geometry_msgs::Pose pose;
    getTransformation();
    pose.orientation.w = 1;
   
    for(int j=0; j<18; j++){
        pose.position.x = skeleton_3d.keypoints[j].kp[0];
        pose.position.y = skeleton_3d.keypoints[j].kp[1];
        pose.position.z = skeleton_3d.keypoints[j].kp[2];
        tf2::doTransform(pose, pose, camera2robotTransfo);
        joint[0] = pose.position.x;
        joint[1] = pose.position.y;
        joint[2] = pose.position.z;
        joints[j] = joint;
    }
    joints_positions.push_back(joints);
}

std::vector<std::vector<Eigen::Matrix<double, 3, 1>>> ERGVisualization::getJointsPositions(){
    return joints_positions; //joints of all skeletons
}

void ERGVisualization::updateSkeletonsPoses(bool b){
    update_pose = b;
}

void ERGVisualization::changeRobotFrame(const std::string& frame){
    frame_id = frame;
}

void ERGVisualization::addEndEffectorReferenceFrame(const geometry_msgs::Pose& x_ee, int& rviz_orientation_problem, const std::string& ns){
    visualization_msgs::Marker marker_endeffector_reference;

    Eigen::Matrix<double,3,1> position_x_ee = {x_ee.position.x, x_ee.position.y, x_ee.position.z};
    Eigen::Quaterniond quat_x_ee; 
    Eigen::Matrix3d rotationmatrix_x_ee;
    if(rviz_orientation_problem==1){   // true, problems
        Eigen::Quaterniond quat_rotation_correction; 
        Eigen::Quaterniond quat_resulting_orientation;
        quat_x_ee = Eigen::Quaterniond(x_ee.orientation.w, x_ee.orientation.x, x_ee.orientation.y, x_ee.orientation.z); 
        quat_rotation_correction = Eigen::Quaterniond(0.9063078, 0.0, 0.0, -0.4226183); 
        quat_resulting_orientation = quat_x_ee*quat_rotation_correction;
        rotationmatrix_x_ee = quat_resulting_orientation.toRotationMatrix();
    }
    else if(rviz_orientation_problem==0){ // false, no problems
        quat_x_ee = Eigen::Quaterniond(x_ee.orientation.w, x_ee.orientation.x, x_ee.orientation.y, x_ee.orientation.z); // w,x,y,z
        rotationmatrix_x_ee = quat_x_ee.toRotationMatrix();
    }
    

    Eigen::Matrix<double, 3, 1> startpoint; 
    startpoint[0] = position_x_ee[0]; 
    startpoint[1] = position_x_ee[1]; 
    startpoint[2] = position_x_ee[2]; 

    Eigen::Matrix<double, 3, 1> endpoint_x; 
    endpoint_x[0] = position_x_ee[0] +rotationmatrix_x_ee(0,0)/10;
    endpoint_x[1] = position_x_ee[1] +rotationmatrix_x_ee(1,0)/10; 
    endpoint_x[2] = position_x_ee[2] +rotationmatrix_x_ee(2,0)/10; 

    Eigen::Matrix<double, 3, 1> endpoint_y; 
    endpoint_y[0] = position_x_ee[0] +rotationmatrix_x_ee(0,1)/10; 
    endpoint_y[1] = position_x_ee[1] +rotationmatrix_x_ee(1,1)/10; 
    endpoint_y[2] = position_x_ee[2] +rotationmatrix_x_ee(2,1)/10; 

    Eigen::Matrix<double, 3, 1> endpoint_z; 
    endpoint_z[0] = position_x_ee[0] +rotationmatrix_x_ee(0,2)/10; 
    endpoint_z[1] = position_x_ee[1] +rotationmatrix_x_ee(1,2)/10; 
    endpoint_z[2] = position_x_ee[2] +rotationmatrix_x_ee(2,2)/10; 

    marker_endeffector_reference.header.frame_id = frame_id; //"panda_link0";
    marker_endeffector_reference.header.stamp = ros::Time::now();
    marker_endeffector_reference.ns = ns;
    marker_endeffector_reference.id = 0;
    marker_endeffector_reference.type = visualization_msgs::Marker::ARROW; 
    marker_endeffector_reference.action = visualization_msgs::Marker::ADD;
    marker_endeffector_reference.pose.orientation.y = 0.0;
    marker_endeffector_reference.pose.orientation.w = 1.0;  
    marker_endeffector_reference.scale.x = 0.01; // shaft diameter
    marker_endeffector_reference.scale.y = 0.02; // head diameter
    marker_endeffector_reference.scale.z = 0.02; // head length if not zero
    marker_endeffector_reference.color.r = 1.0f;
    marker_endeffector_reference.color.g = 0.0f;
    marker_endeffector_reference.color.b = 0.0f;
    marker_endeffector_reference.color.a = 1.0;
    marker_endeffector_reference.points.resize(2);
    marker_endeffector_reference.points[0].x = startpoint[0]; 
    marker_endeffector_reference.points[0].y = startpoint[1]; 
    marker_endeffector_reference.points[0].z = startpoint[2];
    marker_endeffector_reference.points[1].x = endpoint_x[0];
    marker_endeffector_reference.points[1].y = endpoint_x[1];
    marker_endeffector_reference.points[1].z = endpoint_x[2];
    marker_endeffector_reference.lifetime = ros::Duration();
    reference_frame_marker_array.markers.push_back(marker_endeffector_reference);

    marker_endeffector_reference.header.frame_id = frame_id; //"panda_link0";
    marker_endeffector_reference.header.stamp = ros::Time::now();
    marker_endeffector_reference.ns = ns;
    marker_endeffector_reference.id = 1;
    marker_endeffector_reference.type = visualization_msgs::Marker::ARROW; 
    marker_endeffector_reference.action = visualization_msgs::Marker::ADD;
    marker_endeffector_reference.pose.orientation.y = 0.0;
    marker_endeffector_reference.pose.orientation.w = 1.0;  
    marker_endeffector_reference.scale.x = 0.01; // shaft diameter
    marker_endeffector_reference.scale.y = 0.02; // head diameter
    marker_endeffector_reference.scale.z = 0.02; // head length if not zero
    marker_endeffector_reference.color.r = 0.0f;
    marker_endeffector_reference.color.g = 1.0f;
    marker_endeffector_reference.color.b = 0.0f;
    marker_endeffector_reference.color.a = 1.0;
    marker_endeffector_reference.points.resize(2);
    marker_endeffector_reference.points[0].x = startpoint[0]; 
    marker_endeffector_reference.points[0].y = startpoint[1]; 
    marker_endeffector_reference.points[0].z = startpoint[2];
    marker_endeffector_reference.points[1].x = endpoint_y[0];
    marker_endeffector_reference.points[1].y = endpoint_y[1];
    marker_endeffector_reference.points[1].z = endpoint_y[2];
    marker_endeffector_reference.lifetime = ros::Duration();
    reference_frame_marker_array.markers.push_back(marker_endeffector_reference);

    marker_endeffector_reference.header.frame_id = frame_id; //"panda_link0";
    marker_endeffector_reference.header.stamp = ros::Time::now();
    marker_endeffector_reference.ns = ns;
    marker_endeffector_reference.id = 2;
    marker_endeffector_reference.type = visualization_msgs::Marker::ARROW; 
    marker_endeffector_reference.action = visualization_msgs::Marker::ADD;
    marker_endeffector_reference.pose.orientation.y = 0.0;
    marker_endeffector_reference.pose.orientation.w = 1.0;  
    marker_endeffector_reference.scale.x = 0.01; // shaft diameter
    marker_endeffector_reference.scale.y = 0.02; // head diameter
    marker_endeffector_reference.scale.z = 0.02; // head length if not zero
    marker_endeffector_reference.color.r = 0.0f;
    marker_endeffector_reference.color.g = 0.0f;
    marker_endeffector_reference.color.b = 1.0f;
    marker_endeffector_reference.color.a = 1.0;
    marker_endeffector_reference.points.resize(2);
    marker_endeffector_reference.points[0].x = startpoint[0]; 
    marker_endeffector_reference.points[0].y = startpoint[1]; 
    marker_endeffector_reference.points[0].z = startpoint[2];
    marker_endeffector_reference.points[1].x = endpoint_z[0];
    marker_endeffector_reference.points[1].y = endpoint_z[1];
    marker_endeffector_reference.points[1].z = endpoint_z[2];
    marker_endeffector_reference.lifetime = ros::Duration();
    reference_frame_marker_array.markers.push_back(marker_endeffector_reference);

}