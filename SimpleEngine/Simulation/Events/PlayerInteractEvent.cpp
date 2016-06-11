#include "PlayerInteractEvent.h"

namespace Simulation
{
	PlayerInteractEvent::PlayerInteractEvent(int frame, int id, glm::vec3 position)
		: EventBase(frame)
	{
		_Position = position;
		_id = id;
	}
	
	//virtual
	PlayerInteractEvent::~PlayerInteractEvent()
	{
	}
}