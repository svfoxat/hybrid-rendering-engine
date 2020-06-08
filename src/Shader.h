//
// Created by ninoe on 08.06.2020.
//

#ifndef HYBRIDENGINE_SHADER_H
#define HYBRIDENGINE_SHADER_H

#include "glad/glad.h"
#include "linmath.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);

    void use();

    void setBool(const std::string &name, bool val);
    void setInt(const std::string &name, int val);
    void setFloat(const std::string &name, float val);

    unsigned int getId();
private:
    unsigned int m_id;
};


#endif //HYBRIDENGINE_SHADER_H
