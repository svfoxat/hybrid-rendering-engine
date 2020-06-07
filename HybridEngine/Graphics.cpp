#include "Graphics.h"

Graphics::Graphics() {
	m_OpenGL = 0;
	m_Camera = 0;
	m_Model = 0;
	m_ColorShader = 0;
}
Graphics::Graphics(const Graphics& other) {}
Graphics::~Graphics() {}


bool Graphics::init(OpenGLRenderer* OpenGL, HWND hwnd) {
	bool result;
	m_OpenGL = OpenGL;
	
	// Create the camera object.
	m_Camera = new Camera();
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->setPosition(0.0f, 0.0f, -10.0f);

	// Create the model object.
	m_Model = new Model();
	if (!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->init(m_OpenGL);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	m_ColorShader = new ColorShader();
	if (!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_OpenGL, hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}
	return true;
}


void Graphics::shutdown() {
	if (m_ColorShader) {
		m_ColorShader->Shutdown(m_OpenGL);
		m_ColorShader = 0;
	}

	if (m_Model) {
		m_Model->shutdown(m_OpenGL);
		m_Model = 0;
	}

	if (m_Camera) {
		delete m_Camera;
		m_Camera = 0;
	}

	m_OpenGL = 0;
	return;
}


bool Graphics::frame() {
	return render();
}


bool Graphics::render() {
	float worldMatrix[16];
	float viewMatrix[16];
	float projectionMatrix[16];

	// Clear the buffers to begin the scene.
	m_OpenGL->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->render();

	// Get the world, view, and projection matrices from the opengl and camera objects.
	m_OpenGL->GetWorldMatrix(worldMatrix);
	m_Camera->getViewMatrix(viewMatrix);
	m_OpenGL->GetProjectionMatrix(projectionMatrix);

	// Set the color shader as the current shader program and set the matrices that it will use for rendering.
	m_ColorShader->setShader(m_OpenGL);
	m_ColorShader->setShaderParameters(m_OpenGL, worldMatrix, viewMatrix, projectionMatrix);

	// Render the model using the color shader.
	m_Model->render(m_OpenGL);

	// Present the rendered scene to the screen.
	m_OpenGL->EndScene();

	return true;
}
