cmake_minimum_required(VERSION 3.4)
project(franka_planner_control)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  controller_interface
  dynamic_reconfigure
  franka_hw
  geometry_msgs
  hardware_interface
  message_generation
  pluginlib
  realtime_tools
  roscpp
  rospy
  eigen_conversions
  tf
  tf_conversions
  tf2_ros
  tf2_eigen
  tf2_geometry_msgs
  visualization_msgs
  interactive_markers
  moveit_core
  moveit_visual_tools
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_ros_perception
  std_msgs
)

find_package(Eigen3 REQUIRED)
find_package(Franka 0.7.0 REQUIRED)
find_package(orocos_kdl)
find_package(kdl_parser)

add_message_files(FILES
  JointStates.msg
  HumanStates.msg
  DistanceToConstraints.msg
  TrajectoryPredictions.msg
  DSM.msg
  ComputationalTime.msg
  MoveItTime.msg
  JointTorqueComparison.msg
)

generate_messages(DEPENDENCIES geometry_msgs)

generate_dynamic_reconfigure_options(
  cfg/compliance_param.cfg
  cfg/desired_mass_param.cfg
)

catkin_package(
  LIBRARIES 
    franka_planner_control
  CATKIN_DEPENDS
    controller_interface
    dynamic_reconfigure
    franka_hw
    geometry_msgs
    hardware_interface
    message_runtime
    pluginlib
    realtime_tools
    roscpp
    eigen_conversions
    tf
    tf_conversions
    tf2_geometry_msgs
    moveit_core
    moveit_visual_tools
    moveit_ros_planning_interface
    interactive_markers
  DEPENDS 
    Franka
    EIGEN3
)

include_directories(
   include
   ${catkin_INCLUDE_DIRS}
)

add_library(franka_planner_control
  src/impedance_control_path_execute.cpp
  src/panda_model_controller.cpp
  src/selector_erg_static_move_controller.cpp
  src/erg_static_move_controller.cpp
  src/erg_dynamic_stay_controller.cpp
  src/selector_erg_dynamic_move_controller.cpp
  src/test_erg.cpp
  src/test_erg_selector.cpp
)
add_library(add_rviz_obstacles
  src/add_rviz_obstacles.cpp
)
add_library(explicit_reference_governor
  src/explicit_reference_governor.cpp
)


add_library(skeleton_tracker
  src/skeleton_tracker.cpp
)
add_library(erg_visualization
  src/erg_visualization.cpp
)

add_dependencies(franka_planner_control
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  ${PROJECT_NAME}_generate_messages_cpp
  ${PROJECT_NAME}_gencpp
  ${PROJECT_NAME}_gencfg
)

add_executable(moveit_static_move src/moveit_static_move.cpp)
add_executable(moveit_dynamic_move src/moveit_dynamic_move.cpp)
add_executable(moveit_static_grasp src/moveit_static_grasp.cpp)
add_executable(moveit_octomap_move src/moveit_octomap_move.cpp)
add_executable(moveit_octomap_grasp src/moveit_octomap_grasp.cpp)
add_executable(moveit_octomap_wrist_move src/moveit_octomap_wrist_move.cpp)
add_executable(planner_erg_static_move src/planner_erg_static_move.cpp)
add_executable(planner_erg_dynamic_move src/planner_erg_dynamic_move.cpp)
add_executable(test_send_plan src/test_send_plan.cpp)
add_executable(erg_visualization_test src/erg_visualization_test.cpp)
add_executable(moveit_color_detection_move1 src/moveit_color_detection_move.cpp)


target_link_libraries(franka_planner_control PUBLIC
  ${Franka_LIBRARIES}
  ${catkin_LIBRARIES}
  ${kdl_parser_LIBRARIES}
  ${orocos_kdl_LIBRARIES}
  armadillo
  lapack
  blas
  explicit_reference_governor
  erg_visualization
)

target_link_libraries(moveit_static_move ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles)
target_link_libraries(moveit_dynamic_move ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles)
target_link_libraries(moveit_static_grasp ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles)
target_link_libraries(moveit_octomap_move ${catkin_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(moveit_octomap_grasp ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles)
target_link_libraries(moveit_octomap_wrist_move ${catkin_LIBRARIES} ${Boost_LIBRARIES} skeleton_tracker add_rviz_obstacles)
target_link_libraries(planner_erg_static_move ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles explicit_reference_governor)
target_link_libraries(planner_erg_dynamic_move ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles explicit_reference_governor)
target_link_libraries(test_send_plan ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles explicit_reference_governor)
target_link_libraries(erg_visualization_test ${catkin_LIBRARIES} ${Boost_LIBRAIRIES} erg_visualization)
target_link_libraries(moveit_color_detection_move1 ${catkin_LIBRARIES} ${Boost_LIBRARIES} add_rviz_obstacles)

include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})

target_include_directories(franka_planner_control SYSTEM PUBLIC
  ${Franka_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)
target_include_directories(franka_planner_control PUBLIC
  include ${Boost_INCLUDE_DIR} ${EIGEN_INCLUDE_DIRS}
)

## Installation
install(TARGETS franka_planner_control
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(TARGETS moveit_static_move DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS moveit_dynamic_move DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS moveit_static_grasp DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS planner_erg_static_move DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS planner_erg_dynamic_move DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(TARGETS test_send_plan DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(FILES franka_planner_control_plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
catkin_install_python(
  PROGRAMS 
    scripts/interactive_marker.py 
    scripts/move_to_start.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Tools
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/ClangTools.cmake OPTIONAL
  RESULT_VARIABLE CLANG_TOOLS
)
if(CLANG_TOOLS)
  file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
  file(GLOB_RECURSE HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
  )
  add_format_target(franka_planner_control FILES ${SOURCES} ${HEADERS})
  add_tidy_target(franka_planner_control
    FILES ${SOURCES}
    DEPENDS franka_planner_control
  )
endif()
