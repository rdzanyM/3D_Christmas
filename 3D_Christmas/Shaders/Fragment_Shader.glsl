#version 430 core

layout(location = 0) out vec4 out_color;

in vec4 color;
in float distance;

void main(void)
{
	out_color = color.rgba;
	if (distance > 100.0)
	{
		out_color.a = 0.0;
		return;
	}
	out_color.a = 1.0 - distance / 100.0;
}