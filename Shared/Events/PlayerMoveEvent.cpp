#include "PlayerMoveEvent.h"

namespace Simulation
{
	PlayerMoveEvent::PlayerMoveEvent(int frame, int id, glm::vec3 position)
		: EventBase(frame)
	{
		_id = id;
		_Position = position;			
	}

	//virtual
	PlayerMoveEvent::~PlayerMoveEvent()
	{
	}

	//virtual
	void PlayerMoveEvent::PopulateFromJSON(web::json::object& json)
	{
		EventBase::PopulateFromJSON(json);

		_id = json.find(U("ID"))->second.as_integer();

		_Position = glm::vec3(json.find(U("x"))->second.as_double(), json.find(U("y"))->second.as_double(), json.find(U("z"))->second.as_double());
	}

	//virtual
	void PlayerMoveEvent::ToJSON(web::json::value& result)
	{
		EventBase::ToJSON(result);

		result[U("ID")] = web::json::value::number(_id);

		result[U("x")] = web::json::value::number(_Position.x);
		result[U("y")] = web::json::value::number(_Position.y);
		result[U("z")] = web::json::value::number(_Position.z);
	}
}