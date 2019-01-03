#version 430 core

layout(location = 0) out vec4 out_color;

uniform float ambient;

in vec4 color;
in float distance;
in vec3 lightV;
in vec3 normalV;

void main(void)
{
	out_color = ambient * color.rgba;
	float f = dot(lightV, normalV);
	if(f < 0)
	{
		f = 0;
	}
	out_color += color.rgba * (1 - ambient) * f;
	if (distance > 100.0)
	{
		out_color.a = 0.0;
		return;
	}
	out_color.a = 1.0 - distance / 100.0;
}