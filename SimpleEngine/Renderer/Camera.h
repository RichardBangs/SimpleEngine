#pragma once

#include "glm.hpp"

#include "Utils/Singleton.h"

namespace Renderer
{
	class Camera : public Utils::Singleton<Camera>
	{
	public:
		Camera();
		~Camera();

		void ApplyShaderConstant(unsigned int program);

		glm::vec3 Position;
		glm::vec3 Scale;

	private:

		static Camera* _instance;
	};
}