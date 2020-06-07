#pragma once

#include "OpenGLRenderer.h"
#include "windows.h"


const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class Graphics {
public:
	Graphics();
	Graphics(const Graphics&);
	~Graphics();

	bool init(OpenGLRenderer*, HWND);
	void shutdown();
	bool frame();

private:
	bool render();
	OpenGLRenderer* m_OpenGL;
};

