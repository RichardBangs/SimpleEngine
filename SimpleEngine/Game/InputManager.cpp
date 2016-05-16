#include "InputManager.h"

namespace Game
{
	InputManager* InputManager::_instance;

	InputManager::InputManager()
	{
		_instance = this;
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::RegisterForOnKeyboardInput(std::function<void(char)> func)
	{
		_onKeyboardInput = func;
	}

	void InputManager::OnKeyboardInput(char key)
	{
		_onKeyboardInput(key);
	}
}