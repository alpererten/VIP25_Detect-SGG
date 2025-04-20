// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/detected_surface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msgs__msg__DetectedSurface__init(custom_msgs__msg__DetectedSurface * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    custom_msgs__msg__DetectedSurface__fini(msg);
    return false;
  }
  // normal
  // center
  // confidence
  return true;
}

void
custom_msgs__msg__DetectedSurface__fini(custom_msgs__msg__DetectedSurface * msg)
{
  if (!msg) {
    return;
  }
  // id
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // normal
  // center
  // confidence
}

bool
custom_msgs__msg__DetectedSurface__are_equal(const custom_msgs__msg__DetectedSurface * lhs, const custom_msgs__msg__DetectedSurface * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // normal
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->normal[i] != rhs->normal[i]) {
      return false;
    }
  }
  // center
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->center[i] != rhs->center[i]) {
      return false;
    }
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__DetectedSurface__copy(
  const custom_msgs__msg__DetectedSurface * input,
  custom_msgs__msg__DetectedSurface * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // normal
  for (size_t i = 0; i < 3; ++i) {
    output->normal[i] = input->normal[i];
  }
  // center
  for (size_t i = 0; i < 3; ++i) {
    output->center[i] = input->center[i];
  }
  // confidence
  output->confidence = input->confidence;
  return true;
}

custom_msgs__msg__DetectedSurface *
custom_msgs__msg__DetectedSurface__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__DetectedSurface * msg = (custom_msgs__msg__DetectedSurface *)allocator.allocate(sizeof(custom_msgs__msg__DetectedSurface), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__DetectedSurface));
  bool success = custom_msgs__msg__DetectedSurface__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__DetectedSurface__destroy(custom_msgs__msg__DetectedSurface * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__DetectedSurface__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__DetectedSurface__Sequence__init(custom_msgs__msg__DetectedSurface__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__DetectedSurface * data = NULL;

  if (size) {
    data = (custom_msgs__msg__DetectedSurface *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__DetectedSurface), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__DetectedSurface__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__DetectedSurface__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__DetectedSurface__Sequence__fini(custom_msgs__msg__DetectedSurface__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__DetectedSurface__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__DetectedSurface__Sequence *
custom_msgs__msg__DetectedSurface__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__DetectedSurface__Sequence * array = (custom_msgs__msg__DetectedSurface__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__DetectedSurface__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__DetectedSurface__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__DetectedSurface__Sequence__destroy(custom_msgs__msg__DetectedSurface__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__DetectedSurface__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__DetectedSurface__Sequence__are_equal(const custom_msgs__msg__DetectedSurface__Sequence * lhs, const custom_msgs__msg__DetectedSurface__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__DetectedSurface__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__DetectedSurface__Sequence__copy(
  const custom_msgs__msg__DetectedSurface__Sequence * input,
  custom_msgs__msg__DetectedSurface__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__DetectedSurface);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__DetectedSurface * data =
      (custom_msgs__msg__DetectedSurface *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__DetectedSurface__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__DetectedSurface__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__DetectedSurface__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
