#include "PlayerLogic.h"

#include "..\PlayerState.h"
#include "..\GameState.h"
#include "..\Events\EventBase.h"
#include "..\Events\PlayerMoveEvent.h"

namespace Simulation
{
	PlayerLogic::PlayerLogic()
	{

	}

	PlayerLogic::~PlayerLogic()
	{
	}

	void PlayerLogic::Tick(PlayerState* thisPlayer, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame)
	{
		for (auto it = eventsThisFrame.begin(); it < eventsThisFrame.end(); ++it)
		{
			EventBase* myEvent = *it;

			switch (myEvent->GetType())
			{
			case eEventType::PlayerMove:
				OnPlayerMove(thisPlayer, dynamic_cast<PlayerMoveEvent*>(myEvent));
				break;
			}
		}
	}

	void PlayerLogic::OnPlayerMove(PlayerState* thisPlayer, PlayerMoveEvent* playerMoveEvent)
	{
		if (thisPlayer->_id != playerMoveEvent->_id)
			return;

		thisPlayer->_Position = playerMoveEvent->_Position;
	}
}