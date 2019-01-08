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
		glm::vec3 top = glm::vec3(x, h2, z);
		glm::vec3 v1 = glm::vec3(x, h1, z + r);
		glm::vec3 v2 = glm::vec3(x + diag, h1, z + diag);
		glm::vec3 v3 = glm::vec3(x + r, h1, z);
		glm::vec3 v4 = glm::vec3(x + diag, h1, z - diag);
		glm::vec3 v5 = glm::vec3(x, h1, z - r);
		glm::vec3 v6 = glm::vec3(x - diag, h1, z - diag);
		glm::vec3 v7 = glm::vec3(x - r, h1, z);
		glm::vec3 v8 = glm::vec3(x - diag, h1, z + diag);

		glm::vec3 n = glm::normalize(glm::cross(v1 - top, v2 - top));
		glm::vec3 n2 = glm::normalize(glm::cross(v2 - top, v3 - top));
		glm::vec3 n3 = glm::normalize(glm::cross(v3 - top, v4 - top));
		glm::vec3 n4 = glm::normalize(glm::cross(v4 - top, v5 - top));
		glm::vec3 n5 = glm::normalize(glm::cross(v5 - top, v6 - top));
		glm::vec3 n6 = glm::normalize(glm::cross(v6 - top, v7 - top));
		glm::vec3 n7 = glm::normalize(glm::cross(v7 - top, v8 - top));
		glm::vec3 n8 = glm::normalize(glm::cross(v8 - top, v1 - top));

		glm::vec3 n1 = glm::normalize(n + n2);
		n2 = glm::normalize(n2 + n3);
		n3 = glm::normalize(n3 + n4);
		n4 = glm::normalize(n4 + n5);
		n5 = glm::normalize(n5 + n6);
		n6 = glm::normalize(n6 + n7);
		n7 = glm::normalize(n7 + n8);
		n8 = glm::normalize(n8 + n);

		vertices.push_back(VertexFormat(v2, color, n1));
		vertices.push_back(VertexFormat(v1, color, n8));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v3, color, n2));
		vertices.push_back(VertexFormat(v2, color, n1));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v4, color, n3));
		vertices.push_back(VertexFormat(v3, color, n2));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v5, color, n4));
		vertices.push_back(VertexFormat(v4, color, n3));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v6, color, n5));
		vertices.push_back(VertexFormat(v5, color, n4));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v7, color, n6));
		vertices.push_back(VertexFormat(v6, color, n5));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v8, color, n7));
		vertices.push_back(VertexFormat(v7, color, n6));
		vertices.push_back(VertexFormat(top, color));
		vertices.push_back(VertexFormat(v1, color, n8));
		vertices.push_back(VertexFormat(v8, color, n7));
		vertices.push_back(VertexFormat(top, color));
	};

	addPyramid(0.0, 5.5, 1.0, glm::vec4(0.3, 0.1, 0, 1));	//trunk
	glm::vec4 needles = glm::vec4(0.1, 0.5, 0.1, 1);
	addPyramid(3.8, 5.4, 1.0, needles);
	addPyramid(3.0, 4.5, 1.5, needles);
	addPyramid(2.1, 3.5, 2.0, needles);
	addPyramid(1.3, 2.7, 2.5, needles);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
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
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 120);
}