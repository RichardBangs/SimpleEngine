#pragma once

#include <cpprest/json.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace Simulation
{
	enum eRequestEventType
	{
		PlayerCreate,
	};


	class RequestEventBase
	{
	public:
		RequestEventBase();

		virtual ~RequestEventBase();

		virtual eRequestEventType GetType() = 0;

		inline boost::uuids::uuid UUID() { return _uuid; }

		static RequestEventBase* CreateFromJSON(web::json::object& json);

		RequestEventBase* CreateFromTypeCopy(RequestEventBase* original);

		virtual void PopulateFromJSON(web::json::object& json);
		virtual void ToJSON(web::json::value& result);

	protected:
		static RequestEventBase* CreateFromType(eRequestEventType eventType);

		boost::uuids::uuid _uuid;
	};
}