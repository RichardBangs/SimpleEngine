#pragma once

#include "EventBase.h"

#include "glm.hpp"

namespace Simulation
{
	class PlayerMoveEvent : public EventBase
	{
	public:
		PlayerMoveEvent() {}
		PlayerMoveEvent(int frame, int id, glm::vec3 position);
		virtual ~PlayerMoveEvent();

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		virtual eEventType GetType() { return eEventType::PlayerMove; }

		glm::vec3 _Position;

		int _id;
	};
}