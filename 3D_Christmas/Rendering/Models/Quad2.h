#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Quad2 : public Model	//this quad has more vertices (especially near the center). Used to represent the ground more accurately.
		{
		public:
			Quad2();
			~Quad2();
			void Create(double x, double y, double z, double r, double r2, const glm::vec4& color);
			virtual void Update() override final;
			void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
		};
	}
}