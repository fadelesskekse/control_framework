// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_framework_interfaces:srv/InitState.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__srv__InitState_Request __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__srv__InitState_Request __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InitState_Request_
{
  using Type = InitState_Request_<ContainerAllocator>;

  explicit InitState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit InitState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _pos_init_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _pos_init_type pos_init;
  using _vel_init_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _vel_init_type vel_init;

  // setters for named parameter idiom
  Type & set__pos_init(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->pos_init = _arg;
    return *this;
  }
  Type & set__vel_init(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->vel_init = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__srv__InitState_Request
    std::shared_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__srv__InitState_Request
    std::shared_ptr<control_framework_interfaces::srv::InitState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InitState_Request_ & other) const
  {
    if (this->pos_init != other.pos_init) {
      return false;
    }
    if (this->vel_init != other.vel_init) {
      return false;
    }
    return true;
  }
  bool operator!=(const InitState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InitState_Request_

// alias to use template instance with default allocator
using InitState_Request =
  control_framework_interfaces::srv::InitState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_framework_interfaces


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__srv__InitState_Response __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__srv__InitState_Response __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct InitState_Response_
{
  using Type = InitState_Response_<ContainerAllocator>;

  explicit InitState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit InitState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__srv__InitState_Response
    std::shared_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__srv__InitState_Response
    std::shared_ptr<control_framework_interfaces::srv::InitState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InitState_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const InitState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InitState_Response_

// alias to use template instance with default allocator
using InitState_Response =
  control_framework_interfaces::srv::InitState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_framework_interfaces

namespace control_framework_interfaces
{

namespace srv
{

struct InitState
{
  using Request = control_framework_interfaces::srv::InitState_Request;
  using Response = control_framework_interfaces::srv::InitState_Response;
};

}  // namespace srv

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__INIT_STATE__STRUCT_HPP_
