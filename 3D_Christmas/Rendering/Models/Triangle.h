#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Triangle : public Model
		{
		public:
			Triangle();
			~Triangle();
			void Create(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3, const glm::vec4& color);
			virtual void Update() override final;
			void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
		};
	}
}