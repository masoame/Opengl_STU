#version 430
in vec2 color;
out vec4 COLOR;

layout (binding=0) uniform sampler2D samp;

void main(void)
{
	COLOR=texture(samp,color);
}