#pragma once

#include <cpprest/json.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace Simulation
{
	enum eEventType
	{
		PlayerCreateRequest,

		PlayerCreated,
		PlayerMove,
		PlayerInteract,

		ObjectCreated,
		ObjectDestroyed
	};


	class EventBase
	{
	public:
		EventBase(int frame);

		virtual ~EventBase();

		virtual eEventType GetType() = 0;

		inline int Frame() { return _frame; }
		inline boost::uuids::uuid UUID() { return _uuid; }

		static EventBase* CreateFromJSON(web::json::object& json);

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		bool operator== (const EventBase &other);

		static EventBase* CreateFromTypeCopy(EventBase* original);

	protected:
		EventBase() {}
		static EventBase* CreateFromType(eEventType eventType);

		int _frame;

		boost::uuids::uuid _uuid;
	};
}