// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_framework_interfaces:srv/InitState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__BUILDER_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_framework_interfaces/srv/detail/init_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_InitState_Request_vel_init
{
public:
  explicit Init_InitState_Request_vel_init(::control_framework_interfaces::srv::InitState_Request & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::srv::InitState_Request vel_init(::control_framework_interfaces::srv::InitState_Request::_vel_init_type arg)
  {
    msg_.vel_init = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::InitState_Request msg_;
};

class Init_InitState_Request_pos_init
{
public:
  Init_InitState_Request_pos_init()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InitState_Request_vel_init pos_init(::control_framework_interfaces::srv::InitState_Request::_pos_init_type arg)
  {
    msg_.pos_init = std::move(arg);
    return Init_InitState_Request_vel_init(msg_);
  }

private:
  ::control_framework_interfaces::srv::InitState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::InitState_Request>()
{
  return control_framework_interfaces::srv::builder::Init_InitState_Request_pos_init();
}

}  // namespace control_framework_interfaces


namespace control_framework_interfaces
{

namespace srv
{

namespace builder
{

class Init_InitState_Response_message
{
public:
  explicit Init_InitState_Response_message(::control_framework_interfaces::srv::InitState_Response & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::srv::InitState_Response message(::control_framework_interfaces::srv::InitState_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::srv::InitState_Response msg_;
};

class Init_InitState_Response_success
{
public:
  Init_InitState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InitState_Response_message success(::control_framework_interfaces::srv::InitState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_InitState_Response_message(msg_);
  }

private:
  ::control_framework_interfaces::srv::InitState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::srv::InitState_Response>()
{
  return control_framework_interfaces::srv::builder::Init_InitState_Response_success();
}

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__BUILDER_HPP_
