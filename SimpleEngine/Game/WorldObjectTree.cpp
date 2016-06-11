#include "WorldObjectTree.h"

#include "Renderer/QuadRenderable.h"

namespace Game
{
	WorldObjectTree::WorldObjectTree(int x, int y)
		: WorldObject(x, y, "City::Tree")
	{
	}

	WorldObjectTree::~WorldObjectTree()
	{
	}
}
