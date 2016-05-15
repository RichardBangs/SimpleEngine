#pragma once

#include <map>

namespace Renderer
{
	class TextureLoader
	{
	public:

		static unsigned int GetOrLoadTexture(const char* filename);

	private:

		static unsigned int LoadTexture(const char* filename);

		static std::map<const char*, unsigned int> _textures;
	};
}