#include "ObjectCreatedEvent.h"

namespace Simulation
{
	ObjectCreatedEvent::ObjectCreatedEvent(int frame, int id, int x, int y)
		: EventBase(frame)
	{
		_id = id;
		_x = x;
		_y = y;
	}

	//virtual
	ObjectCreatedEvent::~ObjectCreatedEvent()
	{
	}
}