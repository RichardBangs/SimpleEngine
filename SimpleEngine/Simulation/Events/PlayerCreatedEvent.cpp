#include "PlayerCreatedEvent.h"

namespace Simulation
{
	PlayerCreatedEvent::PlayerCreatedEvent(int frame, int id)
		: EventBase(frame)
	{
		_id = id;
	}

	//virtual
	PlayerCreatedEvent::~PlayerCreatedEvent()
	{
	}
}