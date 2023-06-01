# Install script for directory: /home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/install")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers/msg" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers/cmake" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/new_controllers-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/include/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/share/roseus/ros/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/share/common-lisp/ros/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/share/gennodejs/ros/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/python2.7/dist-packages/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/python2.7/dist-packages/new_controllers")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/new_controllers" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/include/new_controllers/compliance_paramConfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/new_controllers" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/include/new_controllers/desired_mass_paramConfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/new_controllers" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/python2.7/dist-packages/new_controllers/__init__.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/python2.7/dist-packages/new_controllers/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/new_controllers" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/python2.7/dist-packages/new_controllers/cfg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/new_controllers.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers/cmake" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/new_controllers-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers/cmake" TYPE FILE FILES
    "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/new_controllersConfig.cmake"
    "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/new_controllersConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/libnew_controllers.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so"
         OLD_RPATH "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnew_controllers.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE EXECUTABLE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/new_controllers/move_group_interface_thomas")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas"
         OLD_RPATH "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_group_interface_thomas")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE EXECUTABLE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/new_controllers/path_planner_thomas")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas"
         OLD_RPATH "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/path_planner_thomas")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE EXECUTABLE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/new_controllers/move_to_lab_start")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start"
         OLD_RPATH "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/move_to_lab_start")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE EXECUTABLE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib/new_controllers/different_path_planners_test")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test"
         OLD_RPATH "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/devel/lib:/opt/ros/melodic/lib:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/libfranka/build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/new_controllers/different_path_planners_test")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers" TYPE DIRECTORY FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/new_controllers" TYPE FILE FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/new_controllers_plugin.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE PROGRAM FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/interactive_marker.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE PROGRAM FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/move_to_start.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/new_controllers" TYPE PROGRAM FILES "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/build/new_controllers/catkin_generated/installspace/move_to_lab_start.py")
endif()

