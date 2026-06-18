// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_framework_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_framework_interfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_framework_interfaces
{

namespace msg
{

namespace builder
{

class Init_State_vel_state
{
public:
  explicit Init_State_vel_state(::control_framework_interfaces::msg::State & msg)
  : msg_(msg)
  {}
  ::control_framework_interfaces::msg::State vel_state(::control_framework_interfaces::msg::State::_vel_state_type arg)
  {
    msg_.vel_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::msg::State msg_;
};

class Init_State_pos_state
{
public:
  Init_State_pos_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_vel_state pos_state(::control_framework_interfaces::msg::State::_pos_state_type arg)
  {
    msg_.pos_state = std::move(arg);
    return Init_State_vel_state(msg_);
  }

private:
  ::control_framework_interfaces::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::msg::State>()
{
  return control_framework_interfaces::msg::builder::Init_State_pos_state();
}

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
