#pragma once

#include "BaseRenderable.h"
#include "VertexFormat.h"

#include <vector>

namespace Renderer
{
	class SimpleRenderable : public BaseRenderable
	{
	public:
		SimpleRenderable();
		virtual ~SimpleRenderable();

		void CreateFromList(std::vector<VertexFormat> vertices);

		virtual void Render();

	protected:
	private:

		unsigned int _vbo;
		unsigned int _triangleCount;
	};
}