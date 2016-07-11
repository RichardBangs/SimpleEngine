#pragma once

#include "RequestEventBase.h"

namespace Simulation
{
	class PlayerCreateRequestEvent : public RequestEventBase
	{
	public:
		PlayerCreateRequestEvent() {}
		virtual ~PlayerCreateRequestEvent() {}

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		virtual eRequestEventType GetType() { return eRequestEventType::PlayerCreate; }
	};
}