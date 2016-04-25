#pragma once

#include "glm.hpp"
#include "glew.h"

namespace Renderer
{
	struct VertexFormat
	{
		glm::vec3 position;
		glm::vec4 color;
		glm::vec2 uv;

		VertexFormat(const glm::vec3 &pos, const glm::vec4 &col, const glm::vec2 &uv0)
		{
			position = pos;
			color = col;
			uv = uv0;
		}

		static void Bind()
		{
			//	Position.
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);

			//	Color.
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)12);

			//	UV.
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)28);
		}
	};
}