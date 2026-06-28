#ifndef CONTROLLERS_HPP_
#define CONTROLLERS_HPP_

#include "base_controller.hpp"


class Lqr : public BaseController
{
    public:
        Lqr(size_t lqr_gain_row_num, size_t lqr_gain_col_num, vector<double> K);

        vector<double> control_passthrough(const vector<double>& state) override;

    private:
        
        size_t lqr_gain_row_num;
        size_t lqr_gain_col_num;
        size_t lqr_gain_length;

        double* K_;

      
       //std::vector<double> Q(q_gains, q_gains + q_length);


};

#endif