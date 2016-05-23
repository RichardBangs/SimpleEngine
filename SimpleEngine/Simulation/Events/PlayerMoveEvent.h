#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class PlayerMoveEvent : public EventBase
	{
	public:
		PlayerMoveEvent(int frame, int id, glm::vec3 position);
		virtual ~PlayerMoveEvent();

		virtual eEventType GetType() { return eEventType::PlayerMove; }

		glm::vec3 _Position;

		int _id;
	};
}