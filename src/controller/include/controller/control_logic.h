#ifndef CONTROLLER_CONTROL_LOGIC_H
#define CONTROLLER_CONTROL_LOGIC_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    CONTROL_LOGIC_OK = 0,
    CONTROL_LOGIC_NULL_POINTER,
    CONTROL_LOGIC_SIZE_MISMATCH
} control_logic_status_t;

typedef struct
{
    const double *gain_matrix;
    size_t gain_rows;
    size_t gain_columns;
} lqr_controller_t;

control_logic_status_t lqr_controller_init(
    lqr_controller_t *controller,
    const double *gain_matrix,
    size_t gain_rows,
    size_t gain_columns
);

control_logic_status_t lqr_controller_calculate(
    const lqr_controller_t *controller,
    const double *state,
    size_t state_length,
    double *control_output,
    size_t control_output_length
);

#ifdef __cplusplus
}
#endif

#endif