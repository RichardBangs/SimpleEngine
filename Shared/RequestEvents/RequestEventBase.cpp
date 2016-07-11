#include "RequestEventBase.h"

#include "PlayerCreateRequestEvent.h"

namespace Simulation
{
	RequestEventBase::RequestEventBase()
	{
		_uuid = boost::uuids::random_generator()();
	}

	//virtual
	RequestEventBase::~RequestEventBase()
	{
	}

	//static
	RequestEventBase* RequestEventBase::CreateFromJSON(web::json::object& json)
	{
		eRequestEventType eventType = (eRequestEventType)json.find(U("Type"))->second.as_integer();

		RequestEventBase* myEvent = CreateFromType(eventType);
		myEvent->PopulateFromJSON(json);

		return myEvent;
	}

	//virtual
	void RequestEventBase::PopulateFromJSON(web::json::object& json)
	{
		_uuid = boost::uuids::uuid();

		auto uuidArray = json.find(U("UUID"))->second.as_array();
		int index = 0;
		for (auto it = uuidArray.begin(); it != uuidArray.end(); ++it)
		{
			_uuid.data[index++] = (uint8_t)((*it).as_integer());
		}
	}

	//virtual
	void RequestEventBase::ToJSON(web::json::value& result)
	{
		result[U("Type")] = web::json::value::number((int)GetType());

		std::vector<web::json::value> uuidArray;
		for (auto it = _uuid.begin(); it != _uuid.end(); ++it)
		{
			uuidArray.push_back(web::json::value::number(*it));
		}
		result[U("UUID")] = web::json::value::array(uuidArray);
	}

	//static
	RequestEventBase* RequestEventBase::CreateFromTypeCopy(RequestEventBase* original)
	{
		switch (original->GetType())
		{
		case eRequestEventType::PlayerCreate:
			return new PlayerCreateRequestEvent(*static_cast<const PlayerCreateRequestEvent*>(original));
		}

		assert("UNEXPECTED REQUEST EVENT TYPE.");

		return NULL;
	}

	//static
	RequestEventBase* RequestEventBase::CreateFromType(eRequestEventType eventType)
	{
		switch (eventType)
		{
		case eRequestEventType::PlayerCreate:
			return new PlayerCreateRequestEvent();
		}

		assert("UNEXPECTED REQUEST EVENT TYPE.");

		return NULL;
	}
}