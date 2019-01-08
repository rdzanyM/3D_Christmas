#pragma once
#include "Model.h"
#include <stdarg.h>

namespace Rendering
{
	namespace Models
	{
		class Star : public Model
		{
		public:
			Star();
			~Star();

			void Create(double r, const glm::vec4& color);
			void Move(double x, double y, double z);
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
			virtual void Update() override final;
		};
	}
}