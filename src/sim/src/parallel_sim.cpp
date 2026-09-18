
#include "../include/sim/parallel_sim.hpp"


ParallelSim::ParallelSim() : SimBase("parallel_sim",rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
{
    control_input_subscriber_ = this->create_subscription<control_framework_interfaces::msg::ControlInput>("control_input", 10,std::bind(&ParallelSim::control_input_callback, this, _1)); //Need custom msg
   // swap_controllers_service = this->create_service<control_framework_interfaces::srv::ControllerSelect>("controller_select", std::bind(&ParallelSim::controller_select, this, _1, _2));
      
}  


// void ParallelSim::controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
//           std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response)
// {
 
//     control_input_msg.control_input.assign(
//     static_cast<std::size_t>(m->nu),
//     0.0
//     );

//     control_input_.assign(
//         static_cast<std::size_t>(m->nu),
//         0.0
//     );
//     mj_resetDataKeyframe(m, d, default_init_pos_keyframe);
//     mj_forward(m, d);

//     response->success = true;
//     response->message = "Sim Reset to Default IC";
  
// }

void ParallelSim::timer_callback(){


    SimBase::sim_callback();
}

void ParallelSim::control_input_callback(const control_framework_interfaces::msg::ControlInput& control_input)
{

    if (control_input.control_input.size() !=
        static_cast<std::size_t>(m->nu))
    {
        RCLCPP_WARN(
            get_logger(),
            "Ignoring control input of size %zu; expected %d",
            control_input.control_input.size(),
            m->nu
        );
        return;
    }

    control_input_msg = control_input;

    if(!control_input_received_){
        control_input_received_ = true;
    }
}

vector<double> ParallelSim::control_input_calculate(const vector<double>& state)
{

    if (!control_input_received_) { //we return a zeroed but correct size vector for the mujoco control callback when we haven't received a control input
        return std::vector<double>(
            static_cast<std::size_t>(m->nu),
            0.0
        );
    }

    return control_input_msg.control_input;

}