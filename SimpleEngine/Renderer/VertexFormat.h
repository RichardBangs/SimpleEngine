#pragma once

#include "glm.hpp"

namespace Renderer
{
	struct VertexFormat
	{
		glm::vec3 position;

		VertexFormat(const glm::vec3 &pos)
		{
			position = pos;
		}
	};
}