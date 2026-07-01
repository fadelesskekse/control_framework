// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_framework_interfaces:msg/ControlInput.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__STRUCT_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__msg__ControlInput __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__msg__ControlInput __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControlInput_
{
  using Type = ControlInput_<ContainerAllocator>;

  explicit ControlInput_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ControlInput_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _control_input_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _control_input_type control_input;

  // setters for named parameter idiom
  Type & set__control_input(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->control_input = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_framework_interfaces::msg::ControlInput_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::msg::ControlInput_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::msg::ControlInput_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::msg::ControlInput_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__msg__ControlInput
    std::shared_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__msg__ControlInput
    std::shared_ptr<control_framework_interfaces::msg::ControlInput_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlInput_ & other) const
  {
    if (this->control_input != other.control_input) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlInput_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlInput_

// alias to use template instance with default allocator
using ControlInput =
  control_framework_interfaces::msg::ControlInput_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__CONTROL_INPUT__STRUCT_HPP_
