#pragma once

#include "glm.hpp"

namespace Renderer { class QuadRenderable; }

namespace Game
{
	class World;

	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		void OnUpdate(float dt);
		void OnRender();

	private:

		World* _world;
	};
}