#pragma once
#include "Model.h"
#include <stdarg.h>

namespace Rendering
{
	namespace Models
	{
		class Gift : public Model
		{
		public:
			Gift();
			~Gift();

			void Create(double x, double y, double z, double dx, double dy, double dz, const glm::vec4& boxColor, const glm::vec4& tapeColor);
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
			virtual void Update() override final;
		};
	}
}