#include "Player.h"

#include "World.h"

#include "InputManager.h"
#include "Renderer\Camera.h"
#include "Renderer\WindowManager.h"

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

	void Player::Update(float dt)
	{
		UpdateAnimation(dt);

		Renderer::Camera::Instance().Position = _position;
	}

	void Player::UpdateAnimation(float dt)
	{
		const float animationSpeed = 2.0f;	//	world units per second.

		float maxDistanceThisUpdate = animationSpeed * dt;

		glm::vec3 deltaPosition = _targetPosition - _position;
		
		if (glm::length(deltaPosition) <= maxDistanceThisUpdate)
		{
			_position = _targetPosition;
			return;
		}

		_position += glm::normalize(deltaPosition) * maxDistanceThisUpdate;
	}

	void Player::OnKeyboardInput(char key)
	{
		switch (key)
		{
		case 'w':
			_position.y += 0.1f;
			break;

		case 'a':
			_position.x -= 0.1f;
			break;

		case 's':
			_position.y -= 0.1f;
			break;

		case 'd':
			_position.x += 0.1f;
			break;
		}
	}

	void Player::OnMouseInput(int button, int state, int x, int y)
	{
		const int leftMouseButton = 0;
		const int mouseUpState = 1;

		if (button != leftMouseButton)
			return;

		if (state != mouseUpState)
			return;

		auto screenSize = Renderer::WindowManager::Instance().Size();
		glm::vec2 mouseClickInScreenSpace = glm::vec2((float)x / screenSize.x, (float)y / screenSize.y);

		glm::vec2 playerPositionInScreenSpace = glm::vec2(0.5f, 0.5f);

		glm::vec2 deltaPositionInScreenSpace = mouseClickInScreenSpace - playerPositionInScreenSpace;

		_targetPosition = _position + glm::vec3(deltaPositionInScreenSpace.x * World::WorldScale / Renderer::Camera::Instance().Scale.x,
			-deltaPositionInScreenSpace.y * World::WorldScale / Renderer::Camera::Instance().Scale.y,
			0.0f);
	}
}