import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, OpaqueFunction, TimerAction
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition
from launch.conditions import IfCondition, LaunchConfigurationEquals

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
    sim_type = LaunchConfiguration("sim_type").perform(context)
    controller_execution_type = LaunchConfiguration("controller_execution_type").perform(context)

    microros_workspace = os.path.expanduser(
    "~/.local/repos/microros_ws"
)

    zephyr_executable = os.path.join(
        microros_workspace,
        "firmware",
        "build",
        "zephyr",
        "zephyr.exe",
    )

    if (
        controller_execution_type == "hil" and
        not os.path.isfile(zephyr_executable)
    ):
        raise RuntimeError(
            "Zephyr emulator does not exist: "
            f"{zephyr_executable}. Build the firmware first."
        )

    valid_controller_executions = {
        "sil",
        "hil",
    }

    if controller_execution_type not in valid_controller_executions:
        raise RuntimeError(
            f"Unsupported controller_execution "
            f"{controller_execution_type!r}. "
            f"Valid values: "
            f"{', '.join(valid_controller_executions)}"
        )

    sim_executables = {
        "lockstep": "lockstep_sim",
        "parallel" : "parallel_sim",
    }

    try:
        executable = sim_executables[sim_type]

    except KeyError:

        raise RuntimeError(
            f"Unsupported sim_type {sim_type!r}. "
            f"Valid types: {', '.join(sim_executables)}"
        )
 


    sim_share = get_package_share_directory("sim")
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

    if sim_type == "lockstep":

        sim_parameters = controller_param_files + [urdf_joint_ignore_file] + [
            {
                "glfw_render": int(glfw_render),
                "controller_list": controllers,
                #"model_name": model, #grabbed from urdf_joint_ignore_file
            }
        ]

    elif sim_type == "parallel":

        sim_parameters = [urdf_joint_ignore_file] + [
            {
                "glfw_render": int(glfw_render),
                "controller_list": controllers,
                #"model_name": model, #grabbed from urdf_joint_ignore_file
            }
        ]


    actions=[

            Node(
            prefix="chrt -f 98",
            package="sim",
            executable=executable,
            name="sim",
            output="screen",
            arguments=["--ros-args", "--log-level", "info"],
            parameters=sim_parameters,
            ),

            # Node(
            # prefix="chrt -f 98",
            # package="controller",
            # executable="controller_node",
            # name="controller_node",
            # output="screen",
            # condition=LaunchConfigurationEquals("sim_type", "parallel"),
            # parameters=controller_param_files + [urdf_joint_ignore_file] + [
            #         {
            #             "controller_list": controllers,
            #         }
            #     ],
            # ),

            Node(
            prefix="nice -n 10",
            package="excel_record_logging",
            executable="excel_record_logging",
            name="excel_record_logging",
            output="screen",
            condition=IfCondition(LaunchConfiguration("excel_recording")),
            parameters=[urdf_joint_ignore_file, {"sim_type": sim_type}]
            ),

            Node(
                prefix="nice -n 10",
                package="foxglove_bridge",
                executable="foxglove_bridge",
                name="foxglove_bridge",
                output="screen",
            ),

            ExecuteProcess(
                cmd=[
                    "nice", "-n", "10",
                    "foxglove-studio",
                    "--ozone-platform=x11",  
                ],

                name="foxglove_studio",
                output="screen",
            ),

    ]

    if (
        sim_type == "parallel" and
        controller_execution_type == "sil"
    ):
        actions.append(
            Node(
                prefix="chrt -f 98",
                package="controller",
                executable="controller_node",
                name="controller_node",
                output="screen",
                parameters=(
                    controller_param_files +
                    [urdf_joint_ignore_file] +
                    [
                        {
                            "controller_list": controllers,
                        }
                    ]
                ),
            )
        )

    if (
        sim_type == "parallel" and
        controller_execution_type == "hil"
    ):
        actions.extend([
            Node(
                package="micro_ros_agent",
                executable="micro_ros_agent",
                name="micro_ros_agent",
                output="screen",
                prefix="chrt -f 98",
                arguments=[
                    "udp4",
                    "--port",
                    "8888",
                ],
            ),

        TimerAction(
            period=1.0,
            actions=[
                ExecuteProcess(
                    cmd=[
                        "chrt",
                        "-f",
                        "98",
                        zephyr_executable,
                    ],
                    name="zephyr_controller_emulator",
                    output="screen",
                    emulate_tty=True,
                ),
            ],
        ),
        ])

    


    return actions


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("excel_recording", default_value="false"),
            DeclareLaunchArgument("glfw_render", default_value="0"),
            DeclareLaunchArgument("controller_list", default_value="lqr"),
            DeclareLaunchArgument("model", default_value="cart_pole"),
            DeclareLaunchArgument("controller_package", default_value="controller"),
            DeclareLaunchArgument("sim_type", default_value="lockstep"),
            DeclareLaunchArgument("controller_execution_type", default_value="sil"),

            OpaqueFunction(function=_launch_setup),
        ]
    )