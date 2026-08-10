#ifndef BASE_CONTROLLER_HPP_
#define BASE_CONTROLLER_HPP_


    #include <vector>
    #include <numeric>
    #include <string>
    #include <variant>
    

    using ControllerParamValue = std::variant<
    bool,
    int64_t,
    double,
    std::string,
    std::vector<int64_t>,
    std::vector<double>,
    std::vector<std::string>
    >;

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