#include "BaseRenderable.h"

#include "RenderableManager.h"

namespace Renderer
{
	BaseRenderable::BaseRenderable()
	{
		RenderableManager::Instance().AddRenderable(this);
	}

	//virtual
	BaseRenderable::~BaseRenderable()
	{
		RenderableManager::Instance().RemoveRenderable(this);
	}

	void BaseRenderable::SetShader(unsigned int program)
	{
		_program = program;
	}
}