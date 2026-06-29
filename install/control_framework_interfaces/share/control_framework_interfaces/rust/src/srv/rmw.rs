#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__InitState_Request() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__InitState_Request__init(msg: *mut InitState_Request) -> bool;
    fn control_framework_interfaces__srv__InitState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InitState_Request>, size: usize) -> bool;
    fn control_framework_interfaces__srv__InitState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InitState_Request>);
    fn control_framework_interfaces__srv__InitState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InitState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<InitState_Request>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__InitState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_init: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_init: rosidl_runtime_rs::Sequence<f64>,

}



impl Default for InitState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__InitState_Request__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__InitState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InitState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InitState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InitState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/InitState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__InitState_Request() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__InitState_Response() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__InitState_Response__init(msg: *mut InitState_Response) -> bool;
    fn control_framework_interfaces__srv__InitState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<InitState_Response>, size: usize) -> bool;
    fn control_framework_interfaces__srv__InitState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<InitState_Response>);
    fn control_framework_interfaces__srv__InitState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<InitState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<InitState_Response>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__InitState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for InitState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__InitState_Response__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__InitState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for InitState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__InitState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for InitState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for InitState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/InitState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__InitState_Response() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ResetRecord_Request() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__ResetRecord_Request__init(msg: *mut ResetRecord_Request) -> bool;
    fn control_framework_interfaces__srv__ResetRecord_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Request>, size: usize) -> bool;
    fn control_framework_interfaces__srv__ResetRecord_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Request>);
    fn control_framework_interfaces__srv__ResetRecord_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ResetRecord_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Request>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__ResetRecord_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetRecord_Request {
    /// Allows us to pick which init_condition to reset to for the recording. 1 for default, 0 for custom
    pub use_default_init: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub record_time: f64,

}



impl Default for ResetRecord_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__ResetRecord_Request__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__ResetRecord_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ResetRecord_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ResetRecord_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ResetRecord_Request where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/ResetRecord_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ResetRecord_Request() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ResetRecord_Response() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__ResetRecord_Response__init(msg: *mut ResetRecord_Response) -> bool;
    fn control_framework_interfaces__srv__ResetRecord_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Response>, size: usize) -> bool;
    fn control_framework_interfaces__srv__ResetRecord_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Response>);
    fn control_framework_interfaces__srv__ResetRecord_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ResetRecord_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ResetRecord_Response>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__ResetRecord_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetRecord_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for ResetRecord_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__ResetRecord_Response__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__ResetRecord_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ResetRecord_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ResetRecord_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ResetRecord_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ResetRecord_Response where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/ResetRecord_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ResetRecord_Response() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ControllerSelect_Request() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__ControllerSelect_Request__init(msg: *mut ControllerSelect_Request) -> bool;
    fn control_framework_interfaces__srv__ControllerSelect_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Request>, size: usize) -> bool;
    fn control_framework_interfaces__srv__ControllerSelect_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Request>);
    fn control_framework_interfaces__srv__ControllerSelect_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ControllerSelect_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Request>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__ControllerSelect_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControllerSelect_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_name: rosidl_runtime_rs::String,

}



impl Default for ControllerSelect_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__ControllerSelect_Request__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__ControllerSelect_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ControllerSelect_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ControllerSelect_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ControllerSelect_Request where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/ControllerSelect_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ControllerSelect_Request() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ControllerSelect_Response() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__srv__ControllerSelect_Response__init(msg: *mut ControllerSelect_Response) -> bool;
    fn control_framework_interfaces__srv__ControllerSelect_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Response>, size: usize) -> bool;
    fn control_framework_interfaces__srv__ControllerSelect_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Response>);
    fn control_framework_interfaces__srv__ControllerSelect_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ControllerSelect_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ControllerSelect_Response>) -> bool;
}

// Corresponds to control_framework_interfaces__srv__ControllerSelect_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControllerSelect_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for ControllerSelect_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__srv__ControllerSelect_Response__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__srv__ControllerSelect_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ControllerSelect_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__srv__ControllerSelect_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ControllerSelect_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ControllerSelect_Response where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/srv/ControllerSelect_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__srv__ControllerSelect_Response() }
  }
}






#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__InitState() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__InitState
#[allow(missing_docs, non_camel_case_types)]
pub struct InitState;

impl rosidl_runtime_rs::Service for InitState {
    type Request = InitState_Request;
    type Response = InitState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__InitState() }
    }
}




#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ResetRecord() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__ResetRecord
#[allow(missing_docs, non_camel_case_types)]
pub struct ResetRecord;

impl rosidl_runtime_rs::Service for ResetRecord {
    type Request = ResetRecord_Request;
    type Response = ResetRecord_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ResetRecord() }
    }
}




#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ControllerSelect() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__ControllerSelect
#[allow(missing_docs, non_camel_case_types)]
pub struct ControllerSelect;

impl rosidl_runtime_rs::Service for ControllerSelect {
    type Request = ControllerSelect_Request;
    type Response = ControllerSelect_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ControllerSelect() }
    }
}


