#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class ObjectCreatedEvent : public EventBase
	{
	public:
		ObjectCreatedEvent(int frame, int id, int x, int y);
		virtual ~ObjectCreatedEvent();

		virtual eEventType GetType() { return eEventType::ObjectCreated; }

		int _id;

		int _x, _y;
	};
}