// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_framework_interfaces:srv/ControllerSelect.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__STRUCT_H_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'controller_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ControllerSelect in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__ControllerSelect_Request
{
  rosidl_runtime_c__String controller_name;
} control_framework_interfaces__srv__ControllerSelect_Request;

// Struct for a sequence of control_framework_interfaces__srv__ControllerSelect_Request.
typedef struct control_framework_interfaces__srv__ControllerSelect_Request__Sequence
{
  control_framework_interfaces__srv__ControllerSelect_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__ControllerSelect_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ControllerSelect in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__ControllerSelect_Response
{
  bool success;
  rosidl_runtime_c__String message;
} control_framework_interfaces__srv__ControllerSelect_Response;

// Struct for a sequence of control_framework_interfaces__srv__ControllerSelect_Response.
typedef struct control_framework_interfaces__srv__ControllerSelect_Response__Sequence
{
  control_framework_interfaces__srv__ControllerSelect_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__ControllerSelect_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__STRUCT_H_
