import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription , OpaqueFunction
from launch.conditions import IfCondition
from launch.launch_description_sources import AnyLaunchDescriptionSource

def _launch_setup(context, *args, **kwargs):
    msg_n = int(LaunchConfiguration("msg_n").perform(context))

    foxglove_bridge_launch = os.path.join(
        get_package_share_directory("foxglove_bridge"),
        "launch",
        "foxglove_bridge_launch.xml",
    )

    return [
        Node(
            package="test_package",
            executable="test_node",
            name="test_node",
            output="screen",
            arguments=["--ros-args", "--log-level", "info"],
            parameters=[
                {
                    "msg_n": msg_n,
                }
            ]
        ),



        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(foxglove_bridge_launch),
        ),

        ExecuteProcess(
            cmd=[
                "foxglove-studio",
                "--ozone-platform=x11",
                "--disable-features=Vulkan",
                "--disable-accelerated-video-decode",
            ],
            additional_env={
                "__NV_PRIME_RENDER_OFFLOAD": "1",
                "__GLX_VENDOR_LIBRARY_NAME": "nvidia",
                "__VK_LAYER_NV_optimus": "NVIDIA_only",
                "VK_ICD_FILENAMES": "/usr/share/vulkan/icd.d/nvidia_icd.json",
            },
            name="foxglove_studio",
            output="screen",
        ),
            ]

def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("msg_n", default_value="1"),
            OpaqueFunction(function=_launch_setup),
        ]
    )