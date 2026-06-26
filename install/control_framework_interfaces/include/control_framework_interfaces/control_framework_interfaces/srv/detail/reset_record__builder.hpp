// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_framework_interfaces:srv/ResetRecord.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__BUILDER_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_framework_interfaces/srv/detail/reset_record__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResetRecord_Request_record_time
{
public:
  explicit Init_ResetRecord_Request_record_time(::control_framework_interfaces::srv::ResetRecord_Request & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::srv::ResetRecord_Request record_time(::control_framework_interfaces::srv::ResetRecord_Request::_record_time_type arg)
  {
    msg_.record_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::ResetRecord_Request msg_;
};

class Init_ResetRecord_Request_use_default_init
{
public:
  Init_ResetRecord_Request_use_default_init()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetRecord_Request_record_time use_default_init(::control_framework_interfaces::srv::ResetRecord_Request::_use_default_init_type arg)
  {
    msg_.use_default_init = std::move(arg);
    return Init_ResetRecord_Request_record_time(msg_);
  }

private:
  ::control_framework_interfaces::srv::ResetRecord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::ResetRecord_Request>()
{
  return control_framework_interfaces::srv::builder::Init_ResetRecord_Request_use_default_init();
}

}  // namespace control_framework_interfaces


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResetRecord_Response_message
{
public:
  explicit Init_ResetRecord_Response_message(::control_framework_interfaces::srv::ResetRecord_Response & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::srv::ResetRecord_Response message(::control_framework_interfaces::srv::ResetRecord_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::ResetRecord_Response msg_;
};

class Init_ResetRecord_Response_success
{
public:
  Init_ResetRecord_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetRecord_Response_message success(::control_framework_interfaces::srv::ResetRecord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ResetRecord_Response_message(msg_);
  }

private:
  ::control_framework_interfaces::srv::ResetRecord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::ResetRecord_Response>()
{
  return control_framework_interfaces::srv::builder::Init_ResetRecord_Response_success();
}

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__BUILDER_HPP_
