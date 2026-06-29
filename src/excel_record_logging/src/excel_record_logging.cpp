#include "../include/excel_record_logging/excel_record_logging.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

ExcelRecordLogging::ExcelRecordLogging() : Node("excel_record_logging"){

    reset_record_service = this->create_service<control_framework_interfaces::srv::ResetRecord>("reset_record", std::bind(&ExcelRecordLogging::reset_record, this, _1, _2));
    state_subscriber_ = this->create_subscriber<sensor_msgs::msg::JointState>("joint_states", 10); //Need custom msg
    sim_time_subscriber_ = this->create_subscriber<std_msgs::msg::Float64>("sim_time", 10); //Need custom msg

 
}

void ExcelRecordLogging::reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response)
{


}