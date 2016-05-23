#pragma once

#include <functional>
#include "Utils/Singleton.h"

namespace Game
{
	class InputManager : public Utils::Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

		void RegisterForOnKeyboardInput(std::function<void(char)> func);
		void OnKeyboardInput(char key);

		void RegisterForOnMouseInput(std::function<void(int,int,int,int)> func);
		void OnMouseInput(int button, int state, int x, int y);

	private:
		static InputManager* _instance;

		std::function<void(char)> _onKeyboardInput;

		std::function<void(int,int,int,int)> _onMouseInput;
	};
}