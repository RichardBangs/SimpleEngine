#include "SpriteLoader.h"

namespace Renderer
{
	SpriteInfo::SpriteInfo(const char* texturePath, int posX, int posY)
	{
		this->texturePath = texturePath;
		this->posX = posX;
		this->posY = posY;
	}

	AtlasInfo::AtlasInfo(int strideX, int strideY, int bufferX, int bufferY)
	{
		this->strideX = strideX;
		this->strideY = strideY;
		this->bufferX = bufferX;
		this->bufferY = bufferY;
	}

	std::map<const char*, SpriteInfo*> SpriteLoader::_sprites;
	std::map<const char*, AtlasInfo*> SpriteLoader::_atlases;

	//static
	void SpriteLoader::RegisterAtlas(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY)
	{
		_atlases[texturePath] = new AtlasInfo(strideX, strideY, bufferX, bufferY);
	}

	//static
	void SpriteLoader::RegisterSprite(const char* texturePath, int posX, int posY, const char* spriteID)
	{
		_sprites[spriteID] = new SpriteInfo(texturePath, posX, posY);
	}
}
