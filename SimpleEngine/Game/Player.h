#pragma once

#include "glm.hpp"

namespace Game
{
	class Player
	{
	public:
		Player();
		~Player();

		void Update();
	
	private:

		void OnKeyboardInput(char key);
		void OnMouseInput(int button, int state, int x, int y);

		glm::vec3 _position;
	};
}