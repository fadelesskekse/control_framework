import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition

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
    

    sim_share = get_package_share_directory("lockstep_sim")
    urdf_joint_ignore_file = os.path.join(sim_share,
                "config",
                model,
                "urdf_joint_ignore.yaml",)

    if not os.path.isfile(urdf_joint_ignore_file):
        raise RuntimeError(
            "URDF joint ignore parameter file does not exist: "
            f"{urdf_joint_ignore_file}"
        )

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

    sim_parameters = controller_param_files + [urdf_joint_ignore_file] + [
        {
            "glfw_render": int(glfw_render),
            "controller_list": controllers,
            #"model_name": model, #grabbed from urdf_joint_ignore_file
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

        Node(
            package="excel_record_logging",
            executable="excel_record_logging",
            name="excel_record_logging",
            output="screen",
            condition=IfCondition(LaunchConfiguration("excel_recording")),
            parameters=[urdf_joint_ignore_file]
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
            DeclareLaunchArgument("excel_recording", default_value="false"),
            DeclareLaunchArgument("glfw_render", default_value="0"),
            DeclareLaunchArgument("controller_list", default_value=""),
            DeclareLaunchArgument("model", default_value=""),
            DeclareLaunchArgument("controller_package", default_value="controller"),
            OpaqueFunction(function=_launch_setup),
        ]
    )
