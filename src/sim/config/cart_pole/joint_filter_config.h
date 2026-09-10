#ifndef SIM_GENERATED_CART_POLE_JOINT_FILTER_CONFIG_H
#define SIM_GENERATED_CART_POLE_JOINT_FILTER_CONFIG_H

#include <stddef.h>

#define CART_POLE_TOTAL_JOINT_COUNT 4U
#define CART_POLE_CONTROLLED_JOINT_COUNT 2U

extern const size_t
    cart_pole_controlled_joint_indices[
        CART_POLE_CONTROLLED_JOINT_COUNT
    ];

extern const char *const
    cart_pole_controlled_joint_names[
        CART_POLE_CONTROLLED_JOINT_COUNT
    ];

#define JOINT_FILTER_TOTAL_JOINT_COUNT \
    CART_POLE_TOTAL_JOINT_COUNT

#define JOINT_FILTER_CONTROLLED_JOINT_COUNT \
    CART_POLE_CONTROLLED_JOINT_COUNT

#define JOINT_FILTER_CONTROLLED_JOINT_INDICES \
    cart_pole_controlled_joint_indices

#define JOINT_FILTER_CONTROLLED_JOINT_NAMES \
    cart_pole_controlled_joint_names

#endif
