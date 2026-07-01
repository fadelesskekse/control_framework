// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_framework_interfaces:msg/ControlInput.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__TRAITS_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_framework_interfaces/msg/detail/control_input__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_framework_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControlInput & msg,
  std::ostream & out)
{
  out << "{";
  // member: control_input
  {
    if (msg.control_input.size() == 0) {
      out << "control_input: []";
    } else {
      out << "control_input: [";
      size_t pending_items = msg.control_input.size();
      for (auto item : msg.control_input) {
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
  const ControlInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: control_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.control_input.size() == 0) {
      out << "control_input: []\n";
    } else {
      out << "control_input:\n";
      for (auto item : msg.control_input) {
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

inline std::string to_yaml(const ControlInput & msg, bool use_flow_style = false)
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
  const control_framework_interfaces::msg::ControlInput & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::msg::ControlInput & msg)
{
  return control_framework_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::msg::ControlInput>()
{
  return "control_framework_interfaces::msg::ControlInput";
}

template<>
inline const char * name<control_framework_interfaces::msg::ControlInput>()
{
  return "control_framework_interfaces/msg/ControlInput";
}

template<>
struct has_fixed_size<control_framework_interfaces::msg::ControlInput>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::msg::ControlInput>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::msg::ControlInput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__TRAITS_HPP_
