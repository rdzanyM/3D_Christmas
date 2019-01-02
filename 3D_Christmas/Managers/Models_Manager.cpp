#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	/*
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(Shader_Manager::GetShader("colorShader"));
	triangle->Create();
	sceneModelList_NDC["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(Shader_Manager::GetShader("colorShader"));
	quad->Create();
	sceneModelList_NDC["quad"] = quad;
	*/
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(Shader_Manager::GetShader("colorShader"));
	triangle->Create(glm::vec3(-1e4, -2.0, 4e3), glm::vec3(0.0, -2.0, -12e3), glm::vec3(1e4, -2.0, 4e3), glm::vec4(0.0, 1.0, 0.0, 1.0));
	sceneModelList["ground"] = triangle;

	Models::Cube* cube = new Models::Cube();
	cube->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube->Create(5,3,0,1,glm::vec4(0.0,1.0,1.0,1.0));
	sceneModelList["cube"] = cube;
}

Models_Manager::~Models_Manager()
{
	for (auto model : sceneModelList)
	{
		delete model.second;
	}
	sceneModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& sceneModelName)
{
	ISceneObject* model = sceneModelList[sceneModelName];
	model->Destroy();
	sceneModelList.erase(sceneModelName);
}

void Models_Manager::Update()
{
	for (auto model : sceneModelList)
	{
		model.second->Update();
	}
}

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix)
{
	for (auto model : sceneModelList)
	{
		model.second->Draw(projection_matrix, view_matrix);
	}
}

const ISceneObject& Models_Manager::GetModel(const std::string& sceneModelName) const
{
	return (*sceneModelList.at(sceneModelName));
}

void Models_Manager::SetModel(const std::string& sceneObjectName, ISceneObject* sceneObject)
{
	sceneModelList[sceneObjectName.c_str()] = sceneObject;
}