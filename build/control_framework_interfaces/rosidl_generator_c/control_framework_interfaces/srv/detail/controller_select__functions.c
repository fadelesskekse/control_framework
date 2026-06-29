// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control_framework_interfaces:srv/ControllerSelect.idl
// generated code does not contain a copyright notice
#include "control_framework_interfaces/srv/detail/controller_select__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `controller_name`
#include "rosidl_runtime_c/string_functions.h"

bool
control_framework_interfaces__srv__ControllerSelect_Request__init(control_framework_interfaces__srv__ControllerSelect_Request * msg)
{
  if (!msg) {
    return false;
  }
  // controller_name
  if (!rosidl_runtime_c__String__init(&msg->controller_name)) {
    control_framework_interfaces__srv__ControllerSelect_Request__fini(msg);
    return false;
  }
  return true;
}

void
control_framework_interfaces__srv__ControllerSelect_Request__fini(control_framework_interfaces__srv__ControllerSelect_Request * msg)
{
  if (!msg) {
    return;
  }
  // controller_name
  rosidl_runtime_c__String__fini(&msg->controller_name);
}

bool
control_framework_interfaces__srv__ControllerSelect_Request__are_equal(const control_framework_interfaces__srv__ControllerSelect_Request * lhs, const control_framework_interfaces__srv__ControllerSelect_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // controller_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->controller_name), &(rhs->controller_name)))
  {
    return false;
  }
  return true;
}

bool
control_framework_interfaces__srv__ControllerSelect_Request__copy(
  const control_framework_interfaces__srv__ControllerSelect_Request * input,
  control_framework_interfaces__srv__ControllerSelect_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // controller_name
  if (!rosidl_runtime_c__String__copy(
      &(input->controller_name), &(output->controller_name)))
  {
    return false;
  }
  return true;
}

control_framework_interfaces__srv__ControllerSelect_Request *
control_framework_interfaces__srv__ControllerSelect_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Request * msg = (control_framework_interfaces__srv__ControllerSelect_Request *)allocator.allocate(sizeof(control_framework_interfaces__srv__ControllerSelect_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_framework_interfaces__srv__ControllerSelect_Request));
  bool success = control_framework_interfaces__srv__ControllerSelect_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_framework_interfaces__srv__ControllerSelect_Request__destroy(control_framework_interfaces__srv__ControllerSelect_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_framework_interfaces__srv__ControllerSelect_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__init(control_framework_interfaces__srv__ControllerSelect_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Request * data = NULL;

  if (size) {
    data = (control_framework_interfaces__srv__ControllerSelect_Request *)allocator.zero_allocate(size, sizeof(control_framework_interfaces__srv__ControllerSelect_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_framework_interfaces__srv__ControllerSelect_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_framework_interfaces__srv__ControllerSelect_Request__fini(&data[i - 1]);
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
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__fini(control_framework_interfaces__srv__ControllerSelect_Request__Sequence * array)
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
      control_framework_interfaces__srv__ControllerSelect_Request__fini(&array->data[i]);
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

control_framework_interfaces__srv__ControllerSelect_Request__Sequence *
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Request__Sequence * array = (control_framework_interfaces__srv__ControllerSelect_Request__Sequence *)allocator.allocate(sizeof(control_framework_interfaces__srv__ControllerSelect_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_framework_interfaces__srv__ControllerSelect_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__destroy(control_framework_interfaces__srv__ControllerSelect_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_framework_interfaces__srv__ControllerSelect_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__are_equal(const control_framework_interfaces__srv__ControllerSelect_Request__Sequence * lhs, const control_framework_interfaces__srv__ControllerSelect_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_framework_interfaces__srv__ControllerSelect_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_framework_interfaces__srv__ControllerSelect_Request__Sequence__copy(
  const control_framework_interfaces__srv__ControllerSelect_Request__Sequence * input,
  control_framework_interfaces__srv__ControllerSelect_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_framework_interfaces__srv__ControllerSelect_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_framework_interfaces__srv__ControllerSelect_Request * data =
      (control_framework_interfaces__srv__ControllerSelect_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_framework_interfaces__srv__ControllerSelect_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_framework_interfaces__srv__ControllerSelect_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_framework_interfaces__srv__ControllerSelect_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
control_framework_interfaces__srv__ControllerSelect_Response__init(control_framework_interfaces__srv__ControllerSelect_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    control_framework_interfaces__srv__ControllerSelect_Response__fini(msg);
    return false;
  }
  return true;
}

void
control_framework_interfaces__srv__ControllerSelect_Response__fini(control_framework_interfaces__srv__ControllerSelect_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
control_framework_interfaces__srv__ControllerSelect_Response__are_equal(const control_framework_interfaces__srv__ControllerSelect_Response * lhs, const control_framework_interfaces__srv__ControllerSelect_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
control_framework_interfaces__srv__ControllerSelect_Response__copy(
  const control_framework_interfaces__srv__ControllerSelect_Response * input,
  control_framework_interfaces__srv__ControllerSelect_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

control_framework_interfaces__srv__ControllerSelect_Response *
control_framework_interfaces__srv__ControllerSelect_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Response * msg = (control_framework_interfaces__srv__ControllerSelect_Response *)allocator.allocate(sizeof(control_framework_interfaces__srv__ControllerSelect_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_framework_interfaces__srv__ControllerSelect_Response));
  bool success = control_framework_interfaces__srv__ControllerSelect_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_framework_interfaces__srv__ControllerSelect_Response__destroy(control_framework_interfaces__srv__ControllerSelect_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_framework_interfaces__srv__ControllerSelect_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__init(control_framework_interfaces__srv__ControllerSelect_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Response * data = NULL;

  if (size) {
    data = (control_framework_interfaces__srv__ControllerSelect_Response *)allocator.zero_allocate(size, sizeof(control_framework_interfaces__srv__ControllerSelect_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_framework_interfaces__srv__ControllerSelect_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_framework_interfaces__srv__ControllerSelect_Response__fini(&data[i - 1]);
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
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__fini(control_framework_interfaces__srv__ControllerSelect_Response__Sequence * array)
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
      control_framework_interfaces__srv__ControllerSelect_Response__fini(&array->data[i]);
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

control_framework_interfaces__srv__ControllerSelect_Response__Sequence *
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__ControllerSelect_Response__Sequence * array = (control_framework_interfaces__srv__ControllerSelect_Response__Sequence *)allocator.allocate(sizeof(control_framework_interfaces__srv__ControllerSelect_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_framework_interfaces__srv__ControllerSelect_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__destroy(control_framework_interfaces__srv__ControllerSelect_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_framework_interfaces__srv__ControllerSelect_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__are_equal(const control_framework_interfaces__srv__ControllerSelect_Response__Sequence * lhs, const control_framework_interfaces__srv__ControllerSelect_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_framework_interfaces__srv__ControllerSelect_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_framework_interfaces__srv__ControllerSelect_Response__Sequence__copy(
  const control_framework_interfaces__srv__ControllerSelect_Response__Sequence * input,
  control_framework_interfaces__srv__ControllerSelect_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_framework_interfaces__srv__ControllerSelect_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_framework_interfaces__srv__ControllerSelect_Response * data =
      (control_framework_interfaces__srv__ControllerSelect_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_framework_interfaces__srv__ControllerSelect_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_framework_interfaces__srv__ControllerSelect_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_framework_interfaces__srv__ControllerSelect_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
