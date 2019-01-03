#pragma once
#include "glm/glm.hpp"

namespace Rendering
{
	struct VertexFormat
	{
		glm::vec3 position;
		glm::vec4 color;
		glm::vec3 normal;

		VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColor, const glm::vec3 &iNorm)
		{
			position = iPos;
			color = iColor;
			normal = iNorm;
		}

		VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColor)
		{
			position = iPos;
			color = iColor;
			normal = glm::vec3(0.0,1.0,0.0);
		}

		VertexFormat() {}
	};
}