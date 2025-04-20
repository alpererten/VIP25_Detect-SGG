// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surface.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__DetectedSurface __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__DetectedSurface __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedSurface_
{
  using Type = DetectedSurface_<ContainerAllocator>;

  explicit DetectedSurface_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->normal.begin(), this->normal.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->center.begin(), this->center.end(), 0.0);
      this->confidence = 0.0;
    }
  }

  explicit DetectedSurface_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    normal(_alloc),
    center(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->normal.begin(), this->normal.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->center.begin(), this->center.end(), 0.0);
      this->confidence = 0.0;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _normal_type =
    std::array<double, 3>;
  _normal_type normal;
  using _center_type =
    std::array<double, 3>;
  _center_type center;
  using _confidence_type =
    double;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__normal(
    const std::array<double, 3> & _arg)
  {
    this->normal = _arg;
    return *this;
  }
  Type & set__center(
    const std::array<double, 3> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::DetectedSurface_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::DetectedSurface_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DetectedSurface_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DetectedSurface_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__DetectedSurface
    std::shared_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__DetectedSurface
    std::shared_ptr<custom_msgs::msg::DetectedSurface_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedSurface_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->normal != other.normal) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedSurface_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedSurface_

// alias to use template instance with default allocator
using DetectedSurface =
  custom_msgs::msg::DetectedSurface_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_HPP_
