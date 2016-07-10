#include "ObjectCreatedEvent.h"

namespace Simulation
{
	ObjectCreatedEvent::ObjectCreatedEvent(int frame, int id, int x, int y)
		: EventBase(frame)
	{
		_id = id;
		_x = x;
		_y = y;
	}

	//virtual
	ObjectCreatedEvent::~ObjectCreatedEvent()
	{
	}

	//virtual
	void ObjectCreatedEvent::PopulateFromJSON(web::json::object& json)
	{
		EventBase::PopulateFromJSON(json);

		_id = json.find(U("ID"))->second.as_integer();
		_x = json.find(U("x"))->second.as_integer();
		_y = json.find(U("y"))->second.as_integer();
	}

	//virtual
	void ObjectCreatedEvent::ToJSON(web::json::value& result)
	{
		EventBase::ToJSON(result);

		result[U("ID")] = web::json::value::number(_id);
		result[U("x")] = web::json::value::number(_x);
		result[U("y")] = web::json::value::number(_y);
	}
}