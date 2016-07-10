#include "Server.h"

#include "Simulation\Events\EventBase.h"

namespace Simulation
{
	ServerManager::ServerManager()
	{
		web::http::uri_builder uri(U("http://localhost:1234"));
		uri.append_path(U("test"));

		_server = new Restful::Server(uri.to_string());
		_server->open();
	}

	ServerManager::~ServerManager()
	{
		delete _server;
	}

	void ServerManager::SendMessage(EventBase* eventBase)
	{
		_server->send_message(eventBase);
	}

	void ServerManager::PollMessages()
	{
		_server->poll_messages();
	}
}