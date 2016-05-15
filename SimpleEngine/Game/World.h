#pragma once

#include <vector>

namespace Game
{
	class WorldTile;
	class WorldObject;

	class World
	{
	public:
		World();
		~World();



	private:

		std::vector<WorldTile*> _tiles;
		std::vector<WorldObject*> _objects;
	};
}