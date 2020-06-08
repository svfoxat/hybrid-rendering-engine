//
// Created by ninoe on 07.06.2020.
//
#ifndef HYBRIDENGINE_ENGINEWINDOW_H
#define HYBRIDENGINE_ENGINEWINDOW_H

#include "stdio.h"
#include <GLFW/glfw3.h>
#include "Shader.h"

class EngineWindow {
public:
    EngineWindow(unsigned int width, unsigned int height, char *windowTitle);
    ~EngineWindow();

    void run();

private:
    GLFWwindow* m_window;
    char* m_windowTitle;
    unsigned int m_width;
    unsigned int m_height;

    int m_framebuffer_width{};
    int m_framebuffer_height{};

    static void KeyboardAction(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseMoveAction(GLFWwindow* window, double xpos, double ypos);
    static void MouseButtonAction(GLFWwindow* window, int button, int action, int mods);
};


#endif //HYBRIDENGINE_ENGINEWINDOW_H
