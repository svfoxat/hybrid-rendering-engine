#pragma once

#include <math.h>


class Camera {
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	void setPosition(float, float, float);
	void setRotation(float, float, float);
	void render();
	void getViewMatrix(float*);

private:
	struct Vector {
		float x, y, z;
	};
	void matrixRotationYawPitchRoll(float*, float, float, float);
	void transformCoord(Vector&, float*);
	void buildViewMatrix(Vector, Vector, Vector);

	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	float m_viewMatrix[16];

};

