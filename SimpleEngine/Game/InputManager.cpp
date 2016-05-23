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

	void InputManager::RegisterForOnMouseInput(std::function<void(int, int, int, int)> func)
	{
		_onMouseInput = func;
	}

	void InputManager::OnMouseInput(int button, int state, int x, int y)
	{
		_onMouseInput(button, state, x, y);
	}
}