#include "../include/sim/sim.hpp"

static Simbase* active_sim = nullptr;

static void control_callback(const mjModel* m, mjData* d)
{
  std::vector<double> state;

  for (int i=0; i < m->nq; i++){
    state.push_back(d->qpos[i]); //Controller derivation always needs the states in this order. 
    state.push_back(d->qvel[i]);
  }

  vector<double> control_input = active_sim->control_input_calculate(state);

  if (control_input.size() != m->nu){     
    throw std::invalid_argument("Control Input size as calculated from controller doesn't equal the number of actuators assigned in the mjcf model.");
  }

  for(int i = 0; i < m->nu; i++){
    d->ctrl[i] = control_input[i];
  }

}

SimBase::SimBase(const std::string& node_name) : Node(node_name)
{
    active_sim = this;

    this->declare_parameter("reset_and_record", false);
    this->declare_parameter("prev_reset_and_record", false);
    this->declare_parameter("use_default_init_for_reset_record", true);
    this->declare_parameter("record_time", 0.0);
	this->declare_parameter("model_name", "");


    //Create common pubs/subs/timers
    sim_timer_ = this->create_wall_timer(
    1ms, std::bind(&SimBase::sim_callback, this));

    state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10); //Need custom msg
    sim_time_publisher_ = this->create_publisher<std_msgs::msg::Float64>("sim_time", 10); //Need custom msg


    default_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_default_initial_position", std::bind(&LockStepSim::reset_to_default_initial_position, this, _1, _2));
    custom_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_custom_initial_position", std::bind(&LockStepSim::reset_to_custom_initial_position, this, _1, _2));
    change_custom_init_service = this->create_service<control_framework_interfaces::srv::InitState>("change_initial_position", std::bind(&LockStepSim::change_initial_position, this, _1, _2));
    reset_record_service = this->create_service<control_framework_interfaces::srv::ResetRecord>("reset_record", std::bind(&LockStepSim::reset_record, this, _1, _2));

    this->declare_parameter<vector<string>>("urdf_joint_total", vector<string> {});
    this->declare_parameter<vector<string>>("urdf_joint_type", vector<string> {});

    urdf_joint_total_list = this->get_parameter("urdf_joint_total").as_string_array();
    urdf_joint_type_list = this->get_parameter("urdf_joint_type").as_string_array();

    string model_name = this->get_parameter("model_name").as_string();


    //Load Model and Data
    std::string package_share = ament_index_cpp::get_package_share_directory("sim");
    //std::string model_path = package_share + "/models/cart_pole_mjcf.xml";
    std::string model_path = package_share + "/models/" + model_name + ".xml";
    
    char error[1000];

    m = mj_loadXML(model_path.c_str(), NULL, error, 1000);


    if (!m) {
        
        printf("%s\n", error);   
    }

    d = mj_makeData(m);

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

void SimBase::sim_callback(){

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

    sim_time.data = d->time;

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

    state_publisher_->publish(joint_state);
    sim_time_publisher_->publish(sim_time);

    glfw_render();

    //control_input_publisher_->publish(control_input);
}

void SimBase::glfw_render(){

    if (this->get_parameter("glfw_render").as_int() == 1) //render in the simulation loop. 
  {

    if (count_ % render_frame_rate == 0)
      {
        render::render_frame(); 
          
      }

    count_++;

  }

}

void SimBase::reset_to_custom_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
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

void SimBase::reset_to_default_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
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

void SimBase::change_initial_position(const std::shared_ptr<control_framework_interfaces::srv::InitState::Request> request,
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

void SimBase::reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
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