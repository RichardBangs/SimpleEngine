#version 450 core
layout(location = 0) out vec4 out_color;

in vec4 color;
in vec2 uv;

uniform sampler2D tex0;

void main()
{
	out_color = texture2D(tex0, uv);
}