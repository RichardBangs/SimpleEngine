#pragma once

#include <vector>

#include "Utils/Singleton.h"

namespace Renderer
{
	class BaseRenderable;

	class RenderableManager : public Utils::Singleton<RenderableManager>
	{
	public:
		RenderableManager();
		~RenderableManager();

		void AddRenderable(BaseRenderable* newRenderable);
		void RemoveRenderable(BaseRenderable* newRenderable);

		void Render();

		void DestroyAllRenderables();

	protected:
	private:
		static RenderableManager* _instance;

		std::vector<BaseRenderable*> _renderables;
	};
}
