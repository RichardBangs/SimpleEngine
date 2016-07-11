#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class ObjectCreatedEvent : public EventBase
	{
	public:
		ObjectCreatedEvent() {}
		ObjectCreatedEvent(int frame, int id, int x, int y);
		virtual ~ObjectCreatedEvent();

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		virtual eEventType GetType() { return eEventType::ObjectCreated; }

		int _id;

		int _x, _y;
	};
}