#pragma once

namespace Renderer { class QuadRenderable; }

namespace Game
{
	class WorldTile
	{
	public:
		WorldTile(int x, int y, const char* texturePath);
		~WorldTile();

	private:
		int x, y;

		Renderer::QuadRenderable* _renderable;
	};
}