#pragma once

#include <vector>

namespace Simulation
{
	class WorldObjectState;

	class WorldState
	{
	public:
		WorldState();
		~WorldState() {}

		std::vector<WorldObjectState*> _objects;
	};
}