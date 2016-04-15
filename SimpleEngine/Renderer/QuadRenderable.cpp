#include "QuadRenderable.h"

#include <vector>

#include "glew.h"

namespace Renderer
{
	QuadRenderable::QuadRenderable()
	{
		SetSize(glm::vec2(0.5f, 0.5f));
	}

	//virtual
	QuadRenderable::~QuadRenderable()
	{
	}

	void QuadRenderable::SetSize(glm::vec2 size)
	{
		_size = size;

		std::vector<Renderer::VertexFormat> vertices;

		glm::vec4 blue(0.0f, 0.0f, 1.0f, 1.0f);
		glm::vec4 green(0.0f, 1.0f, 0.0f, 1.0f);

		float halfWidth = size.x / 2.0f;
		float halfHeight = size.y / 2.0f;

		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, -halfHeight, 0.0f), blue));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), blue));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), blue));

		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), green));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), green));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, halfHeight, 0.0f), green));

		CreateFromList(vertices);
	}

	//virtual
	void QuadRenderable::SetShader(unsigned int program)
	{
		SimpleRenderable::SetShader(program);

		_shaderLocWorld = glGetUniformLocation(_program, "worldPosition");
	}

	//virtual
	void QuadRenderable::Render()
	{
		glUniform4f(_shaderLocWorld, _position.x, _position.y, _position.z, 0.0f);

		SimpleRenderable::Render();
	}
}