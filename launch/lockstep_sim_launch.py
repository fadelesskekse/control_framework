import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _split_controller_list(controller_list):
    return [
        controller.strip()
        for controller in controller_list.replace(";", ",").split(",")
        if controller.strip()
    ]


def _launch_setup(context, *args, **kwargs):
    glfw_render = LaunchConfiguration("glfw_render").perform(context)
    controller_list = LaunchConfiguration("controller_list").perform(context)
    model = LaunchConfiguration("model").perform(context)
    controller_package = LaunchConfiguration("controller_package").perform(context)

    controller_param_files = []
    controllers = _split_controller_list(controller_list)

    if controllers:
        if not model:
            raise RuntimeError(
                "model must be set when controller_list is set, e.g. "
                "model:=cart_pole controller_list:=lqr,pid"
            )

        controller_share = get_package_share_directory(controller_package)

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

    sim_parameters = controller_param_files + [
        {
            "glfw_render": int(glfw_render),
            "controller_list": controllers,
            "model_name": model,
        }
    ]

    foxglove_bridge_launch = os.path.join(
        get_package_share_directory("foxglove_bridge"),
        "launch",
        "foxglove_bridge_launch.xml",
    )

    return [
        Node(
            package="lockstep_sim",
            executable="lockstep_sim",
            name="sim",
            output="screen",
            arguments=["--ros-args", "--log-level", "info"],
            parameters=sim_parameters,
        ),
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(foxglove_bridge_launch),
        ),
        ExecuteProcess(
            cmd=["foxglove-studio"],
            name="foxglove_studio",
            output="screen",
        ),
    ]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("glfw_render", default_value="0"),
            DeclareLaunchArgument("controller_list", default_value=""),
            DeclareLaunchArgument("model", default_value=""),
            DeclareLaunchArgument("controller_package", default_value="controller"),
            OpaqueFunction(function=_launch_setup),
        ]
    )
