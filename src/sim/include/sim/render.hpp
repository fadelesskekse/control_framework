#ifndef RENDER_HPP_
#define RENDER_HPP_

#include "GLFW/glfw3.h"
#include "mujoco/mujoco.h"

namespace render {
    void init(mjModel* model, mjData* data);
    void render_frame();

    void keyboard(GLFWwindow* window, int key, int scancode, int act, int mods);
    void mouse_button(GLFWwindow* window, int button, int act, int mods);
    void mouse_move(GLFWwindow* window, double xpos, double ypos);
    void scroll(GLFWwindow* window, double xoffset, double yoffset);
}


#endif