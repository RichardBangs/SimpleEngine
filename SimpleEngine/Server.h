#pragma once

#include "Utils\Singleton.h"

#include "../Restful/Server.h"
#include "../Restful/Message.h"

#include <vector>

namespace Simulation
{
	class EventBase;
	class RequestEventBase;

	enum eServerMode
	{
		Client=1,
		Server=2
	};

	class ServerManager : public Utils::Singleton<ServerManager>
	{
	public:
		ServerManager();
		~ServerManager();

		void Start();

		bool IsClient() { return (_networkMode & eServerMode::Client) != 0; }
		bool IsServer() { return (_networkMode & eServerMode::Server) != 0; }

		void PollMessages();
		void SendMessage(RequestEventBase* eventBase);
		
		void AddMessage(Simulation::EventBase* message) { _server->AddMessage(message); }
		
		std::vector<Simulation::EventBase*> RemoteMessages() { return _server->RemoteMessages(); }
		std::vector<Simulation::RequestEventBase*> IncomingMessages() { return _server->GetIncomingRequests(); }
		void ClearIncomingMessages() { _server->ClearIncomingMessages(); }

	private:

		int _networkMode;

		Restful::Server* _server;

		std::vector<EventBase*> _messages;
	};
}