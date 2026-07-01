// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from control_framework_interfaces:msg/ControlInput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "control_framework_interfaces/msg/detail/control_input__rosidl_typesupport_introspection_c.h"
#include "control_framework_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "control_framework_interfaces/msg/detail/control_input__functions.h"
#include "control_framework_interfaces/msg/detail/control_input__struct.h"


// Include directives for member types
// Member `control_input`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_framework_interfaces__msg__ControlInput__init(message_memory);
}

void control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_fini_function(void * message_memory)
{
  control_framework_interfaces__msg__ControlInput__fini(message_memory);
}

size_t control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__size_function__ControlInput__control_input(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_const_function__ControlInput__control_input(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_function__ControlInput__control_input(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__fetch_function__ControlInput__control_input(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_const_function__ControlInput__control_input(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__assign_function__ControlInput__control_input(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_function__ControlInput__control_input(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__resize_function__ControlInput__control_input(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_member_array[1] = {
  {
    "control_input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_framework_interfaces__msg__ControlInput, control_input),  // bytes offset in struct
    NULL,  // default value
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__size_function__ControlInput__control_input,  // size() function pointer
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_const_function__ControlInput__control_input,  // get_const(index) function pointer
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__get_function__ControlInput__control_input,  // get(index) function pointer
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__fetch_function__ControlInput__control_input,  // fetch(index, &value) function pointer
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__assign_function__ControlInput__control_input,  // assign(index, value) function pointer
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__resize_function__ControlInput__control_input  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_members = {
  "control_framework_interfaces__msg",  // message namespace
  "ControlInput",  // message name
  1,  // number of fields
  sizeof(control_framework_interfaces__msg__ControlInput),
  control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_member_array,  // message members
  control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_init_function,  // function to initialize message memory (memory has to be allocated)
  control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_type_support_handle = {
  0,
  &control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_framework_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_framework_interfaces, msg, ControlInput)() {
  if (!control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_type_support_handle.typesupport_identifier) {
    control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_framework_interfaces__msg__ControlInput__rosidl_typesupport_introspection_c__ControlInput_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
