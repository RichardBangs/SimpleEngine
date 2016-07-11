#pragma once

#include <map>

#include "glm.hpp"

namespace Simulation
{
	class WorldObjectState;

	class WorldState
	{
	public:
		WorldState();
		~WorldState() {}

		WorldObjectState* GetClosestObject(glm::vec3 position, float maxRange);

		std::map<int, WorldObjectState*> _objects;
	};
}