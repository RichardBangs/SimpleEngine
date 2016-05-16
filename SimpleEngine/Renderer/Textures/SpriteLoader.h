#pragma once

#include <map>
#include <vector>

namespace Renderer
{
	struct SpriteInfo
	{
		SpriteInfo(const char* texturePath, int posX, int posY);

		const char* texturePath;
		
		int posX;
		int posY;
	};

	struct AtlasInfo
	{
		AtlasInfo(int strideX, int strideY, int bufferX, int bufferY);

		int strideX;
		int strideY;
		int bufferX;
		int bufferY;
	};

	class SpriteLoader
	{
	public:

		static void RegisterAtlas(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY);
		static AtlasInfo* GetAtlasInfo(const char* texturePath) { return _atlases[texturePath]; }

		static void RegisterSprite(const char* texturePath, int posX, int posY, const char* spriteID);
		static SpriteInfo* GetSpriteInfo(const char* spriteID) { return _sprites[spriteID]; }

	private:

		static std::map<const char*, AtlasInfo*> _atlases;
		static std::map<const char*, SpriteInfo*> _sprites;
	};
}
