#version 430 core

layout(location = 0) out vec4 out_color;

uniform float ambient;
uniform vec3 background;

in vec4 color;
in float distance;
in vec3 lightV;
in vec3 mainLightV;
in vec3 normalV;
in float lightDistSquare;
in vec3 V;

void main(void)
{
	float f;
	float r;
	vec3 rv;

	//star light (intensity gets smaller with distance)
	float i = 1.0 - lightDistSquare / 100.0;
	if(i > 0.0)
	{
		float d = dot(lightV, normalV);
		
		//diffused
		f = d;
		if(f < 0.0) //light on the other side of the surface;
		{
			f = 0.0;
		}
		else
		{
			f *= i;
			
			//reflected
			rv = 2 * normalV * d - lightV;
			r = dot(rv, V);
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
			}
		}
	}

	//main light (high above and same intensity at any distance)
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

	//rcolor result
	out_color = color.rgba * f + r * color.rgba;
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