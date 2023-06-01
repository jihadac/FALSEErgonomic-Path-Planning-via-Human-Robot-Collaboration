#include <skeleton_tracker.h>

SkeletonTracker::SkeletonTracker(std::string source, std::string target, bool avoid_skeleton){
    source_frame = source;
    target_frame = target;
    collision_avoidance = avoid_skeleton;
    tf.waitForTransform(source_frame, target_frame, ros::Time(), ros::Duration(1.0));
    tracked_joints_pose.resize(18);
}

void SkeletonTracker::getTransformation(){
    try{
        tf::StampedTransform echo_transform;
        tf.lookupTransform(target_frame, source_frame, ros::Time(), echo_transform);
        tf::Vector3 v = echo_transform.getOrigin();
        zed2pandaTransfo.transform.translation.x = v.getX();
        zed2pandaTransfo.transform.translation.y = v.getY();
        zed2pandaTransfo.transform.translation.z = v.getZ();
        tf::Quaternion q = echo_transform.getRotation();
        zed2pandaTransfo.transform.rotation.x = q.getX();
        zed2pandaTransfo.transform.rotation.y = q.getY();
        zed2pandaTransfo.transform.rotation.z = q.getZ();
        zed2pandaTransfo.transform.rotation.w = q.getW();
    }
    catch (tf::TransformException &ex) {
        ROS_WARN("%s",ex.what());
    }
}

void SkeletonTracker::addCylinderCollisionObject(moveit_msgs::CollisionObject& skeleton,const Eigen::Matrix<double, 3, 1> &p1,const Eigen::Matrix<double, 3, 1> &p2, const double &r){ // REPLACE WITH EIGEN ARGUMENTS
    // Point3D middle = getMiddle(p1, p2);
    // double distance = getDistance(p1, p2);

    /* THIS IS HOW YOU CAN DEFINE EIGEN VECTORS AND GET THE CENTER AND THE DISTANCE */
    // Eigen::Matrix<double, 3, 1> p1 = {10, 10, 10}; 
	// Eigen::Matrix<double, 3, 1> p2 = {-10, 0, 5}; 
	// // std::cout << "p1: \n" << p1 << std::endl;
	// // std::cout << "p2: \n" << p2 << std::endl;
	double distance = (p1-p2).norm();
	// // std::cout << "distance_p1_p2 : " << distance_p1_p2 << std::endl;
	Eigen::Matrix<double,3,1> center = (p1+p2)*0.5;
	// // std::cout << "center_p1_p2:  \n" << center_p1_p2 << std::endl;

    shape_msgs::SolidPrimitive cylinder_primitive;
    cylinder_primitive.type = cylinder_primitive.CYLINDER;
    cylinder_primitive.dimensions.resize(2);
    cylinder_primitive.dimensions[0] = distance;
    cylinder_primitive.dimensions[1] = r;

    geometry_msgs::Pose cylinder_pose;
    cylinder_pose.position.x = center[0]; 
    cylinder_pose.position.y = center[1]; 
    cylinder_pose.position.z = center[2];

    Eigen::Vector3d cylinder_z_direction(p2-p1);
    Eigen::Vector3d origin_z_direction(0., 0., 1.);
    cylinder_z_direction.normalize();
    Eigen::Vector3d axis;
    axis = origin_z_direction.cross(cylinder_z_direction);
    axis.normalize();
    double angle = acos(cylinder_z_direction.dot(origin_z_direction));
    cylinder_pose.orientation.x = axis.x() * sin(angle/2);
    cylinder_pose.orientation.y = axis.y() * sin(angle/2);
    cylinder_pose.orientation.z = axis.z() * sin(angle/2);
    cylinder_pose.orientation.w = cos(angle/2);

    this -> getTransformation();
    tf2::doTransform(cylinder_pose, cylinder_pose, zed2pandaTransfo);
    skeleton.primitives.push_back(cylinder_primitive);
    skeleton.primitive_poses.push_back(cylinder_pose);
    skeleton.operation = skeleton.ADD;
}

void SkeletonTracker::addSphereCollisionObject(moveit_msgs::CollisionObject& skeleton, const Eigen::Matrix<double, 3, 1> &p, const double & r){
    moveit_msgs::CollisionObject sphere;

    shape_msgs::SolidPrimitive sphere_primitive;
    sphere_primitive.type = sphere_primitive.SPHERE;
    sphere_primitive.dimensions.resize(1);
    sphere_primitive.dimensions[0] = r;

    geometry_msgs::Pose sphere_pose;
    sphere_pose.position.x = p[0]; 
    sphere_pose.position.y = p[1];
    sphere_pose.position.z = p[2];

    sphere_pose.orientation.w = 1;

    this -> getTransformation();
    tf2::doTransform(sphere_pose, sphere_pose, zed2pandaTransfo);
    skeleton.primitives.push_back(sphere_primitive);
    skeleton.primitive_poses.push_back(sphere_pose);
    skeleton.operation = skeleton.ADD;
}


