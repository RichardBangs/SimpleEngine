#pragma once

#include "EventBase.h"

namespace Simulation
{
	class PlayerCreatedEvent : public EventBase
	{
	public:
		PlayerCreatedEvent(int frame, int id);
		virtual ~PlayerCreatedEvent();

		virtual eEventType GetType() { return eEventType::PlayerCreated; }

		int _id;
	};
}