#pragma once

#include <vector>

namespace Simulation
{
	class GameState;
	class EventBase;

	template <typename T>
	class LogicBase
	{
	public:
		LogicBase() {}
		virtual ~LogicBase() {}

		virtual void Tick(T* thisPlayer, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame) = 0;
	};
}