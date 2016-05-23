#pragma once

#include "Utils\Singleton.h"

#include <vector>

namespace Simulation
{
	class EventBase;	//	Each user input that changes some state in our simulation comes through from an Event.
	class GameState;	//	Single Frame of State.
	class PlayerLogic;

	class SimulationManager : public Utils::Singleton<SimulationManager>
	{
	public:
		SimulationManager();
		~SimulationManager();

		GameState* Tick();

		void AddEvent(EventBase* newEvent);

		int Frame() { return _frame; }

	private:

		int _frame;

		std::vector<GameState*> _states;
		PlayerLogic* _playerLogic;
		std::vector<EventBase*> _events;
	};
}