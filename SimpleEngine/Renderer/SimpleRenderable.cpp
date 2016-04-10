#include "SimpleRenderable.h"

#include "glew.h"
#include "freeglut.h"

namespace Renderer
{
	SimpleRenderable::SimpleRenderable()
		: BaseRenderable()
	{
	}

	//virtual
	SimpleRenderable::~SimpleRenderable()
	{
		glDeleteBuffers(1, &_vbo);
	}

	void SimpleRenderable::CreateFromList(std::vector<VertexFormat> vertices)
	{
		_triangleCount = vertices.size();

		glGenBuffers(1, &_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * _triangleCount, &vertices[0], GL_STATIC_DRAW);
	}

	//virtual
	void SimpleRenderable::Render()
	{
		//	Position.
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
		
		//	Color.
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)12);

		
		glBindVertexBuffer(0, _vbo, 0, sizeof(VertexFormat));
		glDrawArrays(GL_TRIANGLES, 0, _triangleCount);
	}
}