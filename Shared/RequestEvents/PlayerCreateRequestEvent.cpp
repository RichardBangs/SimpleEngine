#include "PlayerCreateRequestEvent.h"

namespace Simulation
{
	//virtual
	void PlayerCreateRequestEvent::PopulateFromJSON(web::json::object& json)
	{
		RequestEventBase::PopulateFromJSON(json);
	}

	//virtual
	void PlayerCreateRequestEvent::ToJSON(web::json::value& result)
	{
		RequestEventBase::ToJSON(result);
	}
}