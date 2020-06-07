#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "OpenGLRenderer.h"
#include "IOHandler.h"
#include "Graphics.h"

#pragma once
class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool initialize();
	void shutdown();
	void run();

	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);


private:
	bool frame();
	bool initWindows(OpenGLRenderer*, int&, int&);
	void shutdownWindows();



protected:
	LPCUWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;
	OpenGLRenderer* m_OpenGL;
	IOHandler* m_IO;
	Graphics* m_Graphics;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = 0;