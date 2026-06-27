#ifndef CONTROLLERS_HPP_
#define CONTROLLERS_HPP_

#include "base_controller.hpp"


class LqrController : public BaseController
{
    public:
        LqrController(size_t gain_count_);

        vector<double> control_passthrough(const vector<double>& state_input) override;

    private:
        
        size_t lqr_gain_length;
        double* K_;
      
       //std::vector<double> Q(q_gains, q_gains + q_length);


};

#endif