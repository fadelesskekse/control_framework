
#include "../include/sim/parallel_sim.hpp"


ParallelSim::ParallelSim() : SimBase("parallel_sim",rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
{
    control_input_subscriber_ = this->create_subscription<control_framework_interfaces::msg::ControlInput>("control_input", 10,std::bind(&ParallelSim::control_input_callback, this, _1)); //Need custom msg
   
}  

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