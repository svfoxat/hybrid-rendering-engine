//
// Created by ninoe on 07.06.2020.
//
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "linmath.h"
#include "EngineWindow.h"

static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
        {
                { -0.6f, -0.4f, 1.f, 0.f, 0.f },
                {  0.6f, -0.4f, 0.f, 1.f, 0.f },
                {   0.f,  0.6f, 0.f, 0.f, 1.f }
        };

static const char* vertex_shader_text =
        "#version 110\n"
        "uniform mat4 MVP;\n"
        "attribute vec3 vCol;\n"
        "attribute vec2 vPos;\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
        "    color = vCol;\n"
        "}\n";

static const char* fragment_shader_text =
        "#version 110\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = vec4(color, 1.0);\n"
        "}\n";



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
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) (sizeof(float) * 2));

    while (!glfwWindowShouldClose(m_window)) {
        float ratio;
        mat4x4 m, p, mvp;

        glfwGetFramebufferSize(m_window, &m_framebuffer_width, &m_framebuffer_height);
        ratio = (float) m_framebuffer_width / (float) m_framebuffer_height;
        glViewport(0, 0, m_width, m_height);
        glClear(GL_COLOR_BUFFER_BIT);

        mat4x4_identity(m);
        mat4x4_rotate(m, m, (float) glfwGetTime(), 0, 0, 0);
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);

        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}