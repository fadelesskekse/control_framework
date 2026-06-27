#include "../include/controller/controllers.hpp"

LqrController::LqrController(size_t lqr_gain_row_num_, size_t lqr_gain_col_num_)
:   BaseController(lqr_gain_row_num_ * lqr_gain_col_num_),
    lqr_gain_row_num(lqr_gain_row_num_),
    lqr_gain_col_num(lqr_gain_col_num_),
    lqr_gain_length(lqr_gain_row_num * lqr_gain_col_num),
    K_(gains.data())
{}

vector<double> LqrController::control_passthrough(const vector<double>& state)
{

    if (state_n != lqr_gain_col_num){
        RCLCPP_ERROR(
        this->get_logger(),
        "state_inputs size (%zu) does not match LQR gain columns (%d)",
        state_inputs.size(),
        lqr_gain_col_num
        );
    }

    vector<double> K_row;
    vector<double> control_input;
    
    for (int i = 0; i < lqr_gain_row_num;i++){
        K_row.assign(K_ + lqr_gain_col_num*(i), K_ + lqr_gain_col_num*(i+1));
        

        double u_i = std::inner_product(
            K_row.begin(),
            K_row.end(),
            state_inputs.begin(),
            0.0
        );

        control_input.push_back(-u_i);

    }

    return control_input;


}
