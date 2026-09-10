#include "joint_filter_config.h"

const size_t
cart_pole_controlled_joint_indices[
    CART_POLE_CONTROLLED_JOINT_COUNT
] = {
    1U,
    2U
};

const char *const
cart_pole_controlled_joint_names[
    CART_POLE_CONTROLLED_JOINT_COUNT
] = {
    "cart_joint",
    "pole_joint"
};
