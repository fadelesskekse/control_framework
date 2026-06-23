// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_framework_interfaces:srv/InitState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__TRAITS_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_framework_interfaces/srv/detail/init_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const InitState_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos_init
  {
    if (msg.pos_init.size() == 0) {
      out << "pos_init: []";
    } else {
      out << "pos_init: [";
      size_t pending_items = msg.pos_init.size();
      for (auto item : msg.pos_init) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: vel_init
  {
    if (msg.vel_init.size() == 0) {
      out << "vel_init: []";
    } else {
      out << "vel_init: [";
      size_t pending_items = msg.vel_init.size();
      for (auto item : msg.vel_init) {
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
  const InitState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos_init
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pos_init.size() == 0) {
      out << "pos_init: []\n";
    } else {
      out << "pos_init:\n";
      for (auto item : msg.pos_init) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: vel_init
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vel_init.size() == 0) {
      out << "vel_init: []\n";
    } else {
      out << "vel_init:\n";
      for (auto item : msg.vel_init) {
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

inline std::string to_yaml(const InitState_Request & msg, bool use_flow_style = false)
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
  const control_framework_interfaces::srv::InitState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::InitState_Request & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::InitState_Request>()
{
  return "control_framework_interfaces::srv::InitState_Request";
}

template<>
inline const char * name<control_framework_interfaces::srv::InitState_Request>()
{
  return "control_framework_interfaces/srv/InitState_Request";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::InitState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::InitState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::srv::InitState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace control_framework_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const InitState_Response & msg,
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
  const InitState_Response & msg,
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

inline std::string to_yaml(const InitState_Response & msg, bool use_flow_style = false)
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
  const control_framework_interfaces::srv::InitState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_framework_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_framework_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_framework_interfaces::srv::InitState_Response & msg)
{
  return control_framework_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_framework_interfaces::srv::InitState_Response>()
{
  return "control_framework_interfaces::srv::InitState_Response";
}

template<>
inline const char * name<control_framework_interfaces::srv::InitState_Response>()
{
  return "control_framework_interfaces/srv/InitState_Response";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::InitState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_framework_interfaces::srv::InitState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_framework_interfaces::srv::InitState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<control_framework_interfaces::srv::InitState>()
{
  return "control_framework_interfaces::srv::InitState";
}

template<>
inline const char * name<control_framework_interfaces::srv::InitState>()
{
  return "control_framework_interfaces/srv/InitState";
}

template<>
struct has_fixed_size<control_framework_interfaces::srv::InitState>
  : std::integral_constant<
    bool,
    has_fixed_size<control_framework_interfaces::srv::InitState_Request>::value &&
    has_fixed_size<control_framework_interfaces::srv::InitState_Response>::value
  >
{
};

template<>
struct has_bounded_size<control_framework_interfaces::srv::InitState>
  : std::integral_constant<
    bool,
    has_bounded_size<control_framework_interfaces::srv::InitState_Request>::value &&
    has_bounded_size<control_framework_interfaces::srv::InitState_Response>::value
  >
{
};

template<>
struct is_service<control_framework_interfaces::srv::InitState>
  : std::true_type
{
};

template<>
struct is_service_request<control_framework_interfaces::srv::InitState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<control_framework_interfaces::srv::InitState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__TRAITS_HPP_
