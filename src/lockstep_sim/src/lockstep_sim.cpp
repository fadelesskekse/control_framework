
#include <iostream>
#include "../include/lockstep_sim/lockstep_sim.hpp"
#include "../include/lockstep_sim/render.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

using namespace std::chrono_literals;

LockStepSim::LockStepSim() : Node("lockstep_sim")
{
      //Create pubs/subs
      sim_timer_ = this->create_wall_timer(
      1ms, std::bind(&LockStepSim::sim_callback, this));

      state_publisher_ = this->create_publisher<control_framework_interfaces::msg::JointState>("joint_states", 10); //Need custom msg
      control_input_publisher = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10); //Need custom msg
      
      //Load Model
      std::string package_share = ament_index_cpp::get_package_share_directory("lockstep_sim");
      std::string model_path = package_share + "/models/cart_pole_mjcf.xml";
      char error[1000];

      m = mj_loadXML(model_path.c_str(), NULL, error, 1000);

      if (!m) {
          
          printf("%s\n", error);   
      }

      d = mj_makeData(m);

      render::init(m,d);

      count_ = 0;
      render_frame_rate = 16; //1/60 fps ~ 16ms per frame


      
  

}

void LockStepSim::sim_callback()
{
  mj_step(m, d);

  auto state = control_framework_interfaces::msg::JointState();
 // auto control_input = control_framework_interfaces::msg::ControlInput();

  for(int i = 0; i < m->nq;i++){
    state.pos_state[i] = d->qpos[i];
  }

  for(int i = 0; i < m->nv;i++){
    state.vel_state[i] = d->qvel[i];
  }

  state_publisher_->publish(state);

  if (count_ % render_frame_rate == 0)
  {
    render::render_frame();
    
  }

  count_++;

}

