#pragma once

#include <cpprest/json.h>

namespace Simulation
{
	enum eEventType
	{
		PlayerCreated,
		PlayerMove,
		PlayerInteract,

		ObjectCreated
	};


	class EventBase
	{
	public:
		EventBase(int frame);

		virtual ~EventBase();

		virtual eEventType GetType() = 0;

		inline int Frame() { return _frame; }

		static EventBase* CreateFromJSON(web::json::object& json);

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

		bool operator== (const EventBase &other);

		static EventBase* CreateFromTypeCopy(EventBase* original);

	protected:
		EventBase() {}
		static EventBase* CreateFromType(eEventType eventType);

		int _frame;
	};
}