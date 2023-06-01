#include <franka/exception.h>
#include <franka/gripper.h>

int frankaGraspCube(){
    try{
        franka::Gripper gripper("192.168.2.106");
        double grasping_width = 0.05;
        
        franka::GripperState gripper_state = gripper.readOnce();
        if (gripper_state.max_width < grasping_width) {
            std::cout << "Object is too large for the current fingers on the gripper." << std::endl;
            return -1;
        }
        
        if (!gripper.grasp(grasping_width, 0.1, 70)) {
            std::cout << "Failed to grasp object." << std::endl;
            gripper.stop();
            return -1;
        }
        //ros::Duration(0.2).sleep();
        gripper_state = gripper.readOnce();
        if (!gripper_state.is_grasped) {
            std::cout << "Object lost." << std::endl;
            gripper.stop();
            return -1;
        }
    }
    catch (franka::Exception const& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
    return 0;
}

void frankaRelease(){
    franka::Gripper gripper("192.168.2.106");
    gripper.move(0.79,0.1);
    gripper.stop();
}
