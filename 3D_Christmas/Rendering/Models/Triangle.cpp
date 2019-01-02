#include "Triangle.h"
using namespace Rendering;
using namespace Models;
 
Triangle::Triangle() {}
 
Triangle::~Triangle() {}
 
void Triangle::Create(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3, const glm::vec4& color)
{
    GLuint vao;
    GLuint vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
 
    std::vector<VertexFormat> vertices;
    vertices.push_back(VertexFormat(v1, color));
	vertices.push_back(VertexFormat(v2, color));
	vertices.push_back(VertexFormat(v3, color));

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
    glBindVertexArray(0);
    this->vao = vao;
    this->vbos.push_back(vbo);
}
 
void Triangle::Update()
{

}
 
void Triangle::Draw(const glm::mat4& projection_matrix,
					const glm::mat4& view_matrix)
{
	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}