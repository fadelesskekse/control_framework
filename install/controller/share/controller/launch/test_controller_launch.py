import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _split_controller_list(controller_list):
    return [
        controller.strip()
        for controller in controller_list.replace(";", ",").split(",")
        if controller.strip()
    ]


def _launch_setup(context, *args, **kwargs):
    model = LaunchConfiguration("model").perform(context)
    controller_list = LaunchConfiguration("controller_list").perform(context)
    controllers = _split_controller_list(controller_list)

    controller_share = get_package_share_directory("controller")
    controller_param_files = []

    for controller in controllers:
        controller_param_file = os.path.join(
            controller_share,
            "config",
            model,
            f"{controller}.yaml",
        )

        if not os.path.isfile(controller_param_file):
            raise RuntimeError(
                "Controller parameter file does not exist: "
                f"{controller_param_file}"
            )

        controller_param_files.append(controller_param_file)

    return [
        Node(
            package="controller",
            executable="controller_node",
            name="controller_node",
            output="screen",
            parameters=controller_param_files + [
                {
                    "controller_list": controllers,
                }
            ],
        )
    ]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("model", default_value="cart_pole"),
            DeclareLaunchArgument("controller_list", default_value="lqr,test"),
            OpaqueFunction(function=_launch_setup),
        ]
    )
