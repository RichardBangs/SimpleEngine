#include "WorldObjectTree.h"

#include "Renderer/QuadRenderable.h"

namespace Game
{
	WorldObjectTree::WorldObjectTree(int id, int x, int y)
		: WorldObject(id, x, y, "City::Tree")
	{
	}

	WorldObjectTree::~WorldObjectTree()
	{
	}
}
