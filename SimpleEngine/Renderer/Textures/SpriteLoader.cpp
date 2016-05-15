#include "SpriteLoader.h"

namespace Renderer
{
	SpriteInfo::SpriteInfo(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY, int posX, int posY)
	{
		this->texturePath = texturePath;
		this->strideX = strideX;
		this->strideY = strideY;
		this->bufferX = bufferX;
		this->bufferY = bufferY;
		this->posX = posX;
		this->posY = posY;
	}

	std::map<const char*, SpriteInfo*> SpriteLoader::_sprites;

	//static
	void SpriteLoader::RegisterSprite(const char* texturePath, int strideX, int strideY, int bufferX, int bufferY, int posX, int posY, const char* spriteID)
	{
		_sprites[spriteID] = new SpriteInfo(texturePath, strideX, strideY, bufferX, bufferY, posX, posY);
	}
}
