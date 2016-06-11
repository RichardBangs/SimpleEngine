#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class PlayerInteractEvent : public EventBase
	{
	public:
		PlayerInteractEvent(int frame, int id, glm::vec3 position);
		virtual ~PlayerInteractEvent();

		virtual eEventType GetType() { return eEventType::PlayerInteract; }

		glm::vec3 _Position;

		int _id;
	};
}