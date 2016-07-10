#pragma once

#include "Utils\Singleton.h"

#include "../Restful/Server.h"
#include "../Restful/Message.h"

#include <vector>

namespace Simulation
{
	class EventBase;

	class ServerManager : public Utils::Singleton<ServerManager>
	{
	public:
		ServerManager();
		~ServerManager();

		void PollMessages();
		void SendMessage(EventBase* eventBase);

		std::vector<Simulation::EventBase*> RemoteMessages() { return _server->RemoteMessages(); }

	private:

		Restful::Server* _server;

		std::vector<EventBase*> _messages;
	};
}