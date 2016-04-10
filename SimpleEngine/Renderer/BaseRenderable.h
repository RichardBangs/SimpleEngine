#pragma once

namespace Renderer
{
	class BaseRenderable
	{
	public:
		BaseRenderable();
		virtual ~BaseRenderable();

		virtual void Render() = 0;

		void SetShader(unsigned int program);

	protected:

	private:
		friend class RenderableManager;

		unsigned int _program;
	};
}