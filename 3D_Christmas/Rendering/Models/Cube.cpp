#include "Cube.h"

using namespace Rendering;
using namespace Models;

Cube::Cube() {}

Cube::~Cube() {}

void Cube::Create(double x, double y, double z, double r, const glm::vec4& color)
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	
	//ccw triangles are culled

	//front (when camera at(x,y,z+))
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z + r), color));

	//back
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z - r), color));

	//right
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z - r), color));

	//left
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z - r), color));

	//top
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y + r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y + r, z - r), color));

	//bottom
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r, y - r, z - r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z + r), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r, y - r, z - r), color));


	
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

void Cube::Update() {}

void Cube::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position)
{
	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform3f(glGetUniformLocation(program, "eye"), camera_position.x, camera_position.y, camera_position.z);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}