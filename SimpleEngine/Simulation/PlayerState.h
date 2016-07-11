#pragma once

#include "glm.hpp"

namespace Simulation
{
	class PlayerState
	{
	public:
		PlayerState(int id);
		~PlayerState() {}

		glm::vec3 _Position;
		int _id;

		int _amountOfWood;
	};
}