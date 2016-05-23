#include "PlayerMoveEvent.h"

namespace Simulation
{
	PlayerMoveEvent::PlayerMoveEvent(int frame, int id, glm::vec3 position)
		: EventBase(frame)
	{
		_id = id;
		_Position = position;			
	}

	//virtual
	PlayerMoveEvent::~PlayerMoveEvent()
	{
	}
}