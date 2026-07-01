cmake_minimum_required(VERSION 3.8)
project(controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(control_framework_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)

add_library(controller 
src/base_controller.cpp
src/controllers.cpp
)

add_executable(controller_node
  src/main.cpp
  src/controller_node.cpp
)

target_link_libraries(controller_node
  controller
)

ament_target_dependencies(controller

control_framework_interfaces
sensor_msgs
rclcpp)


target_include_directories(controller PUBLIC
  $<INSTALL_INTERFACE:include> #Tells consumers of this library to look in install/controller/include for its header files
  #Used in find_package(controller) in lockstep_sim
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  )


install(DIRECTORY include/ #Copies this libraries header files into the install/controller/include. 
  DESTINATION include
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  TARGETS controller
  EXPORT controllerTargets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib)

install(
  TARGETS controller_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_export_targets(controllerTargets HAS_LIBRARY_TARGET)

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

ament_package()
