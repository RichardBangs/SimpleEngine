#pragma once

#include "LogicBase.h"

#include <vector>

namespace Simulation
{
	class EventBase;
	class GameState;
	class PlayerState;
	class PlayerMoveEvent;
	class PlayerInteractEvent;

	class PlayerLogic : public LogicBase<PlayerState>
	{
	public:
		PlayerLogic();
		~PlayerLogic();

		virtual void Tick(PlayerState* thisPlayer, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame);

		void OnPlayerMove(PlayerState* thisPlayer, PlayerMoveEvent* playerMoveEvent);
		void OnPlayerInteract(PlayerState* thisPlayer, PlayerInteractEvent* playerInteractEvent);
	};
}