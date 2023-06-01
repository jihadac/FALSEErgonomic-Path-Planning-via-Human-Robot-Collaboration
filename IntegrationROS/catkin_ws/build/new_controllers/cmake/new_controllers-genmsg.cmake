# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "new_controllers: 1 messages, 0 services")

set(MSG_I_FLAGS "-Inew_controllers:/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(new_controllers_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_custom_target(_new_controllers_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "new_controllers" "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(new_controllers
  "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/new_controllers
)

### Generating Services

### Generating Module File
_generate_module_cpp(new_controllers
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/new_controllers
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(new_controllers_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(new_controllers_generate_messages new_controllers_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_dependencies(new_controllers_generate_messages_cpp _new_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(new_controllers_gencpp)
add_dependencies(new_controllers_gencpp new_controllers_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS new_controllers_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(new_controllers
  "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/new_controllers
)

### Generating Services

### Generating Module File
_generate_module_eus(new_controllers
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/new_controllers
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(new_controllers_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(new_controllers_generate_messages new_controllers_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_dependencies(new_controllers_generate_messages_eus _new_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(new_controllers_geneus)
add_dependencies(new_controllers_geneus new_controllers_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS new_controllers_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(new_controllers
  "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/new_controllers
)

### Generating Services

### Generating Module File
_generate_module_lisp(new_controllers
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/new_controllers
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(new_controllers_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(new_controllers_generate_messages new_controllers_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_dependencies(new_controllers_generate_messages_lisp _new_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(new_controllers_genlisp)
add_dependencies(new_controllers_genlisp new_controllers_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS new_controllers_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(new_controllers
  "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/new_controllers
)

### Generating Services

### Generating Module File
_generate_module_nodejs(new_controllers
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/new_controllers
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(new_controllers_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(new_controllers_generate_messages new_controllers_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_dependencies(new_controllers_generate_messages_nodejs _new_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(new_controllers_gennodejs)
add_dependencies(new_controllers_gennodejs new_controllers_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS new_controllers_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(new_controllers
  "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/new_controllers
)

### Generating Services

### Generating Module File
_generate_module_py(new_controllers
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/new_controllers
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(new_controllers_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(new_controllers_generate_messages new_controllers_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mainuser/Documents/panda_brubotics_2021/franka_constrained_control/catkin_ws/src/new_controllers/msg/JointTorqueComparison.msg" NAME_WE)
add_dependencies(new_controllers_generate_messages_py _new_controllers_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(new_controllers_genpy)
add_dependencies(new_controllers_genpy new_controllers_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS new_controllers_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/new_controllers)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/new_controllers
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/new_controllers)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/new_controllers
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/new_controllers)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/new_controllers
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/new_controllers)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/new_controllers
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/new_controllers)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/new_controllers\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/new_controllers
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
