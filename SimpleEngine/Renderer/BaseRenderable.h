#pragma once

namespace Renderer
{
	class BaseRenderable
	{
	public:
		BaseRenderable();
		virtual ~BaseRenderable();

		virtual void Render() = 0;

		virtual void SetShader(unsigned int program);

	protected:

		unsigned int _program;

	private:
		friend class RenderableManager;
		
	};
}