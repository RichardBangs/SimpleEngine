#pragma once

#include "glm.hpp"

namespace Renderer { class SpriteRenderable; }
namespace Simulation { class PlayerState; }

namespace Game
{
	class Player
	{
	public:
		Player(int id, bool isLocalPlayer);
		~Player();

		void UpdateAnimation(float dt);

		void UpdateView(Simulation::PlayerState* playerState, float dt);
		void UpdateController();
	
	private:

		void OnKeyboardInput(char key);
		void OnMouseInput(int button, int state, int x, int y);

		Renderer::SpriteRenderable* _renderable;

		glm::vec3 _position;
		glm::vec3 _targetPosition;

		int _id;
		bool _isLocalPlayer;
	};
}