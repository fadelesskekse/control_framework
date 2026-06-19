
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

      state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10); //Need custom msg
      
     // control_input_publisher = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10); //Need custom msg
      
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
