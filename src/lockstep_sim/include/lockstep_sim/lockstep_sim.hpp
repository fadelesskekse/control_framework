#ifndef LOCKSTEP_SIM_NODE_HPP_
#define LOCKSTEP_SIM_NODE_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mujoco/mujoco.h"
#include "rclcpp/rclcpp.hpp"
#include "control_framework_interfaces/msg/state.hpp"
#include "control_framework_interfaces/msg/control_input.hpp"

#include "render.hpp"


class LockStepSim : public rclcpp::Node
{
    public:
        LockStepSim();
        virtual ~LockStepSim() = default;

    private:

        void sim_callback();

       

        mjModel* m = NULL;
        mjData* d= NULL;
       
        size_t count_;
        size_t render_frame_rate;
        rclcpp::TimerBase::SharedPtr sim_timer_;
        rclcpp::Publisher<control_framework_interfaces::msg::State>::SharedPtr state_publisher_;
        rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_publisher;
        
        //control_framework_interfaces::msg::State state_;
        //control_framework_interfaces::msg::ControlInput control_input_;
};
  

#endif
