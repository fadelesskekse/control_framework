#include "../include/excel_record_logging/excel_record_logging.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  rclcpp::spin(std::make_shared<ExcelRecordLogging>());
  rclcpp::shutdown();
}