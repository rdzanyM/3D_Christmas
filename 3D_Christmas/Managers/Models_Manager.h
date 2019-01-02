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

		void Draw();
		void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix);
		void Update();

		void DeleteModel(const std::string& sceneModelName);
		const ISceneObject& GetModel(const std::string& sceneModelName) const;

		void DeleteModel_NDC(const std::string& sceneModelName);
		const ISceneObject& GetModel_NDC(const std::string& sceneModelName) const;

		void SetModel(const std::string& sceneObjectName, ISceneObject* sceneObject);

	private:
		std::map<std::string, ISceneObject*> sceneModelList; //change to vector for faster iteration #performance
		std::map<std::string, ISceneObject*> sceneModelList_NDC;
	};
}