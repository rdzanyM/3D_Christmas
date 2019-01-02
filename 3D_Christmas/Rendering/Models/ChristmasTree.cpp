#include "ChristmasTree.h"

#define sqrt2 1.414213562373095

using namespace Rendering;
using namespace Models;

ChristmasTree::ChristmasTree() {}

ChristmasTree::~ChristmasTree() {}

void ChristmasTree::Create(double x, double y, double z)
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;

	double h = 5;
	double r = 1;
	double diag = sqrt2 * r / 2;
	glm::vec4 color = glm::vec4(0.3, 0.1, 0, 1);
	vertices.push_back(VertexFormat(glm::vec3(x + diag, y	 , z + diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y	 , z + r   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r	  , y	 , z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x + diag, y	 , z + diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x + diag, y	 , z - diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x + r	  , y	 , z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y	 , z - r   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x + diag, y	 , z - diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x - diag, y	 , z - diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y	 , z - r   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r	  , y	 , z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x - diag, y	 , z - diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x - diag, y	 , z + diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x - r	  , y	 , z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y	 , z + r   ), color));
	vertices.push_back(VertexFormat(glm::vec3(x - diag, y	 , z + diag), color));
	vertices.push_back(VertexFormat(glm::vec3(x		  , y + h, z	   ), color));
	
	
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

void ChristmasTree::Update() {}

void ChristmasTree::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position)
{
	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform3f(glGetUniformLocation(program, "eye"), camera_position.x, camera_position.y, camera_position.z);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 24);
}