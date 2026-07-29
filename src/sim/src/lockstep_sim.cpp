
#include <iostream>
#include "../include/sim/lockstep_sim.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std;

static BaseController* active_controller = nullptr;


LockStepSim::LockStepSim() : SimBase("lockstep_sim")
{
     
    swap_controllers_service = this->create_service<control_framework_interfaces::srv::ControllerSelect>("controller_select", std::bind(&LockStepSim::controller_select, this, _1, _2));
      
    auto publishers = this->get_publishers_info_by_topic("/control_input"); //If we are in lockstep, there shouldn't exist another node publishing control as this sim should be publishign control

    if (!publishers.empty()) {
    RCLCPP_ERROR(
        this->get_logger(),
        "Another node is already publishing to /control_input. This node should not run at the same time."
    );

    throw std::runtime_error("Duplicate /control_input publisher detected");
    }

    else{
        control_input_publisher_ = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10); //Need custom msg;
    } 
      
      
      
      

      this->declare_parameter<vector<string>>("urdf_joint_total", vector<string> {});
	    this->declare_parameter<vector<string>>("controller_list", vector<string> {});
      this->declare_parameter<vector<string>>("urdf_joint_type", vector<string> {});

      


	    vector<string> controller_list = this->get_parameter("controller_list").as_string_array();

  
      urdf_joint_total_list = this->get_parameter("urdf_joint_total").as_string_array();
      urdf_joint_type_list = this->get_parameter("urdf_joint_type").as_string_array();

	    std::string controller_names;

      for (const auto& controller_name : controller_list) {

        if (!controller_names.empty()) {
            controller_names += ", ";
        }
        controller_names += controller_name;

        set_controllers(controller_name);

      }


      RCLCPP_WARN(
          this->get_logger(),
          "Controller list: [%s]",
          controller_names.c_str()
      );


      active_controller = controllers[0].get(); //set a default controller
      mjcb_control = control_callback;


      //Grab Initial Condition from model, and set model to those values
      default_init_pos_keyframe = mj_name2id(m, mjOBJ_KEY, "default_initial");
      custom_init_pos_keyframe = mj_name2id(m, mjOBJ_KEY, "custom_initial");

      if (default_init_pos_keyframe < 0 || custom_init_pos_keyframe < 0) {
          throw std::runtime_error("Could not find keyframe named 'default_initial'");
      }

      mj_resetDataKeyframe(m,d,default_init_pos_keyframe);
      mj_forward(m,d);

      // Set a ros parameter to choose whether to render using glfw or not. 
      this->declare_parameter("glfw_render", 0);
      int glfw_render = this->get_parameter("glfw_render").as_int();

      if (glfw_render == 1){
        render::init(m,d);
        count_ = 0;
        render_frame_rate = 16; //1/60 fps ~ 16ms per frame
      }
      
}

vector<double> LockStepSim::control_input_calculate(const vector<double>& state)
{
  return active_controller->control_passthrough(state);
}

void LockStepSim::controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response)
{
  string active_controller_name_request = request->controller_name;

  vector<string> controller_list = this->get_parameter("controller_list").as_string_array();


  for (size_t i = 0; i < controller_list.size(); i++) {

        if(active_controller_name_request == controller_list[i]){
          active_controller = controllers[i].get();

          response->success = true;
          response->message = "Controller changed to: " + active_controller_name_request;

          return;
        }

    }
    response->success = false;
    response->message = "Invalid Controller Requested, Controller Is not Changed";
    RCLCPP_WARN(
          this->get_logger(),
          "Not a valid Controller Requested, Controller Is not Changed"
        );

}
//
void LockStepSim::set_controllers(string controller_name){

    if (controller_name == "lqr") {

      this->declare_parameter<int64_t>("lqr_gain_row_num", 0);
      this->declare_parameter<int64_t>("lqr_gain_col_num", 0);
      this->declare_parameter<std::vector<double>>("lqr_K", std::vector<double>{});

      int lqr_gain_row_num =
          this->get_parameter("lqr_gain_row_num").as_int();

      int lqr_gain_col_num =
          this->get_parameter("lqr_gain_col_num").as_int();

      std::vector<double> lqr_K =
          this->get_parameter("lqr_K").as_double_array();

      controllers.push_back(std::make_unique<Lqr>(
           static_cast<std::size_t>(lqr_gain_row_num),
           static_cast<std::size_t>(lqr_gain_col_num),
          lqr_K
      ));

      RCLCPP_WARN(
          this->get_logger(),
          "Instantiated LQR controller"
      );

      RCLCPP_WARN(
          this->get_logger(),
          "LQR params: rows=%ld, cols=%ld",
          lqr_gain_row_num,
          lqr_gain_col_num
      );

      std::string lqr_K_string;

      for (const auto& gain : lqr_K) {
          if (!lqr_K_string.empty()) {
              lqr_K_string += ", ";
          }
          lqr_K_string += std::to_string(gain);
      }

            RCLCPP_WARN(
          this->get_logger(),
          "LQR K: [%s]",
          lqr_K_string.c_str()
      );


  }
  
  else if(controller_name == "test"){
      this->declare_parameter<int64_t>("test_gain_row_num", 0);
      this->declare_parameter<int64_t>("test_gain_col_num", 0);
      this->declare_parameter<std::vector<double>>("test_K", std::vector<double>{});

      int test_gain_row_num =
          this->get_parameter("test_gain_row_num").as_int();

      int test_gain_col_num =
          this->get_parameter("test_gain_col_num").as_int();

      std::vector<double> test_K =
          this->get_parameter("test_K").as_double_array();

      controllers.push_back(std::make_unique<Test>(
           static_cast<std::size_t>(test_gain_row_num),
           static_cast<std::size_t>(test_gain_col_num),
          test_K
      ));

      RCLCPP_WARN(
          this->get_logger(),
          "Instantiated test controller"
      );

      RCLCPP_WARN(
          this->get_logger(),
          "test params: rows=%ld, cols=%ld",
          test_gain_row_num,
          test_gain_col_num
      );

      std::string test_K_string;

      for (const auto& gain : test_K) {
          if (!test_K_string.empty()) {
              test_K_string += ", ";
          }
          test_K_string += std::to_string(gain);
      }

            RCLCPP_WARN(
          this->get_logger(),
          "test K: [%s]",
          test_K_string.c_str()
      );
  }
  
  else {
      RCLCPP_ERROR(
          this->get_logger(),
          "Unknown controller requested: %s",
          controller_name.c_str()
      );
  }

}

