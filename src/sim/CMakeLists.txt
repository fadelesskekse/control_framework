cmake_minimum_required(VERSION 3.8)
project(sim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter)

file(GLOB_RECURSE JOINT_FILTER_YAML_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/config/*/urdf_joint_ignore.yaml"
)

set(GENERATED_JOINT_FILTER_FILES)

foreach(yaml_file IN LISTS JOINT_FILTER_YAML_FILES)
    get_filename_component(
        model_directory
        "${yaml_file}"
        DIRECTORY
    )

    set(
        generated_header
        "${model_directory}/joint_filter_config.h"
    )

    set(
        generated_source
        "${model_directory}/joint_filter_config.c"
    )

    add_custom_command(
        OUTPUT
            "${generated_header}"
            "${generated_source}"
        COMMAND
            "${Python3_EXECUTABLE}"
            "${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate_joint_filter_config.py"
            --input "${yaml_file}"
            --output-dir "${model_directory}"
        DEPENDS
            "${yaml_file}"
            "${CMAKE_CURRENT_SOURCE_DIR}/scripts/generate_joint_filter_config.py"
        COMMENT
            "Generating joint filter from ${yaml_file}"
        VERBATIM
    )

    list(APPEND
        GENERATED_JOINT_FILTER_FILES
        "${generated_header}"
        "${generated_source}"
    )
endforeach()

add_custom_target(
    generate_joint_filter_configs ALL
    DEPENDS ${GENERATED_JOINT_FILTER_FILES}
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(control_framework_interfaces REQUIRED)
find_package(glfw3 REQUIRED)
find_package(std_srvs REQUIRED)
find_package(controller REQUIRED) #Gives the location of the controller library file and the library header files
 
find_library(MUJOCO_LIBRARY mujoco REQUIRED)


add_executable(lockstep_sim 
src/main_lockstep.cpp
src/lockstep_sim.cpp
src/sim.cpp
src/render.cpp)

add_executable(parallel_sim
src/main_parallel.cpp
src/parallel_sim.cpp
src/sim.cpp
src/render.cpp)


ament_target_dependencies(lockstep_sim 
rclcpp 
control_framework_interfaces
sensor_msgs
std_srvs
)

ament_target_dependencies(parallel_sim 
rclcpp 
control_framework_interfaces
sensor_msgs
std_srvs
)


#target_include_directories(lockstep_sim PRIVATE   #THIS IS WHAT FIND_PACKAGE() DOES FOR US
 # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../install/controller/include/> #THIS IS WHAT FIND_PACKAGE() DOES FOR US
 # $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../install/controller/include/> #THIS IS WHAT FIND_PACKAGE() DOES FOR US
#)



target_link_libraries(lockstep_sim

    ${MUJOCO_LIBRARY}
    glfw
    #${CMAKE_CURRENT_SOURCE_DIR}/../../install/controller/lib/libcontroller.a #THIS IS WHAT FIND_PACKAGE() DOES FOR US
    controller::controller
    #"${CMAKE_CURRENT_SOURCE_DIR}/../glfw/build/src/libglfw3.a"
)

target_link_libraries(parallel_sim

    ${MUJOCO_LIBRARY}
    glfw
    controller::controller
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
lockstep_sim parallel_sim
DESTINATION lib/${PROJECT_NAME}

)

install(DIRECTORY models
DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
