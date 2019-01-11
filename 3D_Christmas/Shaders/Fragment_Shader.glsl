#version 430 core

layout(location = 0) out vec4 out_color;

uniform float ambient;

in vec4 color;
in float distance;
in vec3 lightV;
in vec3 mainLightV;
in vec3 normalV;

void main(void)
{
	float f = dot(lightV, normalV);
	if(f < 0.0)
	{
		f = 0.0;
	}
	float f2 = dot(mainLightV, normalV) / 3;
	if(f2 < 0.0)
	{
		f2 = 0.0;
	}
	f += f2;
	f += ambient;
	if(f > 1.0)
	{
		f = 1.0;
	}
	out_color = color.rgba * f;




	if (distance > 100.0)
	{
		out_color.a = 0.0;
		return;
	}
	out_color.a = 1.0 - distance / 100.0;
}