#include "SpriteRenderable.h"

#include "Textures\TextureLoader.h"
#include "Textures\SpriteLoader.h"
#include "ShaderLoader.h"

#include <vector>

#include "glew.h"

namespace Renderer
{
	SpriteRenderable::SpriteRenderable(const char* spriteID)
	{
		auto spriteInfo = SpriteLoader::GetSpriteInfo(spriteID);

		unsigned int simpleShaders = ShaderLoader::CreateProgram("Shaders\\BasicVertex.glsl", "Shaders\\BasicFragment.glsl");
		SetShader(simpleShaders);

		TextureInfo* textureInfo = TextureLoader::GetOrLoadTexture_Info(spriteInfo->texturePath);
		SetTexture(textureInfo->handle);

		SetSize(glm::vec2(1.0f, 1.0f), spriteInfo, textureInfo);
	}

	//virtual
	SpriteRenderable::~SpriteRenderable()
	{
	}

	void SpriteRenderable::SetSize(glm::vec2 size, SpriteInfo* spriteInfo, TextureInfo* textureInfo)
	{
		QuadRenderable::_size = size;

		std::vector<Renderer::VertexFormat> vertices;

		glm::vec4 white(1.0f, 1.0f, 1.0f, 1.0f);

		float halfWidth = size.x / 2.0f;
		float halfHeight = size.y / 2.0f;

		glm::vec2 UV0 = glm::vec2((1.0f / textureInfo->width) * (spriteInfo->posX * ( spriteInfo->strideX + spriteInfo->bufferX )),
			(1.0f / textureInfo->height) * (spriteInfo->posY * ( spriteInfo->strideY + spriteInfo->bufferY )) );

		glm::vec2 UV1 = UV0 + glm::vec2((1.0f / textureInfo->width) * spriteInfo->strideX,
			(1.0f / textureInfo->height) * spriteInfo->strideY);

		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, -halfHeight, 0.0f), white, glm::vec2(UV1.x, UV1.y)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), white, glm::vec2(UV0.x, UV1.y)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), white, glm::vec2(UV1.x, UV0.y)));

		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, -halfHeight, 0.0f), white, glm::vec2(UV0.x, UV1.y)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(halfWidth, halfHeight, 0.0f), white, glm::vec2(UV1.x, UV0.y)));
		vertices.push_back(Renderer::VertexFormat(glm::vec3(-halfWidth, halfHeight, 0.0f), white, glm::vec2(UV0.x, UV0.y)));

		CreateFromList(vertices);
	}
}