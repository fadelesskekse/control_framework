// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_framework_interfaces:srv/ControllerSelect.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__BUILDER_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_framework_interfaces/srv/detail/controller_select__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControllerSelect_Request_controller_name
{
public:
  Init_ControllerSelect_Request_controller_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_framework_interfaces::srv::ControllerSelect_Request controller_name(::control_framework_interfaces::srv::ControllerSelect_Request::_controller_name_type arg)
  {
    msg_.controller_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::ControllerSelect_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::ControllerSelect_Request>()
{
  return control_framework_interfaces::srv::builder::Init_ControllerSelect_Request_controller_name();
}

}  // namespace control_framework_interfaces


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControllerSelect_Response_message
{
public:
  explicit Init_ControllerSelect_Response_message(::control_framework_interfaces::srv::ControllerSelect_Response & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::srv::ControllerSelect_Response message(::control_framework_interfaces::srv::ControllerSelect_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::ControllerSelect_Response msg_;
};

class Init_ControllerSelect_Response_success
{
public:
  Init_ControllerSelect_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControllerSelect_Response_message success(::control_framework_interfaces::srv::ControllerSelect_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ControllerSelect_Response_message(msg_);
  }

private:
  ::control_framework_interfaces::srv::ControllerSelect_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::ControllerSelect_Response>()
{
  return control_framework_interfaces::srv::builder::Init_ControllerSelect_Response_success();
}

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__CONTROLLER_SELECT__BUILDER_HPP_
