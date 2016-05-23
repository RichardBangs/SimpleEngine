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

		void SetSize(glm::vec2 size);

	protected:

		glm::vec2 _size;

	private:

		int _shaderLocWorld;
	};
}