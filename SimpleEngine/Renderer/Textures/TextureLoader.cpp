#include "TextureLoader.h"

#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "lodepng/lodepng.h"

namespace Renderer
{
	std::map<const char*, TextureInfo*> TextureLoader::_textures;

	//static
	unsigned int TextureLoader::GetOrLoadTexture(const char* filename)
	{
		if (_textures.count(filename) == 0)
			_textures[filename] = TextureLoader::LoadTexture(filename);
		
		return _textures[filename]->handle;
	}

	TextureInfo* TextureLoader::GetOrLoadTexture_Info(const char* filename)
	{
		GetOrLoadTexture(filename);

		return _textures[filename];
	}

	//static
	TextureInfo* TextureLoader::LoadTexture(const char* filename)
	{
		auto info = new TextureInfo();

		glGenTextures(1, &info->handle);
		glBindTexture(GL_TEXTURE_2D, info->handle);

		std::string texturePath = Path::AbsolutePathRelativeToAssetsDirectory(filename);

		std::vector<unsigned char> data;

		lodepng::decode(data, info->width, info->height, texturePath);

		assert(data.size() != 0);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->width, info->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);

		//glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		return info;
	}
}