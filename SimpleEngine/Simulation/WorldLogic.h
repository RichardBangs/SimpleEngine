#pragma once

#include "Logic/LogicBase.h"

#include <vector>

namespace Simulation
{
	class EventBase;
	class GameState;
	class WorldState;

	class WorldLogic : public LogicBase<WorldState>
	{
	public:
		WorldLogic();
		~WorldLogic();

		virtual void Tick(WorldState* thisWorld, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame);
	};
}