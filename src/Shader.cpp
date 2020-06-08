//
// Created by ninoe on 08.06.2020.
//

#include "Shader.h"

Shader::Shader(const char *mVertexShaderPath, const char *mFragmentShaderPath) {
    std::string vertexSource;
    std::string fragmentSource;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;

    vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexFile.open(mVertexShaderPath);
        fragmentFile.open(mFragmentShaderPath);

        std::stringstream vertexStream, fragmentStream;
        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();


        vertexFile.close();
        fragmentFile.close();

        vertexSource = vertexStream.str();
        fragmentSource = fragmentStream.str();
    } catch (std::ifstream::failure &e) {
        std::cout << "ERROR::SHADER::FILE_READ_ERROR" << std::endl;
        return;
    }

    const char* vShaderCode = vertexSource.c_str();
    const char* fShaderCode = fragmentSource.c_str();

    // now compile them
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, reinterpret_cast<const GLchar *const *>(&vShaderCode), nullptr);
    glShaderSource(fragment, 1, reinterpret_cast<const GLchar *const *>(&fShaderCode), nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    };

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    };


    m_id = glCreateProgram();
    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);
    glLinkProgram(m_id);

    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return;
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(m_id);
}


void Shader::setBool(const std::string &name, bool val) {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)val);
}
void Shader::setInt(const std::string &name, int val) {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), val);
}
void Shader::setFloat(const std::string &name, float val) {
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), val);
}

unsigned int Shader::getId() {
    return m_id;
}
