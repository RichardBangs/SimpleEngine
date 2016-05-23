#include "Player.h"

#include "InputManager.h"
#include "Renderer\Camera.h"

#include <iostream>

namespace Game
{
	Player::Player()
	{
		InputManager::Instance().RegisterForOnKeyboardInput(std::bind(&Player::OnKeyboardInput, this, std::placeholders::_1));
		InputManager::Instance().RegisterForOnMouseInput(std::bind(&Player::OnMouseInput, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
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

	void Player::OnMouseInput(int button, int state, int x, int y)
	{
		std::cout << button << "," << state << "," << x << "," << y << std::endl;
	}
}