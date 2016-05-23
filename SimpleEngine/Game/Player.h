#pragma once

#include "glm.hpp"

namespace Renderer { class SpriteRenderable; }

namespace Game
{
	class Player
	{
	public:
		Player();
		~Player();

		void Update(float dt);

		void UpdateAnimation(float dt);
	
	private:

		void OnKeyboardInput(char key);
		void OnMouseInput(int button, int state, int x, int y);

		Renderer::SpriteRenderable* _renderable;

		glm::vec3 _position;
		glm::vec3 _targetPosition;
	};
}