#pragma once

#include <cpprest\http_headers.h>
#include <cpprest\http_listener.h>

#include <vector>

namespace Simulation { class EventBase; }

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

		void send_message(Simulation::EventBase* newEvent);
		void poll_messages();

		std::vector<Simulation::EventBase*> RemoteMessages() { return Remote; }

	private:

		web::json::value MessageListAsJSON(std::vector<Simulation::EventBase*>& messages) const;
		void MessageListFromJSON(std::vector<Simulation::EventBase*>& messages, web::json::value& json) const;

		void handle_post(web::http::http_request message);
		void handle_get(web::http::http_request request);

		std::vector<Simulation::EventBase*> Local;
		std::vector<Simulation::EventBase*> Remote;
	};
}