#include "Server.h"

#include "RequestEvents\RequestEventBase.h"

namespace Simulation
{
	ServerManager::ServerManager()
	{
	}

	ServerManager::~ServerManager()
	{
		delete _server;
	}

	void ServerManager::Start()
	{
		_networkMode = eServerMode::Client;

		if (!_server->checkForServer())
		{
			std::cout << "SERVER NOT FOUND - STARTING NEW SERVER" << std::endl;

			web::http::uri_builder uri(U("http://localhost:1234"));
			uri.append_path(U("test"));

			_server = new Restful::Server(uri.to_string());
			_server->open();

			_networkMode |= eServerMode::Server;
		}
	}

	void ServerManager::SendMessage(RequestEventBase* eventBase)
	{
		Restful::Server::send_message(eventBase);
	}

	void ServerManager::PollMessages()
	{
		Restful::Server::poll_messages();
	}
}