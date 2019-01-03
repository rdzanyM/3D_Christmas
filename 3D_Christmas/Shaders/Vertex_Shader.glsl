#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 eye;
uniform vec3 light;

out vec4 color;
out float distance;
out vec3 lightV;
out vec3 normalV;

void main()
{
	color = in_color;
	normalV = in_normal;
	vec3 dif = in_position - eye;
	distance = sqrt(dif.x * dif.x + dif.y * dif.y + dif.z * dif.z);
	lightV = normalize(light - in_position);
    gl_Position = projection_matrix * view_matrix * vec4(in_position, 1);
}