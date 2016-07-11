#pragma once

#include <boost\uuid\uuid.hpp>

#include "glm.hpp"

#include <map>

namespace Renderer { class QuadRenderable; }

namespace Game
{
	class World;
	class Player;

	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void OnUpdate(float dt);
		void OnRender();

		void ServerUpdate();
		void ClientUpdate(float dt);

	private:

		World* _world;
		std::map<int, Player*> _players;

		boost::uuids::uuid _uuidOfLocalPlayerCreation;
		int _idOfLocalPlayer;
	};
}