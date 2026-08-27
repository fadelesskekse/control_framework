#!/usr/bin/env python3

import argparse
import re
from pathlib import Path

import yaml


def c_identifier(value: str) -> str:
    identifier = re.sub(r"[^a-zA-Z0-9_]", "_", value)
    identifier = re.sub(r"_+", "_", identifier)
    return identifier.lower().strip("_")


def load_controller_parameters(
    yaml_path: Path,
    node_name: str,
) -> dict:
    with yaml_path.open("r", encoding="utf-8") as stream:
        document = yaml.safe_load(stream)

    if not document:
        raise ValueError(f"{yaml_path}: YAML file is empty")

    try:
        return document[node_name]["ros__parameters"]
    except (KeyError, TypeError) as error:
        raise ValueError(
            f"{yaml_path}: expected "
            f"'{node_name}.ros__parameters'"
        ) from error


def format_double(value) -> str:
    number = float(value)

    # Ensure C treats whole-valued gains as floating point.
    text = repr(number)

    if "." not in text and "e" not in text.lower():
        text += ".0"

    return text


def generate_files(
    yaml_path: Path,
    output_directory: Path,
    node_name: str,
) -> None:
    model_name = c_identifier(yaml_path.parent.name)
    controller_name = c_identifier(yaml_path.stem)

    parameters = load_controller_parameters(
        yaml_path,
        node_name,
    )

    row_key = f"{controller_name}_gain_row_num"
    column_key = f"{controller_name}_gain_col_num"
    matrix_key = f"{controller_name}_K"

    missing = [
        key
        for key in (row_key, column_key, matrix_key)
        if key not in parameters
    ]

    if missing:
        raise ValueError(
            f"{yaml_path}: missing parameters: "
            + ", ".join(missing)
        )

    rows = parameters[row_key]
    columns = parameters[column_key]
    gains = parameters[matrix_key]

    if not isinstance(rows, int) or rows <= 0:
        raise ValueError(
            f"{yaml_path}: {row_key} must be a positive integer"
        )

    if not isinstance(columns, int) or columns <= 0:
        raise ValueError(
            f"{yaml_path}: {column_key} must be a positive integer"
        )

    if not isinstance(gains, list):
        raise ValueError(
            f"{yaml_path}: {matrix_key} must be a YAML list"
        )

    expected_length = rows * columns

    if len(gains) != expected_length:
        raise ValueError(
            f"{yaml_path}: {matrix_key} has {len(gains)} values; "
            f"expected {rows} * {columns} = {expected_length}"
        )

    output_directory.mkdir(parents=True, exist_ok=True)

    header_path = output_directory / f"{controller_name}_config.h"
    source_path = output_directory / f"{controller_name}_config.c"

    symbol = f"{model_name}_{controller_name}"
    guard = (
        f"CONTROLLER_GENERATED_"
        f"{model_name}_{controller_name}_CONFIG_H"
    ).upper()

    gain_length = rows * columns

    header = f"""\
#ifndef {guard}
#define {guard}

#include <stddef.h>

#ifdef __cplusplus
extern "C" {{
#endif

extern const size_t {symbol}_gain_rows;
extern const size_t {symbol}_gain_columns;
extern const double {symbol}_gain_matrix[{gain_length}];

#ifdef __cplusplus
}}
#endif

#endif
"""

    formatted_gains = ",\n    ".join(
        format_double(gain)
        for gain in gains
    )

    source = f"""\
#include "{controller_name}_config.h"

const size_t {symbol}_gain_rows = {rows};
const size_t {symbol}_gain_columns = {columns};

const double {symbol}_gain_matrix[{gain_length}] = {{
    {formatted_gains}
}};
"""

    header_path.write_text(header, encoding="utf-8")
    source_path.write_text(source, encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True, type=Path)
    parser.add_argument("--output-dir", required=True, type=Path)
    parser.add_argument(
        "--node-name",
        default="controller_node",
    )
    arguments = parser.parse_args()

    generate_files(
        arguments.input,
        arguments.output_dir,
        arguments.node_name,
    )


if __name__ == "__main__":
    main()
