#pragma once
#include <vector>
#include "../ISceneObject.h"
namespace Rendering
{
	namespace Models
	{
		class Model : public ISceneObject
		{
		public:
			Model();
			virtual ~Model();
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override;
			virtual void Update() override;
			virtual void SetProgram(GLuint shaderName) override;
			virtual void Destroy() override;

			virtual GLuint GetVao() const override;
			virtual const std::vector<GLuint>& GetVbos() const override;

		protected:
			GLuint vao;
			GLuint program;
			std::vector<GLuint> vbos;
		};
	}
}