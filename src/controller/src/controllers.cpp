#include "../include/controller/controllers.hpp"

#include <stdexcept>

Lqr::Lqr(size_t lqr_gain_row_num_, size_t lqr_gain_col_num_, vector<double> K)
:   BaseController(lqr_gain_row_num_ * lqr_gain_col_num_),
    lqr_gain_row_num(lqr_gain_row_num_),
    lqr_gain_col_num(lqr_gain_col_num_),
    lqr_gain_length(lqr_gain_row_num * lqr_gain_col_num),
    K_(gains.data())
{
    gains = K;
    K_ = gains.data();
}

vector<double> Lqr::control_passthrough(const vector<double>& state)
{

   
    if (state.size() != lqr_gain_col_num){
        throw std::invalid_argument("state size does not match LQR gain column count");
    }

    vector<double> K_row;
    vector<double> control_input;
    
    for (size_t i = 0; i < lqr_gain_row_num;i++){
        K_row.assign(K_ + lqr_gain_col_num*(i), K_ + lqr_gain_col_num*(i+1));

        double u_i = inner_product(
            K_row.begin(),
            K_row.end(),
            state.begin(),
            0.0
        );

        control_input.push_back(-u_i);

    }
    
    return control_input;


}

Test::Test(size_t lqr_gain_row_num_, size_t lqr_gain_col_num_, vector<double> K)
:   BaseController(lqr_gain_row_num_ * lqr_gain_col_num_),
    lqr_gain_row_num(lqr_gain_row_num_),
    lqr_gain_col_num(lqr_gain_col_num_),
    lqr_gain_length(lqr_gain_row_num * lqr_gain_col_num),
    K_(gains.data())
{
    gains = K;
    K_ = gains.data();
}

vector<double> Test::control_passthrough(const vector<double>& state)
{

   
    if (state.size() != lqr_gain_col_num){
        throw std::invalid_argument("state size does not match LQR gain column count");
    }

    vector<double> K_row;
    vector<double> control_input;
    
    for (size_t i = 0; i < lqr_gain_row_num;i++){
        K_row.assign(K_ + lqr_gain_col_num*(i), K_ + lqr_gain_col_num*(i+1));

        double u_i = inner_product(
            K_row.begin(),
            K_row.end(),
            state.begin(),
            0.0
        );

        control_input.push_back(-u_i);

    }
    
    return control_input;


}