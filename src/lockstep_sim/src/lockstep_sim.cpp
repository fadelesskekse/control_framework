
#include <iostream>
#include "../include/lockstep_sim/lockstep_sim.hpp"
#include "../include/lockstep_sim/render.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std;

static BaseController* active_controller = nullptr;

static void control_callback(const mjModel* m, mjData* d)
{
  std::vector<double> state;

  for (int i=0; i < m->nq; i++){
    state.push_back(d->qpos[i]); //Controller derivation always needs the states in this order. 
    state.push_back(d->qvel[i]);
  }

  vector<double> control_input = active_controller->control_passthrough(state);

  if (control_input.size() != m->nu){     
    throw std::invalid_argument("Control Input size as calculated from controller doesn't equal the number of actuators assigned in the mjcf model.");
  }

  for(int i = 0; i < m->nu; i++){
    d->ctrl[i] = control_input[i];
  }

}

LockStepSim::LockStepSim() : Node("lockstep_sim")
{
      //Create pubs/subs
      sim_timer_ = this->create_wall_timer(
      1ms, std::bind(&LockStepSim::sim_callback, this));

      state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", rclcpp::SensorDataQoS()); //Need custom msg
      sim_time_publisher_ = this->create_publisher<std_msgs::msg::Float64>("sim_time",rclcpp::SensorDataQoS()); //Need custom msg

      default_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_default_initial_position", std::bind(&LockStepSim::reset_to_default_initial_position, this, _1, _2));
      custom_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_custom_initial_position", std::bind(&LockStepSim::reset_to_custom_initial_position, this, _1, _2));
      change_custom_init_service = this->create_service<control_framework_interfaces::srv::InitState>("change_initial_position", std::bind(&LockStepSim::change_initial_position, this, _1, _2));
      reset_record_service = this->create_service<control_framework_interfaces::srv::ResetRecord>("reset_record", std::bind(&LockStepSim::reset_record, this, _1, _2));
      swap_controllers_service = this->create_service<control_framework_interfaces::srv::ControllerSelect>("controller_select", std::bind(&LockStepSim::controller_select, this, _1, _2));
      control_input_publisher_ = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", rclcpp::SensorDataQoS()); //Need custom msg
      
      this->declare_parameter("reset_and_record", false);
      this->declare_parameter("prev_reset_and_record", false);
      this->declare_parameter("use_default_init_for_reset_record", true);
      this->declare_parameter("record_time", 0.0);
	    this->declare_parameter("model_name", "cart_pole");

      this->declare_parameter<vector<string>>("urdf_joint_total", vector<string> {});
	    this->declare_parameter<vector<string>>("controller_list", vector<string> {"lqr"});
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



      string model_name = this->get_parameter("model_name").as_string();


      //Load Model and Data
      std::string package_share = ament_index_cpp::get_package_share_directory("lockstep_sim");
      //std::string model_path = package_share + "/models/cart_pole_mjcf.xml";
      std::string model_path = package_share + "/models/" + model_name + ".xml";
      
      char error[1000];

  
      m = mj_loadXML(model_path.c_str(), NULL, error, 1000);
    

      if (!m) {
          
          printf("%s\n", error);   
      }

      d = mj_makeData(m);

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

void LockStepSim::sim_callback()
{

  

  bool reset_and_record = this->get_parameter("reset_and_record").as_bool();
  bool prev_reset_and_record = this->get_parameter("prev_reset_and_record").as_bool();

  double start_sim_time;

  if(reset_and_record == true){
  
      if (prev_reset_and_record == false) //we just swapped to reset_and_record mode, so do the reset
      {
        mj_resetDataKeyframe(m,d,!this->get_parameter("use_default_init_for_reset_record").as_bool());
        mj_forward(m,d);

        start_sim_time = d->time;

        
        this->set_parameter(rclcpp::Parameter("prev_reset_and_record",true));//this parameter stops this if statement from executing more than once
      }

      

      else if( (d->time - start_sim_time) <= this->get_parameter("record_time").as_double() ){//If the tared current sim time is less than the record_duration, we execute in here
        mj_step(m, d);
      }
      else{
        
        this->set_parameter(rclcpp::Parameter("reset_and_record", false)); //exit the reset_and_record loop
        this->set_parameter(rclcpp::Parameter("prev_reset_and_record", false)); //exit the reset_and_record loop
        

      }
  }

  else{
    mj_step(m, d);
  }

  sensor_msgs::msg::JointState joint_state;
  std_msgs::msg::Float64 sim_time;
  control_framework_interfaces::msg::ControlInput control_input;

  int mujoco_joint_index = 0;

  for (size_t i = 0; i < urdf_joint_total_list.size(); ++i) {

    const std::string & urdf_joint = urdf_joint_total_list[i];
    const std::string & joint_type = urdf_joint_type_list[i];

    joint_state.name.push_back(urdf_joint);

    if (joint_type == "fixed") {
        if (i == 0) {
            joint_state.position.push_back(0.0);
            joint_state.velocity.push_back(0.0);
        } else {
            joint_state.position.push_back(joint_state.position.back());
            joint_state.velocity.push_back(joint_state.velocity.back());
        }
    } 

    else {
        joint_state.position.push_back(d->qpos[mujoco_joint_index]);
        joint_state.velocity.push_back(d->qvel[mujoco_joint_index]);

        mujoco_joint_index++;
    }

  }

  for(int i =0;i < m->nu; i++){
    control_input.control_input.push_back(d->ctrl[i]);
  }

  sim_time.data = d->time;



  state_publisher_->publish(joint_state);
  sim_time_publisher_->publish(sim_time);
  control_input_publisher_->publish(control_input);

  glfw_render();

}

void LockStepSim::glfw_render(){

    if (this->get_parameter("glfw_render").as_int() == 1) //render in the simulation loop. 
  {

    if (count_ % render_frame_rate == 0)
      {
        render::render_frame(); 
          
      }

    count_++;

  }

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

void LockStepSim::reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response)
{


  auto result = this->set_parameters_atomically({
    rclcpp::Parameter("use_default_init_for_reset_record", request->use_default_init),
    rclcpp::Parameter("record_time", request->record_time),
    rclcpp::Parameter("reset_and_record", true)
  });

  if (!result.successful) {
    response->success = false;
    response->message = "Failed to set reset-record parameters: " + result.reason;

    RCLCPP_WARN(
      this->get_logger(),
      "Failed to set reset-record parameters: %s",
      result.reason.c_str()
    );
  }
  else{
  response->success = true;
  response->message = "Successfully set which IC to reset to during recording, the duration of recording, and to start recording.";
  }

}


void LockStepSim::reset_to_default_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{

 // Set model position to intiial position parameter
  mj_resetDataKeyframe(m, d, default_init_pos_keyframe);
  mj_forward(m, d);

  response->success = 1;
  response->message = "Model Set to Initial Position";

  RCLCPP_INFO(
  rclcpp::get_logger("rclcpp"),
  "Resetting Model to Default Initial Position: [%d]",
  static_cast<int>(response->success)
);
}

void LockStepSim::reset_to_custom_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{

 // Set model position to intiial position parameter
  mj_resetDataKeyframe(m, d, custom_init_pos_keyframe);
  mj_forward(m, d);

  response->success = 1;
  response->message = "Model Set to Custom Initial Position";

  RCLCPP_INFO(
  rclcpp::get_logger("rclcpp"),
  "Resetting Model to Initial Position: [%d]",
  static_cast<int>(response->success)
);

}


void LockStepSim::change_initial_position(const std::shared_ptr<control_framework_interfaces::srv::InitState::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::InitState::Response> response)
{

    if (request->pos_init.size() != static_cast<size_t>(m->nq) ||
      request->vel_init.size() != static_cast<size_t>(m->nv))
  {
    response->success = false;
    response->message = "Expected pos_init size " + std::to_string(m->nq) +
                        " and vel_init size " + std::to_string(m->nv);
    return;
  }

  std::vector<double> pos_init = request->pos_init;
  std::vector<double> vel_init = request->vel_init;

   
  mjtNum* key_qpos = m->key_qpos + custom_init_pos_keyframe * m->nq;
  mjtNum* key_qvel = m->key_qvel + custom_init_pos_keyframe * m->nv;

    // Overwrite the stored keyframe values
  std::copy(pos_init.begin(), pos_init.end(), key_qpos);
  std::copy(vel_init.begin(), vel_init.end(), key_qvel);

  // Optional: reset the current live simulation to that newly edited keyframe
  mj_resetDataKeyframe(m, d, custom_init_pos_keyframe);

  // Recompute derived quantities after reset
  mj_forward(m, d);

  std::ostringstream pos_str;
  pos_str << "[";

  for (int i = 0; i < m->nq; ++i) {
      pos_str << std::fixed << std::setprecision(6) << key_qpos[i];

      if (i < m->nq - 1) {
          pos_str << ", ";
      }
  }

  pos_str << "]";

  RCLCPP_INFO(
      rclcpp::get_logger("rclcpp"),
      "Changed Init qpos: %s",
      pos_str.str().c_str()
  );

  std::ostringstream vel_str;
  vel_str << "[";

  for (int i = 0; i < m->nv; ++i) {
      vel_str << std::fixed << std::setprecision(6) << key_qvel[i];

      if (i < m->nv - 1) {
          vel_str << ", ";
      }
  }

  vel_str << "]";

  RCLCPP_INFO(
      rclcpp::get_logger("rclcpp"),
      "Changed Init qvel: %s",
      vel_str.str().c_str()
  );

  response->success = 1;

}


void LockStepSim::set_controllers(string controller_name){

    if (controller_name == "lqr") {

      this->declare_parameter<int64_t>("lqr_gain_row_num", 1);
      this->declare_parameter<int64_t>("lqr_gain_col_num", 4);
      this->declare_parameter<std::vector<double>>("lqr_K", std::vector<double>{-8.82,-13.24,65.9,12.0});


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

