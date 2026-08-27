#include "controller/control_logic.h"

control_logic_status_t lqr_controller_init(
    lqr_controller_t *controller,
    const double *gain_matrix,
    size_t gain_rows,
    size_t gain_columns
)
{
    if (controller == NULL || gain_matrix == NULL) {
        return CONTROL_LOGIC_NULL_POINTER;
    }

    if (gain_rows == 0 || gain_columns == 0) {
        return CONTROL_LOGIC_SIZE_MISMATCH;
    }

    controller->gain_matrix = gain_matrix;
    controller->gain_rows = gain_rows;
    controller->gain_columns = gain_columns;

    return CONTROL_LOGIC_OK;
}

control_logic_status_t lqr_controller_calculate(
    const lqr_controller_t *controller,
    const double *state,
    size_t state_length,
    double *control_output,
    size_t control_output_length
)
{
    if (
        controller == NULL ||
        state == NULL ||
        control_output == NULL
    ) {
        return CONTROL_LOGIC_NULL_POINTER;
    }

    if (controller->gain_matrix == NULL) {
        return CONTROL_LOGIC_NULL_POINTER;
    }

    if (
        state_length != controller->gain_columns ||
        control_output_length != controller->gain_rows
    ) {
        return CONTROL_LOGIC_SIZE_MISMATCH;
    }

    for (size_t row = 0; row < controller->gain_rows; ++row) {
        double value = 0.0;

        for (
            size_t column = 0;
            column < controller->gain_columns;
            ++column
        ) {
            size_t gain_index =
                row * controller->gain_columns + column;

            value +=
                controller->gain_matrix[gain_index] *
                state[column];
        }

        control_output[row] = -value;
    }

    return CONTROL_LOGIC_OK;
}