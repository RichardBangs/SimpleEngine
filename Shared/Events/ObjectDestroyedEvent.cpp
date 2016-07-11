#include "ObjectDestroyedEvent.h"

namespace Simulation
{
	ObjectDestroyedEvent::ObjectDestroyedEvent(int frame, int id)
		: EventBase(frame)
	{
		_id = id;
	}

	//virtual
	ObjectDestroyedEvent::~ObjectDestroyedEvent()
	{
	}

	//virtual
	void ObjectDestroyedEvent::PopulateFromJSON(web::json::object& json)
	{
		EventBase::PopulateFromJSON(json);

		_id = json.find(U("ID"))->second.as_integer();
	}

	//virtual
	void ObjectDestroyedEvent::ToJSON(web::json::value& result)
	{
		EventBase::ToJSON(result);

		result[U("ID")] = web::json::value::number(_id);
	}
}