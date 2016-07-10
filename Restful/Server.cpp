
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

		for (auto it = Local.begin(); it < Local.end(); ++it)
			delete *it;
		Local.clear();

		for (auto it = Remote.begin(); it < Remote.end(); ++it)
			delete *it;
		Remote.clear();
	}

	void Server::handle_post(web::http::http_request request)
	{
		ucout << "POST: " << request.to_string().c_str() << std::endl;

		auto query = web::http::uri::split_query(web::http::uri::decode(request.relative_uri().query()));
		
		auto myEvent = Simulation::EventBase::CreateFromJSON(request.extract_json().get().as_object());
		
		std::vector<Simulation::EventBase*>::iterator it;
		for (it = Local.begin(); it != Local.end(); ++it)
		{
			if ((*it)->Frame() > myEvent->Frame())
				break;
		}
		
		//	Local list is ALWAYS in order of event FRAME.
		if (Local.size() == 0)
			Local.push_back(myEvent);
		//else if (it == Local.begin())
			//Local.insert(it+1, myEvent);
		else
			Local.insert(it, myEvent);

		request.reply(status_codes::OK);
	}

	void Server::handle_get(web::http::http_request request)
	{
		ucout << "GET PROCESSED" << std::endl;

		request.reply(status_codes::OK, MessageListAsJSON(Local));
	}

	void Server::send_message(Simulation::EventBase* newEvent)
	{
		web::http::client::http_client webClient(web::http::uri_builder(U("http://localhost:1234")).append_path(U("test")).to_string());
		
		web::json::value& json = web::json::value::object();
		newEvent->ToJSON(json);

		webClient.request(web::http::methods::POST, U(""), json).wait();
	}

	void Server::poll_messages()
	{
		web::http::client::http_client webClient(web::http::uri_builder(U("http://localhost:1234")).append_path(U("test")).to_string());

		webClient.request(web::http::methods::GET).then([=](web::http::http_response reponse)
		{
			std::vector<Simulation::EventBase*> messages;

			MessageListFromJSON(messages, reponse.extract_json().get());

			auto oldList = Remote;
			Remote = messages;

			for (auto it = oldList.begin(); it < oldList.end(); ++it)
				delete *it;
			oldList.clear();
		});
	}

	web::json::value Server::MessageListAsJSON(std::vector<Simulation::EventBase*>& messages) const
	{
		auto result = web::json::value::array();
		
		int index = 0;
		for (auto it = messages.begin(); it != messages.end(); ++it)
		{
			web::json::value& json = web::json::value::object();
			(*it)->ToJSON(json);

			result[index++] = json;
		}

		return result;
	}

	void Server::MessageListFromJSON(std::vector<Simulation::EventBase*>& messages, web::json::value& json) const
	{
		auto myArray = json.as_array();

		for (auto it = myArray.begin(); it != myArray.end(); ++it)
		{
			auto myEvent = Simulation::EventBase::CreateFromJSON((*it).as_object());
			messages.push_back(myEvent);
		}
	}
}