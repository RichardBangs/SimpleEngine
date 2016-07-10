#include "EventBase.h"

#include "PlayerCreatedEvent.h"
#include "PlayerInteractEvent.h"
#include "ObjectCreatedEvent.h"
#include "PlayerMoveEvent.h"


namespace Simulation
{
	EventBase::EventBase(int frame)
	{
		_frame = frame;
	}
	
	//virtual
	EventBase::~EventBase()
	{
	}

	//static
	EventBase* EventBase::CreateFromJSON(web::json::object& json)
	{
		eEventType eventType = (eEventType)json.find(U("Type"))->second.as_integer();

		EventBase* myEvent = CreateFromType(eventType);
		myEvent->PopulateFromJSON(json);

		return myEvent;
	}

	//virtual
	void EventBase::PopulateFromJSON(web::json::object& json)
	{
		_frame = json.find(U("Frame"))->second.as_integer();
	}

	//virtual
	void EventBase::ToJSON(web::json::value& result)
	{
		result[U("Frame")] = web::json::value::number((int)_frame);
		result[U("Type")] = web::json::value::number((int)GetType());
	}

	//static
	EventBase* EventBase::CreateFromType(eEventType eventType)
	{
		switch (eventType)
		{
		case eEventType::PlayerCreated:
			return new PlayerCreatedEvent();

		case eEventType::PlayerMove:
			return new PlayerMoveEvent();

		case eEventType::PlayerInteract:
			return new PlayerInteractEvent();

		case eEventType::ObjectCreated:
			return new ObjectCreatedEvent();
		}

		assert("UNEXPECTED EVENT TYPE.");

		return NULL;
	}
}