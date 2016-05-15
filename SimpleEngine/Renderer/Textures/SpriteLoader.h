#pragma once

#include <map>
#include <vector>

namespace Renderer
{
	struct SpriteInfo
	{
		SpriteInfo(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY, int posX, int posY);

		const char* texturePath;
		
		int strideX;
		int strideY;

		int bufferX;
		int bufferY;

		int posX;
		int posY;
	};

	class SpriteLoader
	{
	public:

		static void RegisterSprite(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY, int posX, int posY, const char* spriteID);
		static SpriteInfo* GetSpriteInfo(const char* spriteID) { return _sprites[spriteID]; }

	private:

		static std::map<const char*, SpriteInfo*> _sprites;
	};
}
