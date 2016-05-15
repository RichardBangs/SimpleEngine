#pragma once

#include <map>

namespace Renderer
{
	struct TextureInfo
	{
		unsigned int handle;

		unsigned int width;
		unsigned int height;
	};

	class TextureLoader
	{
	public:

		static unsigned int GetOrLoadTexture(const char* filename);
		static TextureInfo* GetOrLoadTexture_Info(const char* filename);

	private:

		static TextureInfo* LoadTexture(const char* filename);

		static std::map<const char*, TextureInfo*> _textures;
	};
}