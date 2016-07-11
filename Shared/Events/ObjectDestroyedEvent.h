#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class ObjectDestroyedEvent : public EventBase
	{
	public:
		ObjectDestroyedEvent() {}
		ObjectDestroyedEvent(int frame, int id);
		virtual ~ObjectDestroyedEvent();

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		virtual eEventType GetType() { return eEventType::ObjectDestroyed; }

		int _id;
	};
}