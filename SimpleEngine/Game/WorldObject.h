#pragma once

namespace Renderer { class SpriteRenderable; }

namespace Game
{
	class WorldObject
	{
	public:
		WorldObject(int x, int y, const char* renderable);
		~WorldObject();

	private:
		int _x, _y;

		Renderer::SpriteRenderable* _renderable;
	};
}