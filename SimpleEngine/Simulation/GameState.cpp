#include "GameState.h"

#include "PlayerState.h"
#include "Events\EventBase.h"
#include "Events\PlayerCreatedEvent.h"
#include "Events\ObjectCreatedEvent.h"
#include "Events\ObjectDestroyedEvent.h"

#include "WorldState.h"

#include "WorldObjectStateTree.h"

namespace Simulation
{
	GameState::GameState(int frame)
	{
		_frame = frame;

		_world = new WorldState();
	}

	GameState::~GameState()
	{
		delete _world;
	}

	void GameState::Tick(std::vector<EventBase*> eventsThisTick, GameState* previousGameState)
	{
		//	Create one PlayerState for each of the previous frames player states.
		for (auto it = previousGameState->_players.begin(); it < previousGameState->_players.end(); ++it)
		{
			_players.push_back(new PlayerState(**it));
		}

		for (auto it = previousGameState->_world->_objects.begin(); it != previousGameState->_world->_objects.end(); ++it)
		{
			_world->_objects[it->first] = it->second;
		}

		//	Create one PlayerState for each PlayerCreated event.
		for (auto it = eventsThisTick.begin(); it < eventsThisTick.end(); ++it)
		{
			EventBase* myEvent = *it;

			switch (myEvent->GetType())
			{
			case eEventType::PlayerCreated:
				_players.push_back(new PlayerState(dynamic_cast<PlayerCreatedEvent*>(myEvent)->_id));
				break;

			case eEventType::ObjectCreated:
				
				 CreateObject(myEvent);

				break;

			case eEventType::ObjectDestroyed:

				auto deadObjectEvent = dynamic_cast<ObjectDestroyedEvent*>(myEvent);

				_world->_objects.erase(deadObjectEvent->_id);

				break;
			}
		}
	}

	void GameState::CreateObject(EventBase* eventBase)
	{
		auto newObjectEvent = dynamic_cast<ObjectCreatedEvent*>(eventBase);

		auto newObjectState = new WorldObjectStateTree(newObjectEvent->_id, newObjectEvent->_x, newObjectEvent->_y);

		_world->_objects[newObjectState->_id] = newObjectState;
	}
}
