#include "PlayerLogic.h"

#include "..\PlayerState.h"
#include "..\GameState.h"
#include "Events\EventBase.h"
#include "Events\PlayerMoveEvent.h"
#include "Events\PlayerInteractEvent.h"

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

			case eEventType::PlayerInteract:
				OnPlayerInteract(thisPlayer, dynamic_cast<PlayerInteractEvent*>(myEvent));
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

	void PlayerLogic::OnPlayerInteract(PlayerState* thisPlayer, PlayerInteractEvent* playerInteractEvent)
	{
		if (thisPlayer->_id != playerInteractEvent->_ObjectID)
			return;

		thisPlayer->_amountOfWood++;
	}
}