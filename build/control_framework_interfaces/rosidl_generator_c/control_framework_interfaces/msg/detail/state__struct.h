// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_framework_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/State in the package control_framework_interfaces.
typedef struct control_framework_interfaces__msg__State
{
  float pos_state[2];
  float vel_state[2];
} control_framework_interfaces__msg__State;

// Struct for a sequence of control_framework_interfaces__msg__State.
typedef struct control_framework_interfaces__msg__State__Sequence
{
  control_framework_interfaces__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_framework_interfaces__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
