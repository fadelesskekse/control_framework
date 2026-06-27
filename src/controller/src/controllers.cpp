#include "../include/controller/controllers.hpp"

LqrController::LqrController(size_t gain_count_)
:   BaseController(gain_count_),
    lqr_gain_length(gain_count_),
    K_(gains.data())
{}

vector<double> LqrController::control_passthrough(const vector<double>& state_input)
{
    vector<double> K(K_,K_ + lqr_gain_length);
    


}

