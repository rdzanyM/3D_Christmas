#version 430 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;

uniform mat4 projection_matrix, view_matrix;
uniform vec3 translation;
uniform float step;

out vec4 color;

void main()
{
	color = in_color;
	
	float x_angle = 2 * sin(step);
	mat4 xr = mat4(1.0);
	xr[1][1] = cos(x_angle);
	xr[2][2] = xr[1][1];
	xr[1][2] = sin(x_angle);
	xr[2][1] = -xr[1][2];
	
	float z_angle = 0.4 * sin(step + 1);
	mat4 zr = mat4(1.0);
	zr[0][0] = cos(z_angle);
	zr[1][1] = zr[0][0];
	zr[0][1] = sin(z_angle);
	zr[1][0] = -zr[1][2];

	mat4 t = mat4(1.0);
	t[3].xyz = translation;
    
	gl_Position = projection_matrix * view_matrix * t * xr * zr * vec4(in_position, 1);
}