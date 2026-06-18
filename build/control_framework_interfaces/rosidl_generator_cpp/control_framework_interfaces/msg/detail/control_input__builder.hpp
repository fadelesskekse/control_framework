// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_framework_interfaces:msg/ControlInput.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__BUILDER_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_framework_interfaces/msg/detail/control_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_framework_interfaces
{

namespace msg
{

namespace builder
{

class Init_ControlInput_control_input
{
public:
  Init_ControlInput_control_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_framework_interfaces::msg::ControlInput control_input(::control_framework_interfaces::msg::ControlInput::_control_input_type arg)
  {
    msg_.control_input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_framework_interfaces::msg::ControlInput msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_framework_interfaces::msg::ControlInput>()
{
  return control_framework_interfaces::msg::builder::Init_ControlInput_control_input();
}

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__BUILDER_HPP_
