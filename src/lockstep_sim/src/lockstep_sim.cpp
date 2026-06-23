
#include <iostream>
#include "../include/lockstep_sim/lockstep_sim.hpp"
#include "../include/lockstep_sim/render.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

LockStepSim::LockStepSim() : Node("lockstep_sim")
{
      //Create pubs/subs
      sim_timer_ = this->create_wall_timer(
      1ms, std::bind(&LockStepSim::sim_callback, this));

      state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10); //Need custom msg

      default_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_default_initial_position", std::bind(&LockStepSim::reset_to_default_initial_position, this, _1, _2));
      custom_init_set_service = this->create_service<std_srvs::srv::Trigger>("reset_to_custom_initial_position", std::bind(&LockStepSim::reset_to_custom_initial_position, this, _1, _2));
      change_custom_init_service = this->create_service<control_framework_interfaces::srv::InitState>("change_initial_position", std::bind(&LockStepSim::change_initial_position, this, _1, _2));
     // control_input_publisher = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10); //Need custom msg
      
      //Load Model and Data
      std::string package_share = ament_index_cpp::get_package_share_directory("lockstep_sim");
      std::string model_path = package_share + "/models/cart_pole_mjcf.xml";
      char error[1000];

  
      m = mj_loadXML(model_path.c_str(), NULL, error, 1000);
    

      if (!m) {
          
          printf("%s\n", error);   
      }

      d = mj_makeData(m);

      //Grab Initial Condition from model, and set model to those values
      default_init_pos_keyframe = mj_name2id(m, mjOBJ_KEY, "default_initial");
      custom_init_pos_keyframe = mj_name2id(m, mjOBJ_KEY, "custom_initial");

      if (default_init_pos_keyframe < 0 || custom_init_pos_keyframe < 0) {
          throw std::runtime_error("Could not find keyframe named 'default_initial'");
      }

      mj_resetDataKeyframe(m,d,default_init_pos_keyframe);
      mj_forward(m,d);

      // Set a ros parameter based on this initial keyframe that we can update via service call. 
      

      render::init(m,d);

      count_ = 0;
      render_frame_rate = 16; //1/60 fps ~ 16ms per frame


      
  

}

void LockStepSim::sim_callback()
{
  mj_step(m, d);

  sensor_msgs::msg::JointState joint_state;

  // Specify joints' name which are defined in the r2d2.urdf.xml and their content
  joint_state.name={"world_to_ground","cart_slide_joint","pole_hinge_joint","pole_to_tip_joint"};


  joint_state.position={0,d->qpos[0],d->qpos[1],d->qpos[1]};
  joint_state.velocity={0,d->qvel[0],d->qvel[1],d->qvel[1]};

  


  state_publisher_->publish(joint_state);

  //if (count_ % render_frame_rate == 0)
 // {
  //  render::render_frame();
    
 // }



  count_++;

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




