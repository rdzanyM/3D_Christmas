#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix;


out vec4 color;
out vec3 normalV;
out vec3 f_position;

void main()
{
	color = in_color;
	normalV = in_normal;
	f_position = in_position;
    gl_Position = projection_matrix * view_matrix * vec4(in_position, 1);
}