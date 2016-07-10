#include "PlayerInteractEvent.h"

namespace Simulation
{
	PlayerInteractEvent::PlayerInteractEvent(int frame, int id, glm::vec3 position)
		: EventBase(frame)
	{
		_Position = position;
		_id = id;
	}
	
	//virtual
	PlayerInteractEvent::~PlayerInteractEvent()
	{
	}

	//virtual
	void PlayerInteractEvent::PopulateFromJSON(web::json::object& json)
	{
		EventBase::PopulateFromJSON(json);

		_id = json.find(U("ID"))->second.as_integer();

		_Position = glm::vec3(json.find(U("x"))->second.as_double(), json.find(U("y"))->second.as_double(), json.find(U("z"))->second.as_double());
	}

	//virtual
	void PlayerInteractEvent::ToJSON(web::json::value& result)
	{
		EventBase::ToJSON(result);

		result[U("ID")] = web::json::value::number(_id);
		
		result[U("x")] = web::json::value::number(_Position.x);
		result[U("y")] = web::json::value::number(_Position.y);
		result[U("z")] = web::json::value::number(_Position.z);
	}
}