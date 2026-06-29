#ifndef EXCEL_RECORD_LOGGER_NODE_HPP_
#define EXCEL_RECORD_LOGGER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"

#include "control_framework_interfaces/srv/reset_record.hpp"

class ExcelRecordLogging : public rclcpp::Node
{
    public:
        ExcelRecordLogging();
        virtual ~ExcelRecordLogging() = default;

    private:

        void reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response);

        rclcpp::Service<control_framework_interfaces::srv::ResetRecord>::SharedPtr reset_record_service;
        rclcpp::Subscriber<sensor_msgs::msg::JointState>::SharedPtr state_subscriber_;
        rclcpp::Subscriber<std_msgs::msg::Float64>::SharedPtr sim_time_subscriber_;


};

#endif