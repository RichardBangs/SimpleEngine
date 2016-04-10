#include "QuadRenderable.h"

#include <vector>

namespace Renderer
{
	QuadRenderable::QuadRenderable()
	{
		std::vector<Renderer::VertexFormat> vertices;

		glm::vec4 blue(0.0f, 0.0f, 1.0f, 1.0f);
		glm::vec4 green(0.0f, 1.0f, 0.0f, 1.0f);

		vertices.push_back(Renderer::VertexFormat(glm::vec3(0.25f, -0.25f, 0.0f), blue));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-0.25f, -0.25f, 0.0f), blue));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(0.25f, 0.25f, 0.0f), blue));

		vertices.push_back(Renderer::VertexFormat(glm::vec3(-0.25f, -0.25f, 0.0f), green));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(0.25f, 0.25f, 0.0f), green));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-0.25f, 0.25f, 0.0f), green));
		
		CreateFromList(vertices);
	}

	//virtual
	QuadRenderable::~QuadRenderable()
	{
	}
}