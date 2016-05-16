#pragma once

#include "glm.hpp"

namespace Renderer
{
	class Camera
	{
	public:
		inline static Camera& Instance() { return *_instance; }
		inline static void Create() { new Camera; }
		inline static void Destroy() { delete _instance; }

		Camera();
		~Camera();

		void ApplyShaderConstant(unsigned int program);

		glm::vec3 Position;

	private:

		static Camera* _instance;
	};
}