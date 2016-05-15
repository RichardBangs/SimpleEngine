#pragma once

#include "QuadRenderable.h"

namespace Renderer
{
	struct SpriteInfo;
	struct TextureInfo;

	class SpriteRenderable : public QuadRenderable
	{
	public:
		SpriteRenderable(const char* spriteID);
		virtual ~SpriteRenderable();

		void SetSize(glm::vec2 size, SpriteInfo* spriteInfo, TextureInfo* textureInfo);

	private:

	};
}