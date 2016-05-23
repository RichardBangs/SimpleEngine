#pragma once

#include <assert.h>

namespace Utils
{
	template<typename T> T* Singleton<T>::_instance = NULL;

	template<typename T>
	inline T& Singleton<T>::Instance()
	{
		assert(_instance != NULL);
		return *_instance;
	}

	template<typename T>
	inline void Singleton<T>::Create()
	{
		assert(_instance == NULL);
		_instance = new T();
	}

	template<typename T>
	inline void Singleton<T>::Destroy()
	{
		assert(_instance != NULL);
		delete _instance;

		_instance = NULL;
	}
}