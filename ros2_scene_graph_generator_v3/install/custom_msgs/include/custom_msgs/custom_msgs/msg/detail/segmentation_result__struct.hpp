// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/segmentation_result.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__SegmentationResult __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__SegmentationResult __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SegmentationResult_
{
  using Type = SegmentationResult_<ContainerAllocator>;

  explicit SegmentationResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0ll;
      this->class_name = "";
      this->x = 0.0;
      this->y = 0.0;
      this->width = 0.0;
      this->height = 0.0;
      this->depth = 0.0;
    }
  }

  explicit SegmentationResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0ll;
      this->class_name = "";
      this->x = 0.0;
      this->y = 0.0;
      this->width = 0.0;
      this->height = 0.0;
      this->depth = 0.0;
    }
  }

  // field types and members
  using _class_id_type =
    int64_t;
  _class_id_type class_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _width_type =
    double;
  _width_type width;
  using _height_type =
    double;
  _height_type height;
  using _depth_type =
    double;
  _depth_type depth;

  // setters for named parameter idiom
  Type & set__class_id(
    const int64_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__width(
    const double & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__depth(
    const double & _arg)
  {
    this->depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::SegmentationResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::SegmentationResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::SegmentationResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::SegmentationResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__SegmentationResult
    std::shared_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__SegmentationResult
    std::shared_ptr<custom_msgs::msg::SegmentationResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SegmentationResult_ & other) const
  {
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const SegmentationResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SegmentationResult_

// alias to use template instance with default allocator
using SegmentationResult =
  custom_msgs::msg::SegmentationResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_HPP_
