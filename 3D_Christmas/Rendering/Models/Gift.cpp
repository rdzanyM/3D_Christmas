#include "Gift.h"

using namespace Rendering;
using namespace Models;

Gift::Gift() {}

Gift::~Gift() {}

void Gift::Create(double x, double y, double z, double dx, double dy, double dz, const glm::vec4& boxColor, const glm::vec4& tapeColor)
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	dx /= 2;
	dz /= 2;
	double x1 = x - dx;
	double x2 = x + dx;
	double y1 = y;
	double y2 = y + dy;
	double z1 = z - dz;
	double z2 = z + dz;
	double x11 = x1 - dx / 72;
	double x21 = x2 + dx / 72;
	double z11 = z1 - dz / 72;
	double z21 = z2 + dz / 72;
	glm::vec3 top = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 left = glm::vec3(1.0, 0.0, 0.0);
	glm::vec3 front = glm::vec3(0.0, 0.0, 1.0);
	//Box
	{
		//front (when camera at(x,y,z+))
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, front));

		////back
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, -front));

		////right
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, -left));

		////left
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, left));

		////bottom
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, -top));
	}
	
	x1 -= dx / 12;
	x2 += dx / 12;
	y1 = y2 - dy / 12;
	y2 += dy / 12;
	z1 -= dz / 12;
	z2 += dz / 12;
	//Lid
	{
		//front
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, front));

		////back
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, -front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, -front));

		////right
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z2), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, -left));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, -left));

		////left
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z2), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z1), boxColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, left));

		////top
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2), boxColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z1), boxColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z1), boxColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z2), boxColor, top));
	}

	double x12 = x1 - dx / 72;
	double x22 = x2 + dx / 72;
	double z12 = z1 - dz / 72;
	double z22 = z2 + dz / 72;
	x1 = x - dx / 4;
	x2 = x + dx / 4;
	y1 = y - dy / 72;
	y2 += dy / 72;
	//Tape1
	{
		front = glm::normalize(glm::cross(glm::vec3(x2, y1, z21) - glm::vec3(x1, y1, z21), glm::vec3(x2, y2, z22) - glm::vec3(x1, y1, z21)));
		//front
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z21), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z22), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z21), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z21), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z22), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z22), tapeColor, front));

		front.z *= -1;
		//back
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z12), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z11), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z11), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z12), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z11), tapeColor, front));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z12), tapeColor, front));

		//top
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z22), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z12), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z22), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z22), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y2, z12), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y2, z12), tapeColor, top));

		//bottom
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z11), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z21), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z21), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z11), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x1, y1, z21), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x2, y1, z11), tapeColor, -top));
	}


	y2 += dy / 256;
	y1 -= dy / 256;
	z1 = z - dz / 4;
	z2 = z + dz / 4;
	//Tape2
	{
		left = glm::normalize(glm::cross(glm::vec3(x21, y1, z2) - glm::vec3(x22, y2, z2), glm::vec3(x21, y1, z1) - glm::vec3(x22, y2, z2)));
		//left
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z2), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z2), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z2), tapeColor, left));

		left.x *= -1;
		//right
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z2), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z2), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z1), tapeColor, left));
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z2), tapeColor, left));

		//top
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z2), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z1), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z2), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z1), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x22, y2, z1), tapeColor, top));
		vertices.push_back(VertexFormat(glm::vec3(x12, y2, z2), tapeColor, top));

		//bottom
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z1), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z2), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z2), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x21, y1, z1), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z1), tapeColor, -top));
		vertices.push_back(VertexFormat(glm::vec3(x11, y1, z2), tapeColor, -top));
	}

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

void Gift::Update() {}

void Gift::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& camera_position)
{
	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform3f(glGetUniformLocation(program, "eye"), camera_position.x, camera_position.y, camera_position.z);
	glUniform3f(glGetUniformLocation(program, "light"), 10, 50, 20);
	glUniform1f(glGetUniformLocation(program, "ambient"), 0.1);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 108);
}