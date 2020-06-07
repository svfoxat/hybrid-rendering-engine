//
// Created by ninoe on 07.06.2020.
//
#include <iostream>
#include "EngineWindow.h"

int main() {

    if (!glfwInit()) {
        return -1;
    }

    EngineWindow* window = new EngineWindow(640, 480, "Hello");
    window->run();

    return 0;
}