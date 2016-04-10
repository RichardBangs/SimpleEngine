#pragma once

#include <vector>

namespace Renderer
{
	class BaseRenderable;

	class RenderableManager
	{
	public:
		inline static RenderableManager& Instance() { return *_instance; }
		inline static void Create() { new RenderableManager; }
		inline static void Destroy() { delete _instance; }

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
