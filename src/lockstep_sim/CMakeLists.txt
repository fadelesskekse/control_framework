cmake_minimum_required(VERSION 3.8)
project(lockstep_sim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(control_framework_interfaces REQUIRED)
find_package(glfw3 REQUIRED)
find_package(std_srvs REQUIRED)


find_library(MUJOCO_LIBRARY mujoco REQUIRED)


add_executable(lockstep_sim 
src/main.cpp
src/lockstep_sim.cpp
src/render.cpp)


ament_target_dependencies(lockstep_sim 
rclcpp 
control_framework_interfaces
sensor_msgs
std_srvs
)

#target_include_directories(lockstep_sim
   # PRIVATE
  #  "/usr/local/include/mujoco"
    #"${CMAKE_CURRENT_SOURCE_DIR}/../../../mujoco-3.9.0/include/"
    #"../glfw/include/"
#)


target_link_libraries(lockstep_sim

    ${MUJOCO_LIBRARY}
    glfw
   
    #"${CMAKE_CURRENT_SOURCE_DIR}/../glfw/build/src/libglfw3.a"
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
lockstep_sim
DESTINATION lib/${PROJECT_NAME}

)

install(DIRECTORY models
DESTINATION share/${PROJECT_NAME}
)



ament_package()
