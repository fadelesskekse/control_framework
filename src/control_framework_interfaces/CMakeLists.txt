cmake_minimum_required(VERSION 3.12)
project(control_framework_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

file(GLOB msg_files
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  CONFIGURE_DEPENDS
  "msg/*.msg"
)
list(SORT msg_files)

file(GLOB srv_files
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  CONFIGURE_DEPENDS
  "srv/*.srv"
)
list(SORT srv_files)

rosidl_generate_interfaces( ${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
)

function(camel_to_snake input output)
  string(REGEX REPLACE "(.)([A-Z][a-z]+)" "\\1_\\2" snake "${input}")
  string(REGEX REPLACE "([a-z0-9])([A-Z])" "\\1_\\2" snake "${snake}")
  string(TOLOWER "${snake}" snake)
  set(${output} "${snake}" PARENT_SCOPE)
endfunction()

function(make_interface_include_block interface_files interface_namespace output)
  set(include_block "")

  foreach(interface_file IN LISTS ${interface_files})
    get_filename_component(interface_name "${interface_file}" NAME_WE)
    camel_to_snake("${interface_name}" interface_header)
    string(APPEND include_block "#include \"${PROJECT_NAME}/${interface_namespace}/${interface_header}.hpp\"\n")
  endforeach()

  set(${output} "${include_block}" PARENT_SCOPE)
endfunction()

function(write_interface_umbrella_header header_name guard include_block)
  set(header_path "${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/${header_name}")

  file(WRITE "${header_path}"
"#ifndef ${guard}
#define ${guard}

${include_block}
#endif  // ${guard}
")
endfunction()

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}")

make_interface_include_block(msg_files "msg" msg_includes)
make_interface_include_block(srv_files "srv" srv_includes)
string(CONCAT all_includes
  "#include \"${PROJECT_NAME}/control_framework_interfaces_msg.hpp\"\n"
  "#include \"${PROJECT_NAME}/control_framework_interfaces_srv.hpp\"\n"
)

write_interface_umbrella_header(
  "control_framework_interfaces_msg.hpp"
  "CONTROL_FRAMEWORK_INTERFACES_MSG_HPP"
  "${msg_includes}"
)

write_interface_umbrella_header(
  "control_framework_interfaces_srv.hpp"
  "CONTROL_FRAMEWORK_INTERFACES_SRV_HPP"
  "${srv_includes}"
)

write_interface_umbrella_header(
  "control_framework_interfaces.hpp"
  "CONTROL_FRAMEWORK_INTERFACES_HPP"
  "${all_includes}"
)

install(
  DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/"
  DESTINATION "include/${PROJECT_NAME}"
)

ament_export_include_directories("include")

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
