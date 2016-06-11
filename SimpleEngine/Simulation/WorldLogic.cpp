#include "WorldLogic.h"

#include "WorldState.h"
#include "GameState.h"
#include "Events\EventBase.h"

namespace Simulation
{
	WorldLogic::WorldLogic()
	{

	}

	WorldLogic::~WorldLogic()
	{
	}

	void WorldLogic::Tick(WorldState* thisPlayer, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame)
	{
		for (auto it = eventsThisFrame.begin(); it < eventsThisFrame.end(); ++it)
		{
			EventBase* myEvent = *it;

			switch (myEvent->GetType())
			{

			}
		}
	}
}