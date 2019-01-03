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

	auto addPyramid = [&vertices, x, z](double h1, double h2, double r, const glm::vec4& color)
	{
		double diag = sqrt2 * r / 2;
		vertices.push_back(VertexFormat(glm::vec3(x + diag, h1, z + diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h1, z +  r  ), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x +  r  , h1, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x + diag, h1, z + diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x + diag, h1, z - diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x +  r  , h1, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h1, z -  r  ), color));
		vertices.push_back(VertexFormat(glm::vec3(x + diag, h1, z - diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x - diag, h1, z - diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h1, z -  r  ), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x -  r  , h1, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x - diag, h1, z - diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x - diag, h1, z + diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x -  r  , h1, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h1, z +  r  ), color));
		vertices.push_back(VertexFormat(glm::vec3(x - diag, h1, z + diag), color));
		vertices.push_back(VertexFormat(glm::vec3(x		  , h2, z		), color));
	};

	addPyramid(0.0, 5.0, 1.0, glm::vec4(0.3, 0.1, 0, 1));	//trunk
	glm::vec4 needles = glm::vec4(0.1, 0.5, 0.1, 1);
	addPyramid(3.3, 4.9, 1.0, needles);
	addPyramid(2.5, 4.0, 1.5, needles);
	addPyramid(1.6, 3.0, 2.0, needles);
	addPyramid(0.8, 2.2, 2.5, needles);
	
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
	glDrawArrays(GL_TRIANGLES, 0, 120);
}