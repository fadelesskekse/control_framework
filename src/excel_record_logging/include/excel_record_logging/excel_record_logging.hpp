#ifndef EXCEL_RECORD_LOGGER_NODE_HPP_
#define EXCEL_RECORD_LOGGER_NODE_HPP_

#include <fstream>
#include <iomanip>

#include "rclcpp/rclcpp.hpp"
#include "ament_index_cpp/get_package_prefix.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/float64.hpp"
#include "control_framework_interfaces/srv/reset_record.hpp"

using namespace std;

class ExcelRecordLogging : public rclcpp::Node
{
    public:
        ExcelRecordLogging();
        virtual ~ExcelRecordLogging() = default;

    private:


        void reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response);

        void joint_state_callback(const sensor_msgs::msg::JointState joint_state);
        void sim_time_callback(const std_msgs::msg::Float64 & sim_time);

        void log_callback();

        rclcpp::TimerBase::SharedPtr log_timer_;
        rclcpp::Service<control_framework_interfaces::srv::ResetRecord>::SharedPtr reset_record_service;
        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr state_subscriber_;
        rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr sim_time_subscriber_;

        vector<string> urdf_joint_ignore_list;
        vector<string> urdf_joint_total_list;
      
      

        std::ofstream log_file_;
        double record_time;
        double sim_start_log_time;
        double sim_time_;
        double raw_sim_time_;
        bool wrote_header_;
        sensor_msgs::msg::JointState joint_state_;
        bool recording;

};

#endif