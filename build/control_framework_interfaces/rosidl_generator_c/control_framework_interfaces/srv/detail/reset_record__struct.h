// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_framework_interfaces:srv/ResetRecord.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_H_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetRecord in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__ResetRecord_Request
{
  /// Allows us to pick which init_condition to reset to for the recording. 1 for default, 0 for custom
  bool use_default_init;
  double record_time;
} control_framework_interfaces__srv__ResetRecord_Request;

// Struct for a sequence of control_framework_interfaces__srv__ResetRecord_Request.
typedef struct control_framework_interfaces__srv__ResetRecord_Request__Sequence
{
  control_framework_interfaces__srv__ResetRecord_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__ResetRecord_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResetRecord in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__ResetRecord_Response
{
  bool success;
  rosidl_runtime_c__String message;
} control_framework_interfaces__srv__ResetRecord_Response;

// Struct for a sequence of control_framework_interfaces__srv__ResetRecord_Response.
typedef struct control_framework_interfaces__srv__ResetRecord_Response__Sequence
{
  control_framework_interfaces__srv__ResetRecord_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__ResetRecord_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_H_
