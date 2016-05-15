#pragma once

#include "SimpleRenderable.h"

namespace Renderer
{
	class QuadRenderable : public SimpleRenderable
	{
	public:
		QuadRenderable();
		QuadRenderable(const char* texturePath);
		virtual ~QuadRenderable();

		inline void SetPosition(glm::vec3 position) { _position = position; }
		void SetSize(glm::vec2 size);

		virtual void SetShader(unsigned int program);

		virtual void Render();

	protected:

		glm::vec3 _position;
		glm::vec2 _size;

	private:

		int _shaderLocWorld;
	};
}