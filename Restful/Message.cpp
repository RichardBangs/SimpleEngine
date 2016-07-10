
#include "Message.h"

namespace Restful
{
	//static
	web::json::value Message::ToJSON(Message* message)
	{
		auto result = web::json::value::object();

		result[U("Frame")] = web::json::value::number((int)message->frame);
		result[U("Type")] = web::json::value::number((int)message->type);
		result[U("x")] = web::json::value::number(message->x);
		result[U("z")] = web::json::value::number(message->z);

		return result;
	}

	//static
	Message* Message::FromJSON(web::json::object& json)
	{
		auto newMessage = new Message();

		newMessage->frame = json.find(U("Frame"))->second.as_integer();
		newMessage->type = (MessageType)json.find(U("Type"))->second.as_integer();
		newMessage->x = json.find(U("x"))->second.as_integer();
		newMessage->z = json.find(U("z"))->second.as_integer();

		return newMessage;
	}
}