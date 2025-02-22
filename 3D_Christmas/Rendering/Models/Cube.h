#pragma once
#include "Model.h"
#include <stdarg.h>

namespace Rendering
{
	namespace Models
	{
		class Cube : public Model
		{
		public:
			Cube();
			~Cube();

			void Create(double x, double y, double z, double r, const glm::vec4& color);
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
			virtual void Update() override final;
		};
	}
}