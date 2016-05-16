#include "Player.h"

#include "InputManager.h"
#include "Renderer\Camera.h"

namespace Game
{
	Player::Player()
	{
		InputManager::Instance().RegisterForOnKeyboardInput(std::bind(&Player::OnKeyboardInput, this, std::placeholders::_1));
	}

	Player::~Player()
	{
	}

	void Player::Update()
	{
		Renderer::Camera::Instance().Position = _position;
	}

	void Player::OnKeyboardInput(char key)
	{
		switch (key)
		{
		case 'w':
			_position.y -= 0.1f;
			break;

		case 'a':
			_position.x += 0.1f;
			break;

		case 's':
			_position.y += 0.1f;
			break;

		case 'd':
			_position.x -= 0.1f;
			break;
		}
	}
}