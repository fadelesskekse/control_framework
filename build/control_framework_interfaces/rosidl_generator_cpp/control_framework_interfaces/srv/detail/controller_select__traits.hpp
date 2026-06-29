// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_framework_interfaces:srv/ControllerSelect.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__TRAITS_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_framework_interfaces/srv/detail/controller_select__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ControllerSelect_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: controller_name
  {
    out << "controller_name: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerSelect_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: controller_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "controller_name: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerSelect_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace control_framework_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_framework_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_framework_interfaces::srv::ControllerSelect_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::ControllerSelect_Request & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::ControllerSelect_Request>()
{
  return "control_framework_interfaces::srv::ControllerSelect_Request";
}

template<>
inline const char * name<control_framework_interfaces::srv::ControllerSelect_Request>()
{
  return "control_framework_interfaces/srv/ControllerSelect_Request";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ControllerSelect_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ControllerSelect_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::srv::ControllerSelect_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ControllerSelect_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerSelect_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerSelect_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace control_framework_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_framework_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_framework_interfaces::srv::ControllerSelect_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::ControllerSelect_Response & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::ControllerSelect_Response>()
{
  return "control_framework_interfaces::srv::ControllerSelect_Response";
}

template<>
inline const char * name<control_framework_interfaces::srv::ControllerSelect_Response>()
{
  return "control_framework_interfaces/srv/ControllerSelect_Response";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ControllerSelect_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ControllerSelect_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::srv::ControllerSelect_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<control_framework_interfaces::srv::ControllerSelect>()
{
  return "control_framework_interfaces::srv::ControllerSelect";
}

template<>
inline const char * name<control_framework_interfaces::srv::ControllerSelect>()
{
  return "control_framework_interfaces/srv/ControllerSelect";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ControllerSelect>
  : std::integral_constant<
    bool,
    has_fixed_size<control_framework_interfaces::srv::ControllerSelect_Request>::value &&
    has_fixed_size<control_framework_interfaces::srv::ControllerSelect_Response>::value
  >
{
};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ControllerSelect>
  : std::integral_constant<
    bool,
    has_bounded_size<control_framework_interfaces::srv::ControllerSelect_Request>::value &&
    has_bounded_size<control_framework_interfaces::srv::ControllerSelect_Response>::value
  >
{
};

template<>
struct is_service<control_framework_interfaces::srv::ControllerSelect>
  : std::true_type
{
};

template<>
struct is_service_request<control_framework_interfaces::srv::ControllerSelect_Request>
  : std::true_type
{
};

template<>
struct is_service_response<control_framework_interfaces::srv::ControllerSelect_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__TRAITS_HPP_
