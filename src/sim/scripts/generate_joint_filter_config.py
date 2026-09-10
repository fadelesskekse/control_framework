#!/usr/bin/env python3

import argparse
import re
from pathlib import Path

import yaml


def c_identifier(value: str) -> str:
    identifier = re.sub(
        r"[^a-zA-Z0-9_]",
        "_",
        value,
    )
    identifier = re.sub(r"_+", "_", identifier)

    return identifier.lower().strip("_")


def c_string(value: str) -> str:
    escaped = value.replace("\\", "\\\\")
    escaped = escaped.replace('"', '\\"')

    return f'"{escaped}"'


def require_string_list(
    parameters: dict,
    parameter_name: str,
    yaml_path: Path,
) -> list[str]:
    if parameter_name not in parameters:
        raise ValueError(
            f"{yaml_path}: missing '{parameter_name}'"
        )

    values = parameters[parameter_name]

    if not isinstance(values, list):
        raise ValueError(
            f"{yaml_path}: '{parameter_name}' must be a list"
        )

    if not all(isinstance(value, str) for value in values):
        raise ValueError(
            f"{yaml_path}: '{parameter_name}' must contain strings"
        )

    return values


def generate_joint_filter(
    yaml_path: Path,
    output_directory: Path,
) -> None:
    with yaml_path.open("r", encoding="utf-8") as stream:
        document = yaml.safe_load(stream)

    if not document:
        raise ValueError(f"{yaml_path}: YAML file is empty")

    try:
        sim_parameters = document["sim"]["ros__parameters"]
        controller_parameters = (
            document["controller_node"]["ros__parameters"]
        )
    except (KeyError, TypeError) as error:
        raise ValueError(
            f"{yaml_path}: expected sim and controller_node "
            "ROS parameter sections"
        ) from error

    total_joints = require_string_list(
        sim_parameters,
        "urdf_joint_total",
        yaml_path,
    )

    ignored_joints = require_string_list(
        controller_parameters,
        "urdf_joint_ignore",
        yaml_path,
    )

    if len(total_joints) != len(set(total_joints)):
        raise ValueError(
            f"{yaml_path}: urdf_joint_total contains duplicates"
        )

    unknown_ignored_joints = [
        name
        for name in ignored_joints
        if name not in total_joints
    ]

    if unknown_ignored_joints:
        raise ValueError(
            f"{yaml_path}: ignored joints not present in "
            f"urdf_joint_total: {unknown_ignored_joints}"
        )

    ignored_set = set(ignored_joints)

    controlled_joints = [
        (index, name)
        for index, name in enumerate(total_joints)
        if name not in ignored_set
    ]

    if not controlled_joints:
        raise ValueError(
            f"{yaml_path}: every joint is ignored"
        )

    model_name = c_identifier(yaml_path.parent.name)
    model_upper = model_name.upper()

    controlled_indices = [
        index
        for index, _ in controlled_joints
    ]

    controlled_names = [
        name
        for _, name in controlled_joints
    ]

    output_directory.mkdir(
        parents=True,
        exist_ok=True,
    )

    header_path = (
        output_directory / "joint_filter_config.h"
    )

    source_path = (
        output_directory / "joint_filter_config.c"
    )

    guard = (
        f"SIM_GENERATED_{model_upper}_"
        "JOINT_FILTER_CONFIG_H"
    )

    header = f"""\
#ifndef {guard}
#define {guard}

#include <stddef.h>

#define {model_upper}_TOTAL_JOINT_COUNT {len(total_joints)}U
#define {model_upper}_CONTROLLED_JOINT_COUNT {len(controlled_joints)}U

extern const size_t
    {model_name}_controlled_joint_indices[
        {model_upper}_CONTROLLED_JOINT_COUNT
    ];

extern const char *const
    {model_name}_controlled_joint_names[
        {model_upper}_CONTROLLED_JOINT_COUNT
    ];

#define JOINT_FILTER_TOTAL_JOINT_COUNT \\
    {model_upper}_TOTAL_JOINT_COUNT

#define JOINT_FILTER_CONTROLLED_JOINT_COUNT \\
    {model_upper}_CONTROLLED_JOINT_COUNT

#define JOINT_FILTER_CONTROLLED_JOINT_INDICES \\
    {model_name}_controlled_joint_indices

#define JOINT_FILTER_CONTROLLED_JOINT_NAMES \\
    {model_name}_controlled_joint_names

#endif
"""

    indices_text = ",\n    ".join(
        f"{index}U"
        for index in controlled_indices
    )

    names_text = ",\n    ".join(
        c_string(name)
        for name in controlled_names
    )

    source = f"""\
#include "joint_filter_config.h"

const size_t
{model_name}_controlled_joint_indices[
    {model_upper}_CONTROLLED_JOINT_COUNT
] = {{
    {indices_text}
}};

const char *const
{model_name}_controlled_joint_names[
    {model_upper}_CONTROLLED_JOINT_COUNT
] = {{
    {names_text}
}};
"""

    header_path.write_text(
        header,
        encoding="utf-8",
    )

    source_path.write_text(
        source,
        encoding="utf-8",
    )


def main() -> None:
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "--input",
        required=True,
        type=Path,
    )

    parser.add_argument(
        "--output-dir",
        required=True,
        type=Path,
    )

    arguments = parser.parse_args()

    generate_joint_filter(
        arguments.input,
        arguments.output_dir,
    )


if __name__ == "__main__":
    main()