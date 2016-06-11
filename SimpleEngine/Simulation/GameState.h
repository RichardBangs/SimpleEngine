#pragma once

#include <vector>

namespace Simulation
{
	class PlayerState;
	class EventBase;
	class WorldObjectState;
	class WorldState;

	class GameState
	{
	public:
		GameState(int frame);
		~GameState();

		void Tick(std::vector<EventBase*> eventsThisTick, GameState* previousGameState);

		std::vector<PlayerState*> _players;
		WorldState* _world;

	private:
		int _frame;
	};
}