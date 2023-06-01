# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/include;/usr/include/eigen3".split(';') if "${prefix}/include;/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/include;/usr/include/eigen3" != "" else []
PROJECT_CATKIN_DEPENDS = "controller_interface;dynamic_reconfigure;franka_hw;geometry_msgs;hardware_interface;message_runtime;pluginlib;realtime_tools;roscpp;eigen_conversions;tf;tf_conversions;tf2_geometry_msgs;moveit_core;moveit_visual_tools;moveit_ros_planning_interface;interactive_markers".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lfranka_planner;/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build/libfranka.so.0.7.1".split(';') if "-lfranka_planner;/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build/libfranka.so.0.7.1" != "" else []
PROJECT_NAME = "franka_planner"
PROJECT_SPACE_DIR = "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/install"
PROJECT_VERSION = "0.7.0"
