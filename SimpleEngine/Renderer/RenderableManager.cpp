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
		for (auto it = _renderables.begin(); it != _renderables.end(); ++it)
		{
			if ((*it) != newRenderable)
				continue;

			_renderables.erase(it);
			break;
		}

		assert("Failed to remove renderable.");
	}

	void RenderableManager::Render()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//	Loop through and render all renderables :)
		std::vector<BaseRenderable*>::iterator it;
		for (it = _renderables.begin(); it < _renderables.end(); ++it)
		{
			BaseRenderable* renderable = static_cast<BaseRenderable*>(*it);

			renderable->Render();
		}
	}
}