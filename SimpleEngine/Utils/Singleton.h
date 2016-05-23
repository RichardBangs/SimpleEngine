#pragma once

namespace Utils
{
	template <typename T>
	class Singleton
	{
	public:
		static T& Instance();
		static void Create();
		static void Destroy();

	private:
		static T* _instance;
	};
}


#include "Singleton.inline.h"