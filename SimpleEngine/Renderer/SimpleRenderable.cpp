#include "SimpleRenderable.h"

#include "Camera.h"

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
		glGenBuffers(1, &_vbo);

		UpdateFromList(vertices);
	}

	void SimpleRenderable::UpdateFromList(std::vector<VertexFormat> vertices)
	{
		_triangleCount = vertices.size();

		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * _triangleCount, &vertices[0], GL_STATIC_DRAW);
	}

	//virtual
	void SimpleRenderable::Render()
	{
		VertexFormat::Bind();
		
		glUseProgram(_program);

		Camera::Instance().ApplyShaderConstant(_program);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);
		
		glUniform1i(_program, glGetUniformLocation(_program, "tex0"));
		
		glBindVertexBuffer(0, _vbo, 0, sizeof(VertexFormat));
		glDrawArrays(GL_TRIANGLES, 0, _triangleCount);
	}
}