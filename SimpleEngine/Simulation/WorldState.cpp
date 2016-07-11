#include "WorldState.h"

#include "WorldObjectState.h"

namespace Simulation
{
	WorldState::WorldState()
	{
	}

	WorldObjectState* WorldState::GetClosestObject(glm::vec3 position, float maxRange)
	{
		float closestLength = 0.0f;
		int closestID = -1;
		for (auto it = _objects.begin(); it != _objects.end(); ++it)
		{
			auto myObject = it->second;
			
			float length = glm::distance(position, glm::vec3(myObject->_x / 10.0f, myObject->_y / 10.0f, 0.0f));
				
			if (length > maxRange)
				continue;

			if (closestID == -1 || length < closestLength)
			{
				closestID = myObject->_id;
				closestLength = length;
			}
		}

		if (closestID == -1)
			return NULL;

		return _objects[closestID];
	}
}