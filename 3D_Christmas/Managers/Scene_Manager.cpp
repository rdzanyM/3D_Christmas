#include "Scene_Manager.h"

using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = new Shader_Manager();
	shader_manager->CreateProgram(	"colorShader",
									"Shaders\\Vertex_Shader.glsl",
									"Shaders\\Fragment_Shader.glsl");

	view_matrix = LookAt
	(	glm::vec3(0.0, 0.0, 10.0),
		glm::vec3(0.0, 0.0, 0.0), 
		glm::vec3(0.0, 1.0, 0.0)
	);

	models_manager = new Models_Manager();
}

Scene_Manager::~Scene_Manager()
{
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame()
{
	models_manager->Update();
}

void Scene_Manager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 1.0, 1.0);

	models_manager->Draw(projection_matrix, view_matrix);
}

void Scene_Manager::notifyEndFrame()
{
}

void Scene_Manager::notifyReshape(	int width,
									int height,
									int previous_width,
									int previous_height)
{
	float ar = (float)glutGet(GLUT_WINDOW_WIDTH) /
		(float)glutGet(GLUT_WINDOW_HEIGHT);
	float angle = 45.0f, near1 = 0.1f, far1 = 2000.0f;

	projection_matrix[0][0] = 1.0f / (ar * tan(angle / 2.0f));
	projection_matrix[1][1] = 1.0f / tan(angle / 2.0f);
	projection_matrix[2][2] = (-near1 - far1) / (near1 - far1);
	projection_matrix[2][3] = 1.0f;
	projection_matrix[3][2] = 2.0f * near1 * far1 / (near1 - far1);
}

glm::mat4 Scene_Manager::LookAt(const glm::vec3& position,
								const glm::vec3& target,
								const glm::vec3& up)
{
	glm::vec3 f = position - target;
	f = glm::normalize(f);
	glm::vec3 s = glm::cross(f, up); //cross product s = f X up
	s = glm::normalize(s);
	glm::vec3 v = glm::cross(s, f);

	//Note! Vectors f,s,v must create a rotation matrix
	//To check if rotation matrix is OK, transpose and inverse
	//of rotation matrix must be equal
	//Check R^T = R^-1

	//One more thing; The camera is not looking forward, it's looking
	//backwards. Camera position is on a positive Z but it's looking
	//in the opposite direction. Ex: position (0,0,100) target (0,0,0)
	//So the view direction is -100. So let's turn f negative.
	//This way the R determinant is going to be equal to 1 and not -1
	f = -f;
	
	return glm::transpose(glm::mat4
	(
		s.x, s.y, s.z, -glm::dot(s, position),
		v.x, v.y, v.z, -glm::dot(v, position),
		f.x, f.y, f.z, -glm::dot(f, position),
		 0,   0,   0,           1           )
	);
}