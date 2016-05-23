#pragma once

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

	private:

		World* _world;
		std::map<int, Player*> _players;

		int _idOfLocalPlayer;
	};
}