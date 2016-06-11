#pragma once

#include <vector>
#include <map>

#include "Utils/Singleton.h"

namespace Game
{
	class WorldTile;
	class WorldObject;

	class World : public Utils::Singleton<World>
	{
	public:
		World();
		~World();

		const static float WorldScale;	//	Number of tiles height-wise that fit on screen (aspect ratio will vary the number in width wise).

		std::vector<WorldTile*> _tiles;
		std::map<int, WorldObject*> _objects;
	};
}