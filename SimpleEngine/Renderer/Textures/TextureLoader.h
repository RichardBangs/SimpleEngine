#pragma once

namespace Renderer
{
	class TextureLoader
	{
	public:
		TextureLoader();
		virtual ~TextureLoader();

		static unsigned int LoadTexture(const char* filename);
	};
}