#include "Camera.h"

#include "glew.h"

namespace Renderer
{
	Camera* Camera::_instance;

	Camera::Camera()
	{
		_instance = this;
	}

	Camera::~Camera()
	{
	}

	void Camera::ApplyShaderConstant(unsigned int program)
	{
		unsigned int loc = glGetUniformLocation(program, "cameraPosition");

		glUniform4f(loc, Position.x, Position.y, Position.z, 0.0f);
	}
}