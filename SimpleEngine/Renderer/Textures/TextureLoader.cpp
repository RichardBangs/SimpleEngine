#include "TextureLoader.h"

#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"

#include "Path.h"

#include "lodepng/lodepng.h"

namespace Renderer
{
	TextureLoader::TextureLoader()
	{
	}
	
	//virtual
	TextureLoader::~TextureLoader()
	{
	}

	unsigned int TextureLoader::LoadTexture(const char* filename)
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		std::string texturePath = Path::AbsolutePathRelativeToAssetsDirectory(filename);

		unsigned int width = 128;
		unsigned int height = 128;
		std::vector<unsigned char> data;

		lodepng::decode(data, width, height, texturePath);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);

		glGenerateMipmap(GL_TEXTURE_2D);

		return texture;
	}
}