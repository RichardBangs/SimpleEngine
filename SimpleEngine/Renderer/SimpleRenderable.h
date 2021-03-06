#pragma once

#include "BaseRenderable.h"
#include "VertexFormat.h"

#include <vector>

namespace Renderer
{
	class SimpleRenderable : public BaseRenderable
	{
	public:
		SimpleRenderable();
		virtual ~SimpleRenderable();

		void CreateFromList(std::vector<VertexFormat> vertices);
		void UpdateFromList(std::vector<VertexFormat> vertices);

		virtual void Render();

		void SetShader(unsigned int program) { _program = program; }
		void SetTexture(unsigned int texture) { _texture = texture;  }

		inline void SetPosition(glm::vec3 position) { _position = position; }

	protected:

		unsigned int _program;
		unsigned int _texture;

		glm::vec3 _position;

	private:

		unsigned int _vbo;
		unsigned int _vao;
		unsigned int _triangleCount;

	};
}