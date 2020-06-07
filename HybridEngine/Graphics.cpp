#include "Graphics.h"

Graphics::Graphics() {
	m_OpenGL = 0;
}
Graphics::Graphics(const Graphics& other) {}
Graphics::~Graphics() {}


bool Graphics::init(OpenGLRenderer* OpenGL, HWND hwnd) {
	m_OpenGL = OpenGL;
	return true;
}


void Graphics::shutdown() {
	m_OpenGL = 0;
	return;
}


bool Graphics::frame() {
	return render();
}


bool Graphics::render() {
	m_OpenGL->BeginScene(0.5f, 0.5f, 0.5f, 1.f);
	m_OpenGL->EndScene();
	return true;
}
