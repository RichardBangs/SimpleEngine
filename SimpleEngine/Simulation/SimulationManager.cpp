#include "SimulationManager.h"

#include "../Server.h"
#include "Logic\PlayerLogic.h"
#include "WorldLogic.h"
#include "GameState.h"

#include "RequestEvents\RequestEventBase.h"
#include "Events\EventBase.h"


namespace Simulation
{
	SimulationManager::SimulationManager()
	{
		_frame = 0;
		_playerLogic = new PlayerLogic();
		_worldLogic = new WorldLogic();

		_ticksUntilNextServerPoll = 0;
	}

	SimulationManager::~SimulationManager()
	{
		delete _playerLogic;
		delete _worldLogic;
	}

	GameState* SimulationManager::Tick()
	{
		//	TODO: Sort out allocations in this function (and those below it in the callstack!!!!).

		int runFromTick = 0;

		if (_ticksUntilNextServerPoll == 0)
		{
			ServerManager::Instance().PollMessages();
			_ticksUntilNextServerPoll = 30;
		}
		_events = ServerManager::Instance().RemoteMessages();
		std::vector<EventBase*>::iterator itLocal = _local.begin();
		std::vector<EventBase*>::iterator itRemote = _events.begin();
		bool isFirst = true;
		do
		{
			if (isFirst)
				isFirst = false;
			else
			{
				++itLocal;
				++itRemote;
			}

			if (itLocal == _local.end() || itRemote == _events.end())
				break;

			runFromTick = (*itLocal)->Frame();

		} while (**itLocal == **itRemote);

		if (_local.size() == _events.size())
			runFromTick = _frame;
		else
		{
			runFromTick = (*itRemote)->Frame();

			if (runFromTick > _states.size())
			{
				runFromTick = _states.size();
			}
		}

		while(!_local.empty() && _local.back()->Frame() >= runFromTick)
		{
			_local.pop_back();
		}

		_ticksUntilNextServerPoll--;

		_frame++;

		std::cout << runFromTick << " " << _frame << std::endl;

		for (int tick = runFromTick; tick < _frame; ++tick)
		{
			GameState* previousGameState;

			if(tick==0)
			{
				previousGameState = new GameState(-1);	//	Empty gamestate! Happens at the start of the game.
			}
			else
			{
				previousGameState = _states[tick-1];
			}

			GameState* currentGameState = new GameState(tick);
			if (_states.size() == tick)
				_states.push_back(currentGameState);
			else
			{
				delete _states[tick];
				_states[tick] = currentGameState;
			}

			//	TODO: Potentially back track simulation for new (TO US) events in the past?

			//	Build Event Queue for this frame.
			std::vector<EventBase*> eventsThisFrame;
			for (auto it = _events.begin(); it < _events.end(); ++it)
			{
				EventBase* myEvent = *it;

				if (myEvent->Frame() != tick)
					continue;

				eventsThisFrame.push_back(myEvent);
				_local.push_back(EventBase::CreateFromTypeCopy(myEvent));
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

			if (tick == 0)
				delete previousGameState;
		}

		return _states[_frame-1];
	}

	void SimulationManager::RequestEvent(RequestEventBase* newEvent)
	{
		ServerManager::Instance().SendMessage(newEvent);

		std::cout << "ADDEVENT: " << newEvent->GetType() << std::endl;
	}
}