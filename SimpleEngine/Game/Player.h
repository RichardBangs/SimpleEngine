#pragma once

#include "glm.hpp"

namespace Renderer { class SpriteRenderable; }
namespace Simulation
{
	class PlayerState;
	class GameState;
}

namespace Game
{
	class Player
	{
	public:
		Player(int id, bool isLocalPlayer);
		~Player();

		void UpdateAnimation(float dt);

		void UpdateView(Simulation::PlayerState* playerState, Simulation::GameState* gameState, float dt);
	
	private:

		void OnKeyboardInput(char key);
		void OnMouseInput(int button, int state, int x, int y);

		void TriggerMove(glm::vec3 position);
		void TriggerInteract(glm::vec3 position);

		Renderer::SpriteRenderable* _renderable;

		glm::vec3 _position;
		glm::vec3 _targetPosition;

		int _id;
		bool _isLocalPlayer;

		Simulation::GameState* latestGameState;
	};
}