#pragma once

#include <cpprest/json.h>
#include <map>

namespace Restful
{
	enum MessageType
	{
		PLAYER_CREATE,
		OBJECT_CREATE
	};

	class Message
	{
	public:
		int frame;

		MessageType type;
		int x, z;

		static Message* FromJSON(web::json::object& json);
		static web::json::value ToJSON(Message* message);
	};
}