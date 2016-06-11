#pragma once
#include "WorldObjectState.h"

namespace Simulation
{
	class WorldObjectStateTree : public WorldObjectState
	{
	public:
		WorldObjectStateTree(int id, int x, int y);
	};
}