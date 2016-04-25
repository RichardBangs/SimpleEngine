#include "RenderableManager.h"

#include "BaseRenderable.h"

#include "glew.h"
#include "glut.h"

namespace Renderer
{
	//static
	RenderableManager* RenderableManager::_instance;

	RenderableManager::RenderableManager()
	{
		RenderableManager::_instance = this;
	}

	RenderableManager::~RenderableManager()
	{
		RenderableManager::_instance = NULL;

		DestroyAllRenderables();

		_renderables.clear();
	}

	void RenderableManager::DestroyAllRenderables()
	{
		std::vector<BaseRenderable*>::iterator it;
		for (it = _renderables.begin(); it < _renderables.end(); ++it)
		{
			BaseRenderable* renderable = static_cast<BaseRenderable*>(*it);

			delete renderable;
		}
	}

	void RenderableManager::AddRenderable(BaseRenderable* newRenderable)
	{
		_renderables.push_back(newRenderable);
	}

	void RenderableManager::RemoveRenderable(BaseRenderable* newRenderable)
	{
		//	TODO: Implement me.
	}

	void RenderableManager::Render()
	{
		std::vector<BaseRenderable*>::iterator it;
		for (it = _renderables.begin(); it < _renderables.end(); ++it)
		{
			BaseRenderable* renderable = static_cast<BaseRenderable*>(*it);

			renderable->Render();
		}
	}
}