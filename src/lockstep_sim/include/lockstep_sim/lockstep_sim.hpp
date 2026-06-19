#ifndef LOCKSTEP_SIM_NODE_HPP_
#define LOCKSTEP_SIM_NODE_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mujoco/mujoco.h"

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

//#include "tf2_ros/transform_broadcaster.h"
//#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

//#include "control_framework_interfaces/msg/joint_state.hpp"
//#include "control_framework_interfaces/msg/control_input.hpp"

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
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr state_publisher_;
  
       // rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_publisher;



};
  

#endif
