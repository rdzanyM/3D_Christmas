#include "Star.h"

using namespace Rendering;
using namespace Models;

Star::Star() {}

Star::~Star() {}

void Star::Create(double r, const glm::vec4& color)
{
	Move(0.0, 2.0, 1.0);
	GLuint vao;
	GLuint vbo;
	glm::vec4 c2 = glm::vec4(0.8, 1.0, 1.0, 1.0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;

	glm::vec3 top = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 left = glm::vec3(1.0, 0.0, 0.0);
	glm::vec3 front = glm::vec3(0.0, 0.0, 1.0);

	//front (when camera at(x,y,z+))
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 , 4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 , 4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 , 4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 , 4 * r), c2));

	//back
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 ,-4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 ,-4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 ,-4 * r), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,  0.0 ,-4 * r), c2));

	//right
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(-4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(-4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(-4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(-4 * r,  0.0 ,  0.0 ), c2));

	//left
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3( 4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3( 4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3( 4 * r,  0.0 ,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3( 4 * r,  0.0 ,  0.0 ), c2));

	//up
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 , 4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 , 4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 , 4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,   r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 , 4 * r,  0.0 ), c2));

	//down
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,-4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,-4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,  -r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,-4 * r,  0.0 ), c2));
	vertices.push_back(VertexFormat(glm::vec3(  -r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(   r  ,  -r  ,   r  ), color));
	vertices.push_back(VertexFormat(glm::vec3(  0.0 ,-4 * r,  0.0 ), c2));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Star::Move(double x, double y, double z)
{
	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "translation"), x, y, z);
}

void Star::Update() {}

void Star::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position)
{
	static float f = 0.0;
	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform1f(glGetUniformLocation(program, "step"), f);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 72);
	f += 0.01f;
}