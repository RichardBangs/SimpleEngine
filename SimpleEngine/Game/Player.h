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

		glm::vec3 _position;
	};
}