//
// Created by ninoe on 07.06.2020.
//
#include <iostream>
#include "EngineWindow.h"

int main() {

    if (!glfwInit()) {
        return -1;
    }

    auto* window = new EngineWindow(640, 480, (char *) L"Hello");
    window->run();

    return 0;
}