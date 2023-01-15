#version 430
in vec4 color;
out vec4 COLOR;

layout (binding=0) uniform sampler2D samp;

void main(void)
{
	COLOR=color;
}