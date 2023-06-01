# Install script for directory: /home/mainuser/Jihad/catkin_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mainuser/Jihad/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE PROGRAM FILES "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE PROGRAM FILES "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/setup.bash;/home/mainuser/Jihad/catkin_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE FILE FILES
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/setup.bash"
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/setup.sh;/home/mainuser/Jihad/catkin_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE FILE FILES
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/setup.sh"
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/setup.zsh;/home/mainuser/Jihad/catkin_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE FILE FILES
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mainuser/Jihad/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/mainuser/Jihad/catkin_ws/install" TYPE FILE FILES "/home/mainuser/Jihad/catkin_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mainuser/Jihad/catkin_ws/build/gtest/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_description/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_ros/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/iai_kinect2/iai_kinect2/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/panda_description/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/panda_moveit_config/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_msgs/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/algorithm/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/octomap_tools/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/panda_gazebo/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_gripper/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_visualization/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/iai_kinect2/kinect2_registration/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/ros_openpose/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/iai_kinect2/kinect2_bridge/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/iai_kinect2/kinect2_calibration/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/iai_kinect2/kinect2_viewer/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/panda_control/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/agni_tf_tools/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_hw/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_control/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_ros/franka_example_controllers/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/algorithm_panda_moveit/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/camera_integration/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/franka_planner_control/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/panda_moveit/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/zed-ros-example/zed_display_rviz/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/zed_interfaces/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/zed-ros-example/rviz-plugin-zed-od/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/zed_franka_planner/cmake_install.cmake")
  include("/home/mainuser/Jihad/catkin_ws/build/zed_saver/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/mainuser/Jihad/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
