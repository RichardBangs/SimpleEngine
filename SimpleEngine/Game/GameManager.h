#pragma once

#include "glm.hpp"

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
		Player* _player;
	};
}