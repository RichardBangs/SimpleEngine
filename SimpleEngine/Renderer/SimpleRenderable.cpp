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
		glGenVertexArrays(1, &_vao);
		glBindVertexArray(_vao);

		glGenBuffers(1, &_vbo);

		UpdateFromList(vertices);
	}

	void SimpleRenderable::UpdateFromList(std::vector<VertexFormat> vertices)
	{
		_triangleCount = vertices.size();

		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * _triangleCount, &vertices[0], GL_STATIC_DRAW);

		glEnableVertexArrayAttrib(_vao, 0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);
	}
	
	//virtual
	void SimpleRenderable::Render()
	{
		VertexFormat::Bind();

		glUseProgram(_program);

		glUniform4f(glGetUniformLocation(_program, "worldPosition"), _position.x, _position.y, _position.z, 0.0f);

		Camera::Instance().ApplyShaderConstant(_program);

		//	Use nearest only filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);
				
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBindVertexArray(_vao);
		glDrawArrays(GL_TRIANGLES, 0, _triangleCount);
	}
}