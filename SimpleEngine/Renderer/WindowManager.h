#pragma once

#include "glm.hpp"

#include "Utils/Singleton.h"

namespace Renderer
{
	class WindowManager : public Utils::Singleton<WindowManager>
	{
	public:
		WindowManager();
		~WindowManager();

		void InitialiseWindow(glm::uvec2 position, glm::uvec2 size);

		glm::uvec2 Position() { return _position; }
		glm::uvec2 Size() { return _size; }

	private:
		glm::uvec2 _position;
		glm::uvec2 _size;
	};
}