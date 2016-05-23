#include "WindowManager.h"

#include "freeglut.h"

namespace Renderer
{
	WindowManager::WindowManager()
	{
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::InitialiseWindow(glm::uvec2 position, glm::uvec2 size)
	{
		_position = position;
		_size = size;

		glutInitWindowPosition(_position.x, _position.y);
		glutInitWindowSize(_size.x, _size.y);
		glutCreateWindow("Simple Engine");
	}
}