#pragma once

namespace Renderer
{
	class BaseRenderable
	{
	public:
		BaseRenderable();
		virtual ~BaseRenderable();

		virtual void Render() = 0;

	protected:

	private:
		
	};
}