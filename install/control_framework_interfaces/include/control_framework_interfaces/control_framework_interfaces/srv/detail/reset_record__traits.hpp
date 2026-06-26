// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_framework_interfaces:srv/ResetRecord.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__TRAITS_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_framework_interfaces/srv/detail/reset_record__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetRecord_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: use_default_init
  {
    out << "use_default_init: ";
    rosidl_generator_traits::value_to_yaml(msg.use_default_init, out);
    out << ", ";
  }

  // member: record_time
  {
    out << "record_time: ";
    rosidl_generator_traits::value_to_yaml(msg.record_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetRecord_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: use_default_init
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_default_init: ";
    rosidl_generator_traits::value_to_yaml(msg.use_default_init, out);
    out << "\n";
  }

  // member: record_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "record_time: ";
    rosidl_generator_traits::value_to_yaml(msg.record_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetRecord_Request & msg, bool use_flow_style = false)
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
  const control_framework_interfaces::srv::ResetRecord_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::ResetRecord_Request & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::ResetRecord_Request>()
{
  return "control_framework_interfaces::srv::ResetRecord_Request";
}

template<>
inline const char * name<control_framework_interfaces::srv::ResetRecord_Request>()
{
  return "control_framework_interfaces/srv/ResetRecord_Request";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ResetRecord_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ResetRecord_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_framework_interfaces::srv::ResetRecord_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetRecord_Response & msg,
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
  const ResetRecord_Response & msg,
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

inline std::string to_yaml(const ResetRecord_Response & msg, bool use_flow_style = false)
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
  const control_framework_interfaces::srv::ResetRecord_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::ResetRecord_Response & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::ResetRecord_Response>()
{
  return "control_framework_interfaces::srv::ResetRecord_Response";
}

template<>
inline const char * name<control_framework_interfaces::srv::ResetRecord_Response>()
{
  return "control_framework_interfaces/srv/ResetRecord_Response";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ResetRecord_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ResetRecord_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::srv::ResetRecord_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<control_framework_interfaces::srv::ResetRecord>()
{
  return "control_framework_interfaces::srv::ResetRecord";
}

template<>
inline const char * name<control_framework_interfaces::srv::ResetRecord>()
{
  return "control_framework_interfaces/srv/ResetRecord";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::ResetRecord>
  : std::integral_constant<
    bool,
    has_fixed_size<control_framework_interfaces::srv::ResetRecord_Request>::value &&
    has_fixed_size<control_framework_interfaces::srv::ResetRecord_Response>::value
  >
{
};

template<>
struct has_bounded_size<control_framework_interfaces::srv::ResetRecord>
  : std::integral_constant<
    bool,
    has_bounded_size<control_framework_interfaces::srv::ResetRecord_Request>::value &&
    has_bounded_size<control_framework_interfaces::srv::ResetRecord_Response>::value
  >
{
};

template<>
struct is_service<control_framework_interfaces::srv::ResetRecord>
  : std::true_type
{
};

template<>
struct is_service_request<control_framework_interfaces::srv::ResetRecord_Request>
  : std::true_type
{
};

template<>
struct is_service_response<control_framework_interfaces::srv::ResetRecord_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__TRAITS_HPP_
