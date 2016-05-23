#include "World.h"

#include "WorldTileGrass.h"

namespace Game
{
	const float World::WorldScale = 2.0f;

	World::World()
	{
		const int worldSize = 1;

		for (int x = 0; x < worldSize; x++)
		{
			for (int y = 0; y < worldSize; y++)
			{
				auto newTile = new WorldTileGrass( x, y );
				_tiles.push_back( (WorldTile*)newTile );
			}
		}
	}

	World::~World()
	{
	}
}