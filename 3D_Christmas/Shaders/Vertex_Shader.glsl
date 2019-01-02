#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 eye;

out vec4 color;
out float distance;

void main()
{
	color = in_color;
	vec3 dif = in_position - eye;
	distance = dif.x * dif.x + dif.y * dif.y + dif.z * dif.z;
    gl_Position = projection_matrix * view_matrix * vec4(in_position, 1);
}