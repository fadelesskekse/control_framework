// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_framework_interfaces:srv/InitState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_H_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos_init'
// Member 'vel_init'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/InitState in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__InitState_Request
{
  rosidl_runtime_c__double__Sequence pos_init;
  rosidl_runtime_c__double__Sequence vel_init;
} control_framework_interfaces__srv__InitState_Request;

// Struct for a sequence of control_framework_interfaces__srv__InitState_Request.
typedef struct control_framework_interfaces__srv__InitState_Request__Sequence
{
  control_framework_interfaces__srv__InitState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__InitState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/InitState in the package control_framework_interfaces.
typedef struct control_framework_interfaces__srv__InitState_Response
{
  bool success;
  rosidl_runtime_c__String message;
} control_framework_interfaces__srv__InitState_Response;

// Struct for a sequence of control_framework_interfaces__srv__InitState_Response.
typedef struct control_framework_interfaces__srv__InitState_Response__Sequence
{
  control_framework_interfaces__srv__InitState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__srv__InitState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_H_
