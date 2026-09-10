import re

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    ExecuteProcess,
    OpaqueFunction,
)
from launch.substitutions import LaunchConfiguration


def _split_topics(value):
    return [
        topic.strip()
        for topic in value.replace(";", ",").split(",")
        if topic.strip()
    ]


def _launch_setup(context, *args, **kwargs):
    topic_value = LaunchConfiguration(
        "topics"
    ).perform(context)

    window = LaunchConfiguration(
        "window"
    ).perform(context)

    priority_text = LaunchConfiguration(
        "realtime_priority"
    ).perform(context)

    topics = _split_topics(topic_value)
    priority = int(priority_text)

    if not topics:
        raise RuntimeError(
            "At least one topic must be provided"
        )

    if priority < 0 or priority > 99:
        raise RuntimeError(
            "realtime_priority must be from 0 through 99"
        )

    actions = []

    for topic in topics:
        command = [
            "ros2",
            "topic",
            "hz",
            topic,
            "-w",
            window,
            "--wall-time",
        ]

        if priority > 0:
            command = [
                "chrt",
                "-r",
                str(priority),
                *command,
            ]

        process_name = re.sub(
            r"[^A-Za-z0-9_]",
            "_",
            topic,
        ).strip("_")

        actions.append(
            ExecuteProcess(
                cmd=command,
                name=f"hz_{process_name}",
                output="screen",
                emulate_tty=True,
            )
        )

    return actions


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            "topics",
            default_value="/control_input",
        ),

        DeclareLaunchArgument(
            "window",
            default_value="100",
        ),

        # A value of zero disables real-time scheduling.
        DeclareLaunchArgument(
            "realtime_priority",
            default_value="0",
        ),

        OpaqueFunction(
            function=_launch_setup
        ),
    ])