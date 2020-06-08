//
// Created by ninoe on 07.06.2020.
//
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "linmath.h"
#include "EngineWindow.h"

EngineWindow::EngineWindow(unsigned int width, unsigned int height, char *windowTitle) :  m_windowTitle(windowTitle),
                                                                                m_width(width), m_height(height) {

    m_window = glfwCreateWindow(m_width, m_height, m_windowTitle, NULL, NULL);
    if (!m_window) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);
    gladLoadGL();

    glfwSetKeyCallback(m_window, KeyboardAction);
    glfwSetCursorPosCallback(m_window, MouseMoveAction);
    glfwSetMouseButtonCallback(m_window, MouseButtonAction);

    glfwGetFramebufferSize(m_window, &m_framebuffer_width, &m_framebuffer_height);
    glViewport(0, 0, m_framebuffer_width, m_framebuffer_height);
}

EngineWindow::~EngineWindow() {
    glfwTerminate();
}

void EngineWindow::KeyboardAction(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // std::cout << "[KEYBOARDACTION]" << key << " " << action << std::endl;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void EngineWindow::MouseMoveAction(GLFWwindow* window, double xpos, double ypos) {
    // std::cout << "[MOUSEMOVEACTION]" << xpos << " " << ypos << std::endl;
}

void EngineWindow::MouseButtonAction(GLFWwindow* window, int button, int action, int mods) {
    // std::cout << "[MOUSEBUTTONACTION]" << button << " " << action << std::endl;
}

void EngineWindow::run() {

    auto scene = new Scene();
    while (!glfwWindowShouldClose(m_window)) {
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glViewport(0, 0, m_width, m_height);
        glClear(GL_COLOR_BUFFER_BIT);

        scene->render();

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}