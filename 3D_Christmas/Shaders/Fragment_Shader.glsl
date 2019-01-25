#version 430 core

layout(location = 0) out vec4 out_color;

uniform float ambient;
uniform vec3 background;

in vec4 color;
in float distance;
in float i; //how intense (less when source far away)
in float d; //how much diffused
in float r; //how much reflected
in float fm; //main light strength

void main(void)
{
	float f;
	vec3 rv;

	//star light (intensity gets smaller with distance)
	if(i > 0.0)
	{
		f = d;
		if(f < 0.0) //light on the other side of the surface;
		{
			f = 0.0;
		}
		else
		{
			f *= i;
		}
	}

	f += fm;
	f += ambient;
	if(f > 1.0)
	{
		f = 1.0;
	}

	//color result
	out_color = color.rgba * f + r * color.rgba * 0.8;
	float max = out_color.r;
	if(out_color.g > max)
	{
		max = out_color.g;
	}
	if(out_color.b > max)
	{
		max = out_color.b;
	}
	if(max > 1.0)
	{
		out_color /= max;
	}

	//fog
	if (distance > 100.0)
	{
		out_color.rgb = background;
		return;
	}
	out_color.rgb = (out_color.rgb * (100.0 - distance) + distance * background.rgb) / 100.0;

	//out_color.a = 1.0 - distance / 100.0;
}