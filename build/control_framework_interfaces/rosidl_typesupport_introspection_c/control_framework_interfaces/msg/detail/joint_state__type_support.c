// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from control_framework_interfaces:msg/JointState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "control_framework_interfaces/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"
#include "control_framework_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "control_framework_interfaces/msg/detail/joint_state__functions.h"
#include "control_framework_interfaces/msg/detail/joint_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_framework_interfaces__msg__JointState__init(message_memory);
}

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_fini_function(void * message_memory)
{
  control_framework_interfaces__msg__JointState__fini(message_memory);
}

size_t control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__pos_state(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__pos_state(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__pos_state(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__pos_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__pos_state(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__pos_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__pos_state(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__vel_state(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__vel_state(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__vel_state(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__vel_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__vel_state(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__vel_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__vel_state(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_member_array[2] = {
  {
    "pos_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(control_framework_interfaces__msg__JointState, pos_state),  // bytes offset in struct
    NULL,  // default value
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__pos_state,  // size() function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__pos_state,  // get_const(index) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__pos_state,  // get(index) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__pos_state,  // fetch(index, &value) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__pos_state,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(control_framework_interfaces__msg__JointState, vel_state),  // bytes offset in struct
    NULL,  // default value
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__vel_state,  // size() function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__vel_state,  // get_const(index) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__vel_state,  // get(index) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__vel_state,  // fetch(index, &value) function pointer
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__vel_state,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_members = {
  "control_framework_interfaces__msg",  // message namespace
  "JointState",  // message name
  2,  // number of fields
  sizeof(control_framework_interfaces__msg__JointState),
  control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_member_array,  // message members
  control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_init_function,  // function to initialize message memory (memory has to be allocated)
  control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle = {
  0,
  &control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_framework_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_framework_interfaces, msg, JointState)() {
  if (!control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle.typesupport_identifier) {
    control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_framework_interfaces__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
