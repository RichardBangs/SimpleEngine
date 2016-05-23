#include "GameState.h"

#include "PlayerState.h"
#include "Events\EventBase.h"
#include "Events\PlayerCreatedEvent.h"

namespace Simulation
{
	GameState::GameState(int frame)
	{
		_frame = frame;
	}

	GameState::~GameState()
	{
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
			}
		}
	}
}