#include "EventBase.h"

#include "PlayerCreatedEvent.h"
#include "PlayerInteractEvent.h"
#include "ObjectCreatedEvent.h"
#include "PlayerMoveEvent.h"
#include "ObjectDestroyedEvent.h"


namespace Simulation
{
	EventBase::EventBase(int frame)
	{
		_frame = frame;
		_uuid = boost::uuids::random_generator()();
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
		_uuid = boost::uuids::uuid();
		
		auto uuidArray = json.find(U("UUID"))->second.as_array();
		int index = 0;
		for (auto it = uuidArray.begin(); it != uuidArray.end(); ++it)
		{
			_uuid.data[index++] = (uint8_t)((*it).as_integer());
		}
	}

	//virtual
	void EventBase::ToJSON(web::json::value& result)
	{
		std::vector<web::json::value> uuidArray;
		for (auto it = _uuid.begin(); it != _uuid.end(); ++it)
		{
			uuidArray.push_back(web::json::value::number(*it));
		}
		result[U("UUID")] = web::json::value::array(uuidArray);

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

		case eEventType::ObjectDestroyed:
			return new ObjectDestroyedEvent(*static_cast<const ObjectDestroyedEvent*>(original));
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

		case eEventType::ObjectDestroyed:
			return new ObjectDestroyedEvent();
		}

		assert("UNEXPECTED EVENT TYPE.");

		return NULL;
	}
}