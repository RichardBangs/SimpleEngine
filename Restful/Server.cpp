
#include "Server.h"

#include <cpprest\http_client.h>
#include <stdio.h>

#include "../SimpleEngine/Simulation/Events/EventBase.h"

#include "Message.h"

using namespace web::http;

namespace Restful
{
	Server::Server(utility::string_t address)
	{
		ucout << "LISTENING ON: " << address << std::endl;

		listener = new web::http::experimental::listener::http_listener(address);

		listener->support(methods::GET, std::bind(&Server::handle_get, this, std::placeholders::_1));
		listener->support(methods::POST, std::bind(&Server::handle_post, this, std::placeholders::_1));
	}

	Server::~Server()
	{
		delete listener;

		for (auto it = Events.begin(); it < Events.end(); ++it)
		{
			auto myEvent = *it;

			delete myEvent;
		}
		Events.clear();
	}

	void Server::handle_post(web::http::http_request request)
	{
		ucout << "POST: " << request.to_string().c_str() << std::endl;

		auto query = web::http::uri::split_query(web::http::uri::decode(request.relative_uri().query()));
		
		auto myEvent = Simulation::EventBase::CreateFromJSON(request.extract_json().get().as_object());
		
		Events.push_back(myEvent);

		request.reply(status_codes::OK);
	}

	void Server::handle_get(web::http::http_request request)
	{
		ucout << "GET PROCESSED" << std::endl;

		request.reply(status_codes::OK, MessageListAsJSON());
	}

	void Server::send_message(Simulation::EventBase* newEvent)
	{
		web::http::client::http_client webClient(web::http::uri_builder(U("http://localhost:1234")).append_path(U("test")).to_string());
		
		web::json::value& json = web::json::value::object();
		newEvent->ToJSON(json);

		webClient.request(web::http::methods::POST, U(""), json).wait();
	}

	web::json::value Server::MessageListAsJSON()
	{
		auto result = web::json::value::array();
		
		int index = 0;
		for (auto it = Events.begin(); it != Events.end(); ++it)
		{
			web::json::value& json = web::json::value::object();
			(*it)->ToJSON(json);

			result[index++] = json;
		}

		return result;
	}
}