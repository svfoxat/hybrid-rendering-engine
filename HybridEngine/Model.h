#pragma once

#include "OpenGLRenderer.h"


class Model {
public:
	Model();
	Model(const Model&);
	~Model();

	bool init(OpenGLRenderer*);
	void shutdown(OpenGLRenderer*);
	void render(OpenGLRenderer*);

private:
	struct Vertex {
		float x, y, z;
		float r, g, b;
	};

	bool initializeBuffers(OpenGLRenderer*);
	void shutdownBuffers(OpenGLRenderer*);
	void renderBuffers(OpenGLRenderer*);

	int m_vertexCount;
	int m_indexCount;
	unsigned int m_vertexArrayId;
	unsigned int m_vertexBufferId;
	unsigned int m_indexBufferId;
};

