#include "../include/sim/render.hpp"

namespace render
{

    mjModel* m = NULL;
    mjData* d = NULL;

    mjvCamera cam;                      // abstract camera
    mjvOption opt;                      // visualization options
    mjvScene scn;                       // abstract scene
    mjrContext con;                     // custom GPU context



    GLFWwindow* window = NULL;

    // mouse interaction
    bool button_left;
    bool button_middle;
    bool button_right;
    double lastx;
    double lasty;
    size_t render_frame_rate;

    void init(mjModel* model, mjData* data)
    {
        m=model;
        d=data;

        render_frame_rate = 60;

        // init GLFW
        if (!glfwInit()) {
            mju_error("Could not initialize GLFW");
        }

        window = glfwCreateWindow(1200, 900, "Sim", NULL, NULL);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        // initialize visualization data structures
        mjv_defaultCamera(&cam);
        mjv_defaultOption(&opt);
        mjv_defaultScene(&scn);
        mjr_defaultContext(&con);

        // create scene and context
        mjv_makeScene(model, &scn, 2000);
        mjr_makeContext(model, &con, mjFONTSCALE_150);

        glfwSetKeyCallback(window, render::keyboard);
        glfwSetCursorPosCallback(window, render::mouse_move);
        glfwSetMouseButtonCallback(window, render::mouse_button);
        glfwSetScrollCallback(window, render::scroll);
  
    }

    void render_frame()
    {
        mjrRect viewport = {0, 0, 0, 0};
        glfwGetFramebufferSize(window, &viewport.width, &viewport.height);

        // update scene and render
        mjv_updateScene(m, d, &opt, NULL, &cam, mjCAT_ALL, &scn);
        mjr_render(viewport, &scn, &con);

        // swap OpenGL buffers (blocking call due to v-sync)
        glfwSwapBuffers(window);

        // process pending GUI events, call GLFW callbacks
        glfwPollEvents();
    }

    void keyboard(GLFWwindow* window, int key, int scancode, int act, int mods)
    {

        // backspace: reset simulation
        if (act==GLFW_PRESS && key==GLFW_KEY_BACKSPACE) {

            mj_resetData(m, d);
             d->qpos[0] = .3;
            d->qpos[1] = .3;
             d->qvel[0] = .3;
             d->qvel[1] = .3;
        

            mj_forward(m, d);
        }
    }

    // mouse button callback
    void mouse_button(GLFWwindow* window, int button, int act, int mods) {
    // update button state
    button_left = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS);
    button_middle = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE)==GLFW_PRESS);
    button_right = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT)==GLFW_PRESS);

    // update mouse position
    glfwGetCursorPos(window, &lastx, &lasty);
    }


    // mouse move callback
    void mouse_move(GLFWwindow* window, double xpos, double ypos) {
    // no buttons down: nothing to do
    if (!button_left && !button_middle && !button_right) {
        return;
    }

    // compute mouse displacement, save
    double dx = xpos - lastx;
    double dy = ypos - lasty;
    lastx = xpos;
    lasty = ypos;

    // get current window size
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // get shift key state
    bool mod_shift = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS ||
                        glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS);

    // determine action based on mouse button
    mjtMouse action;
    if (button_right) {
        action = mod_shift ? mjMOUSE_MOVE_H : mjMOUSE_MOVE_V;
    } else if (button_left) {
        action = mod_shift ? mjMOUSE_ROTATE_H : mjMOUSE_ROTATE_V;
    } else {
        action = mjMOUSE_ZOOM;
    }

    // move camera
    mjv_moveCamera(m, action, dx/height, dy/height, &scn, &cam);
    }


    // scroll callback
    void scroll(GLFWwindow* window, double xoffset, double yoffset) {
    // emulate vertical mouse motion = 5% of window height
    mjv_moveCamera(m, mjMOUSE_ZOOM, 0, -0.05*yoffset, &scn, &cam);
    }



}

/*
RenderObj::RenderObj(mjModel* model, mjData* data)
: m(model), d(data), button_left(false), button_middle(false), button_right(false), lastx(0),lasty(0)
{
    // init GLFW
    if (!glfwInit()) {
        mju_error("Could not initialize GLFW");
    }

    window = glfwCreateWindow(1200, 900, "Sim", NULL, NULL);

    

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // initialize visualization data structures
    mjv_defaultCamera(&cam);
    mjv_defaultOption(&opt);
    mjv_defaultScene(&scn);
    mjr_defaultContext(&con);

        // create scene and context
    mjv_makeScene(m, &scn, 2000);
    mjr_makeContext(m, &con, mjFONTSCALE_150);

        // install GLFW mouse and keyboard callbacks
    glfwSetKeyCallback(window, RenderObj::keyboard);
    glfwSetCursorPosCallback(window, RenderObj::mouse_move);
    glfwSetMouseButtonCallback(window, RenderObj::mouse_button);
    glfwSetScrollCallback(window, RenderObj::scroll);

}

void RenderObj::setup_callbacks(GLFWwindow* window){

    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, RenderObj::keyboard_callback);


}

void RenderObj::keyboard_callback(GLFWwindow* window, int key, int scancode, int act, int mods)
{
    auto* self = static_cast<RenderObj*>(glfwGetWindowUserPointer(window));

    if (self) {
        self->keyboard(window, key, scancode, act, mods);
    }
}

// keyboard callback
void RenderObj::keyboard(GLFWwindow* window, int key, int scancode, int act, int mods) {

  // backspace: reset simulation
  if (act==GLFW_PRESS && key==GLFW_KEY_BACKSPACE) {

    mj_resetData(m, d);
   // d->qpos[0] = .3;
    //d->qpos[1] = .3;
   // d->qvel[0] = .3;
   // d->qvel[1] = .3;
  

    mj_forward(m, d);
  }
}


// mouse button callback
void RenderObj::mouse_button(GLFWwindow* window, int button, int act, int mods) {
  // update button state
  button_left = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS);
  button_middle = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE)==GLFW_PRESS);
  button_right = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT)==GLFW_PRESS);

  // update mouse position
  glfwGetCursorPos(window, &lastx, &lasty);
}


// mouse move callback
void RenderObj::mouse_move(GLFWwindow* window, double xpos, double ypos) {
  // no buttons down: nothing to do
  if (!button_left && !button_middle && !button_right) {
    return;
  }

  // compute mouse displacement, save
  double dx = xpos - lastx;
  double dy = ypos - lasty;
  lastx = xpos;
  lasty = ypos;

  // get current window size
  int width, height;
  glfwGetWindowSize(window, &width, &height);

  // get shift key state
  bool mod_shift = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS ||
                    glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS);

  // determine action based on mouse button
  mjtMouse action;
  if (button_right) {
    action = mod_shift ? mjMOUSE_MOVE_H : mjMOUSE_MOVE_V;
  } else if (button_left) {
    action = mod_shift ? mjMOUSE_ROTATE_H : mjMOUSE_ROTATE_V;
  } else {
    action = mjMOUSE_ZOOM;
  }

  // move camera
  mjv_moveCamera(m, action, dx/height, dy/height, &scn, &cam);
}


// scroll callback
void RenderObj::scroll(GLFWwindow* window, double xoffset, double yoffset) {
  // emulate vertical mouse motion = 5% of window height
  mjv_moveCamera(m, mjMOUSE_ZOOM, 0, -0.05*yoffset, &scn, &cam);
}

*/