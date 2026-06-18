// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_framework_interfaces:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_framework_interfaces/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_framework_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointState & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos_state
  {
    if (msg.pos_state.size() == 0) {
      out << "pos_state: []";
    } else {
      out << "pos_state: [";
      size_t pending_items = msg.pos_state.size();
      for (auto item : msg.pos_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: vel_state
  {
    if (msg.vel_state.size() == 0) {
      out << "vel_state: []";
    } else {
      out << "vel_state: [";
      size_t pending_items = msg.vel_state.size();
      for (auto item : msg.vel_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pos_state.size() == 0) {
      out << "pos_state: []\n";
    } else {
      out << "pos_state:\n";
      for (auto item : msg.pos_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: vel_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vel_state.size() == 0) {
      out << "vel_state: []\n";
    } else {
      out << "vel_state:\n";
      for (auto item : msg.vel_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace control_framework_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_framework_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_framework_interfaces::msg::JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::msg::JointState & msg)
{
  return control_framework_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::msg::JointState>()
{
  return "control_framework_interfaces::msg::JointState";
}

template<>
inline const char * name<control_framework_interfaces::msg::JointState>()
{
  return "control_framework_interfaces/msg/JointState";
}

template<>
struct has_fixed_size<control_framework_interfaces::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_framework_interfaces::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_framework_interfaces::msg::JointState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
