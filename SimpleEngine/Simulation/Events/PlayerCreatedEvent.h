#pragma once

#include "EventBase.h"

namespace Simulation
{
	class PlayerCreatedEvent : public EventBase
	{
	public:
		PlayerCreatedEvent() {}
		PlayerCreatedEvent(int frame, int id);
		virtual ~PlayerCreatedEvent();

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		virtual eEventType GetType() { return eEventType::PlayerCreated; }

		int _id;
	};
}