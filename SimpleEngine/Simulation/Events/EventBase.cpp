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

	bool EventBase::operator== (const EventBase &other)
	{
		return _frame == other._frame;
	}

	//static
	EventBase* EventBase::CreateFromTypeCopy(EventBase* original)
	{
		switch (original->GetType())
		{
		case eEventType::PlayerCreated:
			return new PlayerCreatedEvent(*static_cast<const PlayerCreatedEvent*>(original));

		case eEventType::PlayerMove:
			return new PlayerMoveEvent(*static_cast<const PlayerMoveEvent*>(original));

		case eEventType::PlayerInteract:
			return new PlayerInteractEvent(*static_cast<const PlayerInteractEvent*>(original));

		case eEventType::ObjectCreated:
			return new ObjectCreatedEvent(*static_cast<const ObjectCreatedEvent*>(original));
		}

		assert("UNEXPECTED EVENT TYPE.");

		return NULL;
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