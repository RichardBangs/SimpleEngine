#pragma once

#include <functional>

namespace Game
{
	class InputManager
	{
	public:
		inline static InputManager& Instance() { return *_instance; }
		inline static void Create() { new InputManager; }
		inline static void Destroy() { delete _instance; }

		InputManager();
		~InputManager();

		void RegisterForOnKeyboardInput(std::function<void(char)> func);
		void OnKeyboardInput(char key);
	
	private:
		static InputManager* _instance;

		std::function<void(char)> _onKeyboardInput;
	};
}