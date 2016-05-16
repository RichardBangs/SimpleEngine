#version 450 core
layout(location = 0) in vec4 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec2 in_uv;

out vec4 color;
out vec2 uv;

uniform vec4 cameraPosition;
uniform vec4 worldPosition;

void main()
{
	color = in_color;
	uv = in_uv;
	gl_Position = in_position + worldPosition + cameraPosition;
}