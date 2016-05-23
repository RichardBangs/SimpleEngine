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
		unsigned int locPosition = glGetUniformLocation(program, "cameraPosition");
		unsigned int locScale = glGetUniformLocation(program, "cameraScale");

		glUniform4f(locPosition, Position.x, Position.y, Position.z, 0.0f);
		glUniform4f(locScale, Scale.x, Scale.y, Scale.z, 1.0f);
	}
}