#ifndef BASE_CONTROLLER_HPP_
#define BASE_CONTROLLER_HPP_


    #include <vector>
    #include "rclcpp/rclcpp.hpp"
    #include <numeric>

    using namespace std;

    class BaseController{

        public:
            virtual vector<double> control_passthrough(const vector<double>& state_input) = 0;
         
        protected:
            BaseController(size_t gain_count);
            virtual ~BaseController() = default;
            vector<double> gains;
            
    };


#endif