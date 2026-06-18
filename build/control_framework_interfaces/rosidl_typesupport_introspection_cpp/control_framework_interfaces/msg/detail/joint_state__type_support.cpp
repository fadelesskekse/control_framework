// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from control_framework_interfaces:msg/JointState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "control_framework_interfaces/msg/detail/joint_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace control_framework_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void JointState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) control_framework_interfaces::msg::JointState(_init);
}

void JointState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<control_framework_interfaces::msg::JointState *>(message_memory);
  typed_message->~JointState();
}

size_t size_function__JointState__pos_state(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__JointState__pos_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__JointState__pos_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__JointState__pos_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__JointState__pos_state(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__JointState__pos_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__JointState__pos_state(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__JointState__vel_state(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__JointState__vel_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__JointState__vel_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__JointState__vel_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__JointState__vel_state(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__JointState__vel_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__JointState__vel_state(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JointState_message_member_array[2] = {
  {
    "pos_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(control_framework_interfaces::msg::JointState, pos_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__JointState__pos_state,  // size() function pointer
    get_const_function__JointState__pos_state,  // get_const(index) function pointer
    get_function__JointState__pos_state,  // get(index) function pointer
    fetch_function__JointState__pos_state,  // fetch(index, &value) function pointer
    assign_function__JointState__pos_state,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vel_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(control_framework_interfaces::msg::JointState, vel_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__JointState__vel_state,  // size() function pointer
    get_const_function__JointState__vel_state,  // get_const(index) function pointer
    get_function__JointState__vel_state,  // get(index) function pointer
    fetch_function__JointState__vel_state,  // fetch(index, &value) function pointer
    assign_function__JointState__vel_state,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JointState_message_members = {
  "control_framework_interfaces::msg",  // message namespace
  "JointState",  // message name
  2,  // number of fields
  sizeof(control_framework_interfaces::msg::JointState),
  JointState_message_member_array,  // message members
  JointState_init_function,  // function to initialize message memory (memory has to be allocated)
  JointState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JointState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JointState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace control_framework_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<control_framework_interfaces::msg::JointState>()
{
  return &::control_framework_interfaces::msg::rosidl_typesupport_introspection_cpp::JointState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, control_framework_interfaces, msg, JointState)() {
  return &::control_framework_interfaces::msg::rosidl_typesupport_introspection_cpp::JointState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
