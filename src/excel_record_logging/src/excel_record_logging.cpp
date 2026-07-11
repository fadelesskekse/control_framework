#include "../include/excel_record_logging/excel_record_logging.hpp"

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

ExcelRecordLogging::ExcelRecordLogging() : 
Node("excel_record_logging"),
record_time(0.0),sim_start_log_time(0.0),sim_time_(0.0),raw_sim_time_(0.0),wrote_header_(false),recording(false)
{


    reset_record_service = this->create_service<control_framework_interfaces::srv::ResetRecord>("reset_record", std::bind(&ExcelRecordLogging::reset_record, this, _1, _2));
    state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states", 10, std::bind(&ExcelRecordLogging::joint_state_callback, this, _1)); //Need custom msg
    sim_time_subscriber_ = this->create_subscription<std_msgs::msg::Float64>("sim_time", 10,std::bind(&ExcelRecordLogging::sim_time_callback, this, _1)); //Need custom msg
    control_input_subscriber_ = this->create_subscription<control_framework_interfaces::msg::ControlInput>("control_input", 10,std::bind(&ExcelRecordLogging::control_input_callback, this, _1)); //Need custom msg
   

    log_timer_ = this->create_wall_timer(
      10ms, std::bind(&ExcelRecordLogging::log_callback, this));

    this->declare_parameter("model_name", "");
    this->declare_parameter<vector<string>>("urdf_joint_total", vector<string> {});
	this->declare_parameter<vector<string>>("urdf_joint_ignore", vector<string> {});
   

    urdf_joint_ignore_list = this->get_parameter("urdf_joint_ignore").as_string_array();
    urdf_joint_total_list = this->get_parameter("urdf_joint_total").as_string_array();
  


}

void ExcelRecordLogging::control_input_callback(const control_framework_interfaces::msg::ControlInput & control_input)
{
    control_input_ = control_input;
}



void ExcelRecordLogging::log_callback()
{


    if (!recording) {
        return;
    }
    
    if(sim_time_ < 0){ 
        return;
        //In the sim, once the reset record callback is finished, the sim_timer() will 
        //reset the sim and the time will go to 0. Don't start recording until this is actually 0. 
    }

    if (sim_time_ > record_time) {
        recording = false;

        if (log_file_.is_open()) {
            log_file_.flush();
            log_file_.close();
        }

        RCLCPP_INFO(
          this->get_logger(),
          "CSV File Has Been Closed. Recording Is Stopped"
        );

        return;
    }

    if (!log_file_.is_open()) {
        return;
    }

    if (!wrote_header_) {
        log_file_ << "sim_time";

        for (size_t i = 0; i < joint_state_.name.size(); ++i) {
            const std::string & joint_name = joint_state_.name[i];

            bool ignore_joint =
                std::find(
                    urdf_joint_ignore_list.begin(),
                    urdf_joint_ignore_list.end(),
                    joint_name
                ) != urdf_joint_ignore_list.end();

            if (ignore_joint) {
                continue;
            }

            log_file_ << "," << joint_name << "_position";
        }

        for (size_t i = 0; i < joint_state_.name.size(); ++i) {
            const std::string & joint_name = joint_state_.name[i];

            bool ignore_joint =
                std::find(
                    urdf_joint_ignore_list.begin(),
                    urdf_joint_ignore_list.end(),
                    joint_name
                ) != urdf_joint_ignore_list.end();

            if (ignore_joint) {
                continue;
            }

            log_file_ << "," << joint_name << "_velocity";
        }

        for (size_t i = 0; i < control_input_.control_input.size(); ++i) {
            log_file_ << ",control_input_" << i;
        }

        log_file_ << "\n";
        wrote_header_ = true;
    }

    log_file_ << std::fixed << std::setprecision(9) << sim_time_;

    for (size_t i = 0; i < joint_state_.position.size(); ++i) {
        if (i >= joint_state_.name.size()) {
            continue;
        }

        const std::string & joint_name = joint_state_.name[i];

        bool ignore_joint =
            std::find(
                urdf_joint_ignore_list.begin(),
                urdf_joint_ignore_list.end(),
                joint_name
            ) != urdf_joint_ignore_list.end();

        if (ignore_joint) {
            continue;
        }

        log_file_ << "," << joint_state_.position[i];
    }

    for (size_t i = 0; i < joint_state_.velocity.size(); ++i) {
        if (i >= joint_state_.name.size()) {
            continue;
        }

        const std::string & joint_name = joint_state_.name[i];

        bool ignore_joint =
            std::find(
                urdf_joint_ignore_list.begin(),
                urdf_joint_ignore_list.end(),
                joint_name
            ) != urdf_joint_ignore_list.end();

        if (ignore_joint) {
            continue;
        }

        log_file_ << "," << joint_state_.velocity[i];
    }

    for (size_t i = 0; i < control_input_.control_input.size(); ++i) {
    log_file_ << "," << control_input_.control_input[i];

       
    }

    log_file_ << "\n";


}

void ExcelRecordLogging::joint_state_callback(const sensor_msgs::msg::JointState joint_state)
{
    joint_state_ = joint_state;
}


void ExcelRecordLogging::sim_time_callback(const std_msgs::msg::Float64 & sim_time)
{
   // raw_sim_time_ = sim_time.data;
 //  sim_time_ = raw_sim_time_ - sim_start_log_time; //tared to be 0 at record start time. 
    sim_time_ = sim_time.data;
}



void ExcelRecordLogging::reset_record(const std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ResetRecord::Response> response)
{
    record_time = request->record_time;
    wrote_header_ = false;

    
    string package_prefix = ament_index_cpp::get_package_prefix("excel_record_logging");
    std::string model = this->get_parameter("model_name").as_string();



    std::string log_path =
    package_prefix + "/../../csv_data/" + model + "/excel_record_log.csv";

    RCLCPP_INFO(
    this->get_logger(),
    "model: %s, log_path: %s",
    model.c_str(),
    log_path.c_str()
    );

    log_file_.open(
        log_path,
        std::ios::out | std::ios::trunc
    );

    if (!log_file_.is_open()) {

        RCLCPP_WARN(
          this->get_logger(),
          "Failed to open CSV log file."
        );

        response->success = false;
        response->message = "Failed to open CSV log file";
        return;
    }

    recording = true;
    response->success = true;
    response->message = "Hit reset_record service callback in excel_logger. Starting to record";

    RCLCPP_INFO(
          this->get_logger(),
          "CSV File Opened. Recording has Begun."
        );

 


}


