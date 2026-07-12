
#include "../include/sim/parallel_sim.hpp"


ParallelSim::ParallelSim() : Simbase("lockstep_sim")
{
    control_input_subscriber_ = this->create_subscription<control_framework_interfaces::msg::ControlInput>("control_input", 10,std::bind(&ParallelSim::control_input_callback, this, _1)); //Need custom msg
   
}  

void ParallelSim::control_input_callback(const control_framework_interfaces::msg::ControlInput & control_input)
{
    control_input_ = control_input;
}

vector<double> ParallelSim::control_input_calculate(const vector<double>& state)
{

    return control_input_.control_input;

}