#pragma once

#include <cpprest\http_headers.h>
#include <cpprest\http_listener.h>

#include <vector>

namespace Simulation { class EventBase; class RequestEventBase; }

namespace Restful
{
	class Server
	{
	public:
		Server(utility::string_t address);
		~Server();

		pplx::task<void> open() { return listener->open(); }
		pplx::task<void> close() { return listener->close(); }

		web::http::experimental::listener::http_listener* listener;

		static void send_message(Simulation::RequestEventBase* newEvent);
		static void poll_messages();

		bool checkForServer();

		std::vector<Simulation::EventBase*> RemoteMessages() { return Remote; }
		std::vector<Simulation::RequestEventBase*> GetIncomingRequests() { return IncomingRequests; }
		void ClearIncomingMessages() { IncomingRequests.clear(); }

		void AddMessage(Simulation::EventBase* message);

	private:

		static web::json::value MessageListAsJSON(std::vector<Simulation::EventBase*>& messages);
		static void MessageListFromJSON(std::vector<Simulation::EventBase*>& messages, web::json::value& json);

		void handle_post(web::http::http_request message);
		void handle_get(web::http::http_request request);

		std::vector<Simulation::RequestEventBase*> IncomingRequests;

		std::vector<Simulation::EventBase*> Local;
		static std::vector<Simulation::EventBase*> Remote;
	};
}