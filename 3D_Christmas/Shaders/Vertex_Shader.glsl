#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 eye;
uniform vec3 light;
uniform vec3 mainLight;

out vec4 color;
out float distance;
out vec3 lightV;
out vec3 mainLightV;
out vec3 normalV;
out float lightDistSquare;

void main()
{
	color = in_color;
	normalV = in_normal;
	vec3 dif = in_position - eye;
	distance = sqrt(dif.x * dif.x + dif.y * dif.y + dif.z * dif.z);
	lightV = normalize(light - in_position);
	mainLightV = normalize(mainLight - in_position);
	dif = in_position - light;
	lightDistSquare = dif.x * dif.x + dif.y * dif.y + dif.z * dif.z;
    gl_Position = projection_matrix * view_matrix * vec4(in_position, 1);
}