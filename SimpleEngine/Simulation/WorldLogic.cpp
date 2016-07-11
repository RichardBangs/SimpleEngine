#include "WorldLogic.h"

#include "WorldState.h"
#include "GameState.h"

#include "Events\ObjectDestroyedEvent.h"

namespace Simulation
{
	WorldLogic::WorldLogic()
	{

	}

	WorldLogic::~WorldLogic()
	{
	}

	void WorldLogic::Tick(WorldState* thisWorld, GameState* stateLastFrame, std::vector<EventBase*> eventsThisFrame)
	{
		for (auto it = eventsThisFrame.begin(); it < eventsThisFrame.end(); ++it)
		{
			EventBase* myEvent = *it;

			switch (myEvent->GetType())
			{
				case eEventType::ObjectDestroyed:
				{
					thisWorld->_objects.erase(static_cast<ObjectDestroyedEvent*>(myEvent)->_id);
				}
				break;
			}
		}
	}
}