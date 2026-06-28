#ifndef BASE_CONTROLLER_HPP_
#define BASE_CONTROLLER_HPP_


    #include <vector>
    #include <numeric>

    using namespace std;

    class BaseController{

        public:
            virtual vector<double> control_passthrough(const vector<double>& state_input) = 0;
            virtual ~BaseController() = default;
         
        protected:
            BaseController(size_t gain_count);
            
            vector<double> gains;
            
    };


#endif