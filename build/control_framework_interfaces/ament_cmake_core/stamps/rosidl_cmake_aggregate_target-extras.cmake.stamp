# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target control_framework_interfaces::control_framework_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${control_framework_interfaces_TARGETS}.
if(control_framework_interfaces_TARGETS AND NOT TARGET control_framework_interfaces::control_framework_interfaces)
  add_library(control_framework_interfaces::control_framework_interfaces INTERFACE IMPORTED)
  set_target_properties(control_framework_interfaces::control_framework_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${control_framework_interfaces_TARGETS}")
endif()
