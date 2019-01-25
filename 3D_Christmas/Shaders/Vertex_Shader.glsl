#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 eye;
uniform vec3 light;
uniform vec3 mainLight;
uniform float ambient;

out vec4 color;
out float distance;
out float i;
out float d;
out float r;
out float fm;

void main()
{
	color = in_color;
	vec3 dif = in_position - eye;
	distance = sqrt(dif.x * dif.x + dif.y * dif.y + dif.z * dif.z);
	vec3 lightV = normalize(light - in_position);
	vec3 V = normalize(eye - in_position);
	vec3 mainLightV = normalize(mainLight - in_position);
	dif = in_position - light;
	float lightDistSquare = dif.x * dif.x + dif.y * dif.y + dif.z * dif.z;
	i = 1.0 - lightDistSquare / 100.0;
	d = dot(lightV, in_normal);

	r = dot(2 * in_normal * d - lightV, V);
	if(r < 0)
	{
		r = 0;
	}
	else
	{
		r *= r;
		r *= r;
		r *= r;
		r *= r;
		r *= r;
	}
	fm = dot(mainLightV, in_normal) / 3;
	if(fm < 0.0)
	{
		fm = 0.0;
	}

    gl_Position = projection_matrix * view_matrix * vec4(in_position, 1);
}