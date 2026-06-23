#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to control_framework_interfaces__srv__InitState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_init: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_init: Vec<f64>,

}



impl Default for InitState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::InitState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for InitState_Request {
  type RmwMsg = super::srv::rmw::InitState_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_init: msg.pos_init.into(),
        vel_init: msg.vel_init.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_init: msg.pos_init.as_slice().into(),
        vel_init: msg.vel_init.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pos_init: msg.pos_init
          .into_iter()
          .collect(),
      vel_init: msg.vel_init
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to control_framework_interfaces__srv__InitState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for InitState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::InitState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for InitState_Response {
  type RmwMsg = super::srv::rmw::InitState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
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