geometry_msgs::Pose SkeletonTracker::getJointPosition(int joint_id){
    geometry_msgs::Pose pose;
    pose.position.x = tracked_joints_pose[joint_id][0];
    pose.position.y = tracked_joints_pose[joint_id][1];
    pose.position.z = tracked_joints_pose[joint_id][2];
    this -> getTransformation();
    tf2::doTransform(pose, pose, zed2pandaTransfo);
    pose.orientation.x = 1;
    pose.orientation.y = 0;
    pose.orientation.z = 0;
    pose.orientation.w = 0;
    return pose;

}

void SkeletonTracker::addSkeletonCollisionObject(const zed_interfaces::Skeleton3D &skeleton_3d,std::vector<moveit_msgs::CollisionObject>& collision_objects, const std::string& id){

    std::vector<Eigen::Matrix<double, 3, 1>> points(18);
    double hand_radius = 0.07;
    for(int j=0; j<18; j++){
        //points[j] = Point3D(skeleton_3d.keypoints[j].kp[0], skeleton_3d.keypoints[j].kp[1], skeleton_3d.keypoints[j].kp[2]);
        points[j][0] = skeleton_3d.keypoints[j].kp[0];
        points[j][1] = skeleton_3d.keypoints[j].kp[1];
        points[j][2] = skeleton_3d.keypoints[j].kp[2];
    }

    if (id == tracked_id)
        tracked_joints_pose = points;

    if (!collision_avoidance)
        return;

    //ROS_INFO_STREAM("add skeleton: " << id);
    moveit_msgs::CollisionObject skeleton_collision;
    skeleton_collision.header.frame_id = target_frame;
    skeleton_collision.id = id + "_" + std::to_string(id_toggle);

    // head
    double r = (points[0]-points[1]).norm();
    addSphereCollisionObject(skeleton_collision, (points[16]+points[17])*0.5, r);

    // body
    addCylinderCollisionObject(skeleton_collision, points[1], (points[8]+points[11])*0.5, 0.15);

    // upper right arm
    addCylinderCollisionObject(skeleton_collision, points[2], points[3], 0.05);

    // lower right arm
    addCylinderCollisionObject(skeleton_collision, points[3], points[4], 0.05);

    // right hand
    Eigen::Matrix<double, 3, 1> p2;
    double inv_d2 = 1/((points[3]-points[4]).norm());
    p2 = points[4] + (points[4]-points[3])*inv_d2*hand_radius;
    // p2[0] = points[4][0] + (points[4][0]-points[3][0]).norm()*inv_d2*hand_radius;
    // p2[1] = points[4][1] + (points[4][1]-points[3][1]).norm()*inv_d2*hand_radius;
    // p2[2] = points[4][2] + (points[4][2]-points[3][2]).norm()*inv_d2*hand_radius;
    addSphereCollisionObject(skeleton_collision, p2, hand_radius);

    // upper left arm
    addCylinderCollisionObject(skeleton_collision, points[5], points[6], 0.05);

    // lower left arm
    addCylinderCollisionObject(skeleton_collision, points[6], points[7], 0.05);

    // left hand
    Eigen::Matrix<double, 3, 1> p1;
    double inv_d1 = 1/((points[6]-points[7]).norm());
    p1 = points[7] + (points[7]-points[6])*inv_d1*hand_radius;
    // p1.x = points[7].x + (points[7].x-points[6].x)*inv_d1*hand_radius;
    // p1.y = points[7].y + (points[7].y-points[6].y)*inv_d1*hand_radius;
    // p1.z = points[7].z + (points[7].z-points[6].z)*inv_d1*hand_radius;
    addSphereCollisionObject(skeleton_collision, p1, hand_radius);

    // upper right leg
    addCylinderCollisionObject(skeleton_collision, points[8], points[9], 0.1);

    //lower right leg
    addCylinderCollisionObject(skeleton_collision, points[9], points[10], 0.1);

    //upper left leg
    addCylinderCollisionObject(skeleton_collision, points[11], points[12], 0.1);

    //lower left leg
    addCylinderCollisionObject(skeleton_collision, points[12], points[13], 0.1);

    collision_object_ids.push_back(skeleton_collision.id);
    collision_objects.push_back(skeleton_collision);
    
}

void SkeletonTracker::trackAllSkeletons(const std::vector<zed_interfaces::Object> &objects, std::vector<moveit_msgs::CollisionObject>& collision_objects){
    collision_object_ids.clear();
    for(int i=0; i < objects.size();i++){
      zed_interfaces::Object obj = objects[i];
      if (!obj.skeleton_available)
         return;
      if (obj.label == "Person"){
         std::string skeleton_id = std::to_string(obj.label_id);
         addSkeletonCollisionObject(obj.skeleton_3d, collision_objects, skeleton_id);
         //ROS_INFO_STREAM(skeleton_id);
      }
   }
   id_toggle = !id_toggle;
}

void SkeletonTracker::setTrackedId(const std::string& id){
    tracked_id = id;
}