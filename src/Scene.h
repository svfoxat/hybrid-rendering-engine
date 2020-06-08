//
// Created by ninoe on 08.06.2020.
//

#ifndef HYBRIDENGINE_SCENE_H
#define HYBRIDENGINE_SCENE_H

#include "glad/glad.h"

class Scene {
public:
    Scene();
    void render();

private:
    unsigned int m_VAO;
};


#endif //HYBRIDENGINE_SCENE_H
