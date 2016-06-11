#include "Player.h"

#include "World.h"

#include "InputManager.h"
#include "Renderer\Camera.h"
#include "Renderer\WindowManager.h"

#include "Renderer\SpriteRenderable.h"

#include "Simulation\SimulationManager.h"
#include "Simulation\Events\PlayerMoveEvent.h"
#include "Simulation\Events\PlayerInteractEvent.h"
#include "Simulation\PlayerState.h"

#include <iostream>

namespace Game
{
	Player::Player(int id, bool isLocalPlayer)
	{
		_isLocalPlayer = isLocalPlayer;

		if (isLocalPlayer)
		{
			InputManager::Instance().RegisterForOnKeyboardInput(std::bind(&Player::OnKeyboardInput, this, std::placeholders::_1));
			InputManager::Instance().RegisterForOnMouseInput(std::bind(&Player::OnMouseInput, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
		}

		_renderable = new Renderer::SpriteRenderable("Characters::Hero0", glm::vec2(0.1f, 0.1f));

		_id = id;
	}

	Player::~Player()
	{
	}

	void Player::UpdateView(Simulation::PlayerState* playerState, float dt)
	{
		this->_targetPosition = playerState->_Position;	//TODO: CANT DO THIS REALLY! Server needs to control tick by tick position...

		UpdateAnimation(dt);
		
		if(_isLocalPlayer)	//	TODO: This shouldn't be here.
			Renderer::Camera::Instance().Position = _position;

		_renderable->SetPosition(_position + glm::vec3(0.0f, 0.0f, -1.0f));
	}
	
	void Player::UpdateAnimation(float dt)
	{
		const float animationSpeed = 0.5f;	//	world units per second.

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
	}

	void Player::OnMouseInput(int button, int state, int x, int y)
	{
		const int leftMouseButton = 0;
		const int rightMouseButton = 1;
		const int mouseUpState = 1;

		if (state != mouseUpState)
			return;

		auto screenSize = Renderer::WindowManager::Instance().Size();
		glm::vec2 mouseClickInScreenSpace = glm::vec2((float)x / screenSize.x, (float)y / screenSize.y);

		glm::vec2 playerPositionInScreenSpace = glm::vec2(0.5f, 0.5f);

		glm::vec2 deltaPositionInScreenSpace = mouseClickInScreenSpace - playerPositionInScreenSpace;

		glm::vec3 targetPosition = _position + glm::vec3(deltaPositionInScreenSpace.x * World::WorldScale / Renderer::Camera::Instance().Scale.x,
			-deltaPositionInScreenSpace.y * World::WorldScale / Renderer::Camera::Instance().Scale.y,
			0.0f);

		targetPosition.x = glm::round(targetPosition.x * 10) / 10;
		targetPosition.y = glm::round(targetPosition.y * 10) / 10;
		targetPosition.z = glm::round(targetPosition.z * 10) / 10;

		if (button == leftMouseButton)
			TriggerMove(targetPosition);
		else if (button == rightMouseButton)
			TriggerInteract(targetPosition);
	}

	void Player::TriggerMove(glm::vec3 position)
	{
		auto myMoveEvent = new Simulation::PlayerMoveEvent(Simulation::SimulationManager::Instance().Frame() + 1, _id, position);
		Simulation::SimulationManager::Instance().AddEvent(myMoveEvent);
	}

	void Player::TriggerInteract(glm::vec3 position)
	{
		auto myMoveEvent = new Simulation::PlayerInteractEvent(Simulation::SimulationManager::Instance().Frame() + 1, _id, position);
		Simulation::SimulationManager::Instance().AddEvent(myMoveEvent);
	}
}