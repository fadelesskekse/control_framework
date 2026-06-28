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
#include "controller/controllers.hpp"

#include "std_msgs/msg/float64.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "control_framework_interfaces/srv/init_state.hpp"
#include "control_framework_interfaces/srv/reset_record.hpp"

//#include "control_framework_interfaces/msg/control_input.hpp"

#include "render.hpp"


class LockStepSim : public rclcpp::Node
{
    public:
        LockStepSim();
        virtual ~LockStepSim() = default;

    private:

        void sim_callback();

        void reset_to_default_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response);

        void reset_to_custom_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response);

        void change_initial_position(const std::shared_ptr<control_framework_interfaces::srv::InitState::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::InitState::Response> response);

        void reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response);

        void set_controllers(string controller_name);
	      std::vector<std::unique_ptr<BaseController>> controllers;

          

        mjModel* m = NULL;
        mjData* d= NULL;
       
        int default_init_pos_keyframe;
        int custom_init_pos_keyframe;

        size_t count_;
        size_t render_frame_rate;
        rclcpp::TimerBase::SharedPtr sim_timer_;
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr state_publisher_;
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr sim_time_publisher_;
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr default_init_set_service;
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr custom_init_set_service;
        rclcpp::Service<control_framework_interfaces::srv::InitState>::SharedPtr change_custom_init_service;
        rclcpp::Service<control_framework_interfaces::srv::ResetRecord>::SharedPtr reset_record_service;
  
       // rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_publisher;
  



};
  

#endif
