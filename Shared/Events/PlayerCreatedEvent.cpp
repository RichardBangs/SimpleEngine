#include "PlayerCreatedEvent.h"

namespace Simulation
{
	PlayerCreatedEvent::PlayerCreatedEvent(int frame, int id)
		: EventBase(frame)
	{
		_id = id;
	}

	//virtual
	PlayerCreatedEvent::~PlayerCreatedEvent()
	{
	}

	//virtual
	void PlayerCreatedEvent::PopulateFromJSON(web::json::object& json)
	{
		EventBase::PopulateFromJSON(json);

		_id = json.find(U("ID"))->second.as_integer();
	}

	//virtual
	void PlayerCreatedEvent::ToJSON(web::json::value& result)
	{
		EventBase::ToJSON(result);

		result[U("ID")] = web::json::value::number(_id);
	}
}