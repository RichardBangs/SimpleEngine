#include "QuadRenderable.h"

#include "Textures\TextureLoader.h"
#include "ShaderLoader.h"

#include <vector>

#include "glew.h"

namespace Renderer
{
	QuadRenderable::QuadRenderable()
	{
		SetSize(glm::vec2(0.5f, 0.5f));
	}

	QuadRenderable::QuadRenderable(const char* texturePath)
	{
		SetSize(glm::vec2(0.5f, 0.5f));

		unsigned int simpleShaders = ShaderLoader::CreateProgram("Shaders\\BasicVertex.glsl", "Shaders\\BasicFragment.glsl");
		SetShader(simpleShaders);

		unsigned int simpleTexture = TextureLoader::GetOrLoadTexture("Textures\\test.png");
		SetTexture(simpleTexture);
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

		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, -halfHeight, 0.0f), blue, glm::vec2(1,1)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), blue, glm::vec2(0,1)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), blue, glm::vec2(1,0)));

		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), green, glm::vec2(0,1)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), green, glm::vec2(1,0)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, halfHeight, 0.0f), green, glm::vec2(0,0)));

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