//
// Created by ninoe on 07.06.2020.
//
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "linmath.h"
#include "EngineWindow.h"

float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
};
unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};


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
    //Init Buffer Objects
    unsigned int VBO, VAO, EBO;
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    auto myShader = new Shader("./shader.vs", "./shader.fs");

    while (!glfwWindowShouldClose(m_window)) {
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glViewport(0, 0, m_width, m_height);
        glClear(GL_COLOR_BUFFER_BIT);

        myShader->use();
        myShader->setFloat("r", 1.f);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}