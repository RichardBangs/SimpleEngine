#include "SimulationManager.h"

#include "../Server.h"
#include "Logic\PlayerLogic.h"
#include "WorldLogic.h"
#include "GameState.h"
#include "Events\EventBase.h"

namespace Simulation
{
	SimulationManager::SimulationManager()
	{
		_frame = -1;
		_playerLogic = new PlayerLogic();
		_worldLogic = new WorldLogic();
	}

	SimulationManager::~SimulationManager()
	{
		delete _playerLogic;
		delete _worldLogic;
	}

	GameState* SimulationManager::Tick()
	{
		//	TODO: Sort out allocations in this function (and those below it in the callstack!!!!).

		_frame++;

		GameState* previousGameState;
		if(_states.empty())
		{
			previousGameState = new GameState(-1);	//	Empty gamestate! Happens at the start of the game.
		}
		else
		{
			previousGameState = _states.back();
		}
		
		GameState* currentGameState = new GameState(_frame);
		_states.push_back(currentGameState);

		//	TODO: Potentially back track simulation for new (TO US) events in the past?

		//	Build Event Queue for this frame.
		std::vector<EventBase*> eventsThisFrame;
		for (auto it = _events.begin(); it < _events.end(); ++it)
		{
			EventBase* myEvent = *it;

			if (myEvent->Frame() != _frame)
				continue;

			eventsThisFrame.push_back(myEvent);
		}
		
		//	Loop through all logic objects for all frames up to the current simulation frame.
		//	Populate _states array
		currentGameState->Tick(eventsThisFrame, previousGameState);

		for (auto it = currentGameState->_players.begin(); it < currentGameState->_players.end(); ++it)
		{
			PlayerState* myPlayerState = *it;

			_playerLogic->Tick(myPlayerState, previousGameState, eventsThisFrame);
		}

		_worldLogic->Tick(currentGameState->_world, previousGameState, eventsThisFrame);

		return currentGameState;
	}

	void SimulationManager::AddEvent(EventBase* newEvent)
	{
		ServerManager::Instance().SendMessage(newEvent);

		_events.push_back(newEvent);
	}
}