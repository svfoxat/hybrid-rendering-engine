#pragma once

#include <fstream>
using namespace std;

#include "OpenGLRenderer.h"

class ColorShader
{
public:
	ColorShader();
	ColorShader(const ColorShader&);
	~ColorShader();

	bool Initialize(OpenGLRenderer*, HWND);
	void Shutdown(OpenGLRenderer*);
	void setShader(OpenGLRenderer*);
	bool setShaderParameters(OpenGLRenderer*, float*, float*, float*);

private:
	bool initShader(const char*, const char*, OpenGLRenderer*, HWND);
	char* loadShaderSourceFile(const char*);
	void OutputShaderErrorMessage(OpenGLRenderer*, HWND, unsigned int, const char*);
	void OutputLinkerErrorMessage(OpenGLRenderer*, HWND, unsigned int);
	void ShutdownShader(OpenGLRenderer*);

	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	unsigned int m_shaderProgram;

};



