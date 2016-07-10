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

		void SendMessage(EventBase* eventBase);

	private:

		Restful::Server* _server;
	};
}