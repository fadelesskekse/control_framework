// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_framework_interfaces:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__msg__JointState __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__msg__JointState __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointState_
{
  using Type = JointState_<ContainerAllocator>;

  explicit JointState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->pos_state.begin(), this->pos_state.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->vel_state.begin(), this->vel_state.end(), 0.0f);
    }
  }

  explicit JointState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos_state(_alloc),
    vel_state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->pos_state.begin(), this->pos_state.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->vel_state.begin(), this->vel_state.end(), 0.0f);
    }
  }

  // field types and members
  using _pos_state_type =
    std::array<float, 2>;
  _pos_state_type pos_state;
  using _vel_state_type =
    std::array<float, 2>;
  _vel_state_type vel_state;

  // setters for named parameter idiom
  Type & set__pos_state(
    const std::array<float, 2> & _arg)
  {
    this->pos_state = _arg;
    return *this;
  }
  Type & set__vel_state(
    const std::array<float, 2> & _arg)
  {
    this->vel_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_framework_interfaces::msg::JointState_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::msg::JointState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::msg::JointState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::msg::JointState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__msg__JointState
    std::shared_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__msg__JointState
    std::shared_ptr<control_framework_interfaces::msg::JointState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointState_ & other) const
  {
    if (this->pos_state != other.pos_state) {
      return false;
    }
    if (this->vel_state != other.vel_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointState_

// alias to use template instance with default allocator
using JointState =
  control_framework_interfaces::msg::JointState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_
