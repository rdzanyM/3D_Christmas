#pragma once
#include <vector>
#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "VertexFormat.h"

namespace Rendering
{
	class ISceneObject
	{
	public:
		virtual ~ISceneObject() = 0;

		virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position) = 0;
		virtual void Update() = 0;
		virtual void SetProgram(GLuint shaderName) = 0;
		virtual void Destroy() = 0;

		virtual GLuint GetVao() const = 0;
		virtual const std::vector<GLuint>& GetVbos() const = 0;
	};

	inline ISceneObject::~ISceneObject() {}
}