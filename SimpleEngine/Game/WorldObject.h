#pragma once

namespace Renderer { class SpriteRenderable; }

namespace Game
{
	class WorldObject
	{
	public:
		WorldObject(int id, int x, int y, const char* renderable);
		~WorldObject();

		int _id;

	private:
		int _x, _y;

		Renderer::SpriteRenderable* _renderable;
	};
}