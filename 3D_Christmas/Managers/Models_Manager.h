#pragma once
#include <map>
#include "Shader_Manager.h"
#include "../Rendering/ISceneObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"
#include "../Rendering/Models/Cube.h"

using namespace Rendering;

namespace Managers
{
	class Models_Manager
	{
	public:
		Models_Manager();
		~Models_Manager();

		void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position);
		void Update();

		void DeleteModel(const std::string& sceneModelName);
		const ISceneObject& GetModel(const std::string& sceneModelName) const;

		void SetModel(const std::string& sceneObjectName, ISceneObject* sceneObject);

	private:
		std::map<std::string, ISceneObject*> sceneModelList; //change to vector for faster iteration #performance
	};
}