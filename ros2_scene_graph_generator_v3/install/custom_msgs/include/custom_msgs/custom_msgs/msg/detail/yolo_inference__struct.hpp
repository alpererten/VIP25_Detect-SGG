// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_inference.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'yolo_inference'
#include "custom_msgs/msg/detail/inference_result__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__YoloInference __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__YoloInference __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloInference_
{
  using Type = YoloInference_<ContainerAllocator>;

  explicit YoloInference_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit YoloInference_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _yolo_inference_type =
    std::vector<custom_msgs::msg::InferenceResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::InferenceResult_<ContainerAllocator>>>;
  _yolo_inference_type yolo_inference;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__yolo_inference(
    const std::vector<custom_msgs::msg::InferenceResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::InferenceResult_<ContainerAllocator>>> & _arg)
  {
    this->yolo_inference = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::YoloInference_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::YoloInference_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::YoloInference_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::YoloInference_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__YoloInference
    std::shared_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__YoloInference
    std::shared_ptr<custom_msgs::msg::YoloInference_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloInference_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->yolo_inference != other.yolo_inference) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloInference_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloInference_

// alias to use template instance with default allocator
using YoloInference =
  custom_msgs::msg::YoloInference_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_HPP_
