#include "Graphics.h"

Graphics::Graphics() {}
Graphics::Graphics(const Graphics& other) {}
Graphics::~Graphics() {}


bool Graphics::init(OpenGLRenderer* OpenGL, HWND hwnd) {
	return true;
}


void Graphics::shutdown() {
	return;
}


bool Graphics::frame() {
	return true;
}


bool Graphics::render() {
	return true;
}
