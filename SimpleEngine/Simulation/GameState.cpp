#include "GameState.h"

#include "PlayerState.h"
#include "Events\EventBase.h"
#include "Events\PlayerCreatedEvent.h"
#include "Events\ObjectCreatedEvent.h"

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
				
				auto newObjectEvent = dynamic_cast<ObjectCreatedEvent*>(myEvent);
				auto newTree = new WorldObjectStateTree(newObjectEvent->_id, newObjectEvent->_x, newObjectEvent->_y);

				_world->_objects.push_back(newTree);
			}
		}
	}
}