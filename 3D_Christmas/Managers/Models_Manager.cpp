#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;
void Timer(int value);
float step = 0;
Models::Star* star;

Models_Manager::Models_Manager()
{

	Models::Quad2* ground = new Models::Quad2();
	ground->SetProgram(Shader_Manager::GetShader("colorShader"));
	ground->Create(0.0, 0.0, 0.0, 20.0, 200.0, glm::vec4(0.44, 0.88, 0.11, 1.0));
	sceneModelList["ground"] = ground;

	Models::Cube* cube = new Models::Cube();
	cube->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube->Create(10, 1, -10, 1, glm::vec4(1.0,0.0,0.0,1.0));
	sceneModelList["cube"] = cube;

	Models::Cube* cube2 = new Models::Cube();
	cube2->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube2->Create(-10, 1, -30, 1, glm::vec4(1.0, 0.0, 0.0, 1.0));
	sceneModelList["cube2"] = cube2;

	Models::Gift* gift = new Models::Gift();
	gift->SetProgram(Shader_Manager::GetShader("colorShader"));
	gift->Create(-2, 0, 4, 1, 1.4, 1, glm::vec4(1.0, 0.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, 1.0));
	sceneModelList["gift"] = gift;

	Models::Gift* gift2 = new Models::Gift();
	gift2->SetProgram(Shader_Manager::GetShader("colorShader"));
	gift2->Create(2.6, 0, 2, 2, 1, 1, glm::vec4(0.1, 0.0, 1.0, 1.0), glm::vec4(1.0, 0.5, 0.0, 1.0));
	sceneModelList["gift2"] = gift2;

	Models::ChristmasTree* tree = new Models::ChristmasTree();
	tree->SetProgram(Shader_Manager::GetShader("colorShader"));
	tree->Create(0, 0, 0);
	sceneModelList["tree"] = tree;

	star = new Models::Star();
	star->SetProgram(Shader_Manager::GetShader("starShader"));
	star->Create(0.04, glm::vec4(1.0, 1.0, 1.0, 1.0));
	sceneModelList["star"] = star;

	Timer(0);

}

void Timer(int value)
{
	glutTimerFunc(16, Timer, 0);
	glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShader"), "light"), 4 * sin(step), 2.5 + sin(step * 2.2), 4 * cos(step));
	star->Move(4 * sin(step), 2.5 + sin(step * 2.2), 4 * cos(step));
	step += 0.01;
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

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position)
{
	for (auto model : sceneModelList)
	{
		model.second->Draw(projection_matrix, view_matrix, camera_position);
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