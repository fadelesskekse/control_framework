// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_framework_interfaces:srv/ResetRecord.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_HPP_
#define CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__srv__ResetRecord_Request __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__srv__ResetRecord_Request __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetRecord_Request_
{
  using Type = ResetRecord_Request_<ContainerAllocator>;

  explicit ResetRecord_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->use_default_init = true;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->use_default_init = false;
      this->record_time = 0.0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->record_time = 0.0;
    }
  }

  explicit ResetRecord_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->use_default_init = true;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->use_default_init = false;
      this->record_time = 0.0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->record_time = 0.0;
    }
  }

  // field types and members
  using _use_default_init_type =
    bool;
  _use_default_init_type use_default_init;
  using _record_time_type =
    double;
  _record_time_type record_time;

  // setters for named parameter idiom
  Type & set__use_default_init(
    const bool & _arg)
  {
    this->use_default_init = _arg;
    return *this;
  }
  Type & set__record_time(
    const double & _arg)
  {
    this->record_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__srv__ResetRecord_Request
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__srv__ResetRecord_Request
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetRecord_Request_ & other) const
  {
    if (this->use_default_init != other.use_default_init) {
      return false;
    }
    if (this->record_time != other.record_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetRecord_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetRecord_Request_

// alias to use template instance with default allocator
using ResetRecord_Request =
  control_framework_interfaces::srv::ResetRecord_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_framework_interfaces


#ifndef _WIN32
# define DEPRECATED__control_framework_interfaces__srv__ResetRecord_Response __attribute__((deprecated))
#else
# define DEPRECATED__control_framework_interfaces__srv__ResetRecord_Response __declspec(deprecated)
#endif

namespace control_framework_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetRecord_Response_
{
  using Type = ResetRecord_Response_<ContainerAllocator>;

  explicit ResetRecord_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ResetRecord_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_framework_interfaces__srv__ResetRecord_Response
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_framework_interfaces__srv__ResetRecord_Response
    std::shared_ptr<control_framework_interfaces::srv::ResetRecord_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetRecord_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetRecord_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetRecord_Response_

// alias to use template instance with default allocator
using ResetRecord_Response =
  control_framework_interfaces::srv::ResetRecord_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_framework_interfaces

namespace control_framework_interfaces
{

namespace srv
{

struct ResetRecord
{
  using Request = control_framework_interfaces::srv::ResetRecord_Request;
  using Response = control_framework_interfaces::srv::ResetRecord_Response;
};

}  // namespace srv

}  // namespace control_framework_interfaces

#endif  // CONTROL_FRAMEWORK_INTERFACES__SRV__DETAIL__RESET_RECORD__STRUCT_HPP_
