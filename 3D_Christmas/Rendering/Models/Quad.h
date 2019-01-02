#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Quad : public Model
		{
		public:
			Quad();
			~Quad();
			void Create();
			virtual void Update() override final;
			void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) override final;
		};
	}
}