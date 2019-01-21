#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;
void Timer(int value);
float step = 0;
bool night = false;
Models::Star* star;
std::vector<Rendering::ISceneObject*> objects;
glm::mat4 vm;
glm::vec3 cam = glm::vec3(0.0, 5.0, 8.0); //also at scene_manager

Models_Manager::Models_Manager()
{

	Models::Quad2* ground = new Models::Quad2();
	ground->SetProgram(Shader_Manager::GetShader("colorShader"));
	ground->Create(0.0, 0.0, 0.0, 20.0, 200.0, glm::vec4(0.44, 0.88, 0.11, 1.0));
	sceneModelList["ground"] = ground;
	objects.push_back(ground);

	Models::Cube* cube = new Models::Cube();
	cube->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube->Create(10, 1, -15, 1, glm::vec4(1.0,0.0,0.0,1.0));
	sceneModelList["cube"] = cube;
	objects.push_back(cube);

	Models::Cube* cube2 = new Models::Cube();
	cube2->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube2->Create(-20, 1, -40, 1, glm::vec4(1.0, 0.0, 0.0, 1.0));
	sceneModelList["cube2"] = cube2;
	objects.push_back(cube2);

	Models::Gift* gift = new Models::Gift();
	gift->SetProgram(Shader_Manager::GetShader("colorShader"));
	gift->Create(-2, 0, 4, 1, 1.4, 1, glm::vec4(1.0, 0.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, 1.0));
	sceneModelList["gift"] = gift;
	objects.push_back(gift);

	Models::Gift* gift2 = new Models::Gift();
	gift2->SetProgram(Shader_Manager::GetShader("colorShader"));
	gift2->Create(2.6, 0, 2, 2, 1, 1, glm::vec4(0.1, 0.0, 1.0, 1.0), glm::vec4(1.0, 0.5, 0.0, 1.0));
	sceneModelList["gift2"] = gift2;
	objects.push_back(gift2);

	Models::ChristmasTree* tree = new Models::ChristmasTree();
	tree->SetProgram(Shader_Manager::GetShader("colorShader"));
	tree->Create(0, 0, 0);
	sceneModelList["tree"] = tree;
	objects.push_back(tree);

	star = new Models::Star();
	star->SetProgram(Shader_Manager::GetShader("starShader"));
	star->Create(0.04, glm::vec4(1.0, 1.0, 1.0, 1.0));
	sceneModelList["star"] = star;

	Timer(0);

}

void Timer(int value)
{
	glutTimerFunc(16, Timer, 0);

	//move the star
	double x = 4 * sin(step);
	double y = 2.5 + sin(step * 2.2);
	double z = 4 * cos(step);
	glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShader"), "light"), x, y, z);
	star->Move(x, y, z);

	//alternate cameras and shading
	{
		static int change = 0;
		//static
		if ((int)step % 15 < 5)
		{
			if (change == 4)
			{
				for (auto model : objects)
				{
					model->SetProgram(Shader_Manager::GetShader("colorShaderP"));
				}
				change -= 3;
			}
			else if (change == 5)
			{
				night = true;
				for (auto model : objects)
				{
					model->SetProgram(Shader_Manager::GetShader("colorShaderN"));
				}
				change -= 3;
			}
			else if (change == 6)
			{
				for (auto model : objects)
				{
					model->SetProgram(Shader_Manager::GetShader("colorShaderPN"));
				}
				change -= 3;
			}
			else if (change == 7)
			{
				night = false;
				for (auto model : objects)
				{
					model->SetProgram(Shader_Manager::GetShader("colorShader"));
				}
				change = 0;
			}
			glm::vec3 f = cam - glm::vec3(0.0, 2.0, 0.0);
			f = glm::normalize(f);
			glm::vec3 s = glm::cross(f, glm::vec3(0.0, 1.0, 0.0));
			s = glm::normalize(s);
			glm::vec3 v = glm::cross(s, f);
			f = -f;
			vm = glm::transpose(glm::mat4
			(
				s.x, s.y, s.z, -glm::dot(s, cam),
				v.x, v.y, v.z, -glm::dot(v, cam),
				f.x, f.y, f.z, -glm::dot(f, cam),
				0, 0, 0, 1)
			);
		}
		
		//bound with star
		else if ((int)step % 15 < 10)
		{
			switch (change)
			{
			case 0:
				glUseProgram(Shader_Manager::GetShader("colorShader"));
				glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShader"), "eye"), x + 1, y + 1, z - 2);
				break;
			case 1:
				glUseProgram(Shader_Manager::GetShader("colorShaderP"));
				glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShaderP"), "eye"), x + 1, y + 1, z - 2);
				break;
			case 2:
				glUseProgram(Shader_Manager::GetShader("colorShaderN"));
				glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShaderN"), "eye"), x + 1, y + 1, z - 2);
				break;
			case 3:
				glUseProgram(Shader_Manager::GetShader("colorShaderPN"));
				glUniform3f(glGetUniformLocation(Shader_Manager::GetShader("colorShaderPN"), "eye"), x + 1, y + 1, z - 2);
				break;
			}

			glm::vec3 pos = glm::vec3(x + 1, y + 1, z - 2);
			glm::vec3 f = pos - glm::vec3(x, y, z);
			f = glm::normalize(f);
			glm::vec3 s = glm::cross(f, glm::vec3(0.0, 1.0, 0.0));
			s = glm::normalize(s);
			glm::vec3 v = glm::cross(s, f);
			f = -f;
			vm = glm::transpose(glm::mat4
			(
				s.x, s.y, s.z, -glm::dot(s, pos),
				v.x, v.y, v.z, -glm::dot(v, pos),
				f.x, f.y, f.z, -glm::dot(f, pos),
				0, 0, 0, 1)
			);
		}
		
		//looking at star
		else
		{
			if (change < 4)
			{
				change += 4;
			}
			glm::vec3 f = cam - glm::vec3(x, y, z);
			f = glm::normalize(f);
			glm::vec3 s = glm::cross(f, glm::vec3(0.0, 1.0, 0.0));
			s = glm::normalize(s);
			glm::vec3 v = glm::cross(s, f);
			f = -f;
			vm = glm::transpose(glm::mat4
			(
				s.x, s.y, s.z, -glm::dot(s, cam),
				v.x, v.y, v.z, -glm::dot(v, cam),
				f.x, f.y, f.z, -glm::dot(f, cam),
				0, 0, 0, 1)
			);
		}
	}

	step += 0.04f;
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
	if (night)
	{
		glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
	}
	for (auto model : sceneModelList)
	{
		model.second->Draw(projection_matrix, vm, camera_position);
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