#version 430
uniform mat4 pMat;
uniform mat4 mvMat;
layout(location = 0) in vec3 poi;
layout(location = 1) in vec2 tex;
out vec2 color;
mat4 buidRotateX(float rad);
mat4 buidRotateY(float rad);
mat4 buidRotateZ(float rad);
mat4 buidTranslate(float x,float y,float z);

void main(void)
{
	gl_Position= pMat * mvMat * vec4(poi,1.0f);
	color=tex;
}

mat4 buidRotateX(float rad){
	mat4 RX=mat4(
		1.0f,0.0f,0.f,0.0f,
		0.0f,cos(rad),sin(rad),0.0f,
		0.0f,-sin(rad),cos(rad),0.0f,
		0.0f,0.0f,0.f,1.0f
	);
	return RX;
}
mat4 buidRotateY(float rad){
	mat4 RY=mat4(
		cos(rad),0.0f,-sin(rad),0.0f,
		0.0f,1.0f,0.f,0.0f,
		sin(rad),0.0f,cos(rad),0.0f,
		0.0f,0.0f,0.f,1.0f
	);
	return RY;
}
mat4 buidRotateZ(float rad){
	mat4 RZ=mat4(
		cos(rad),sin(rad),0.f,0.0f,
		-sin(rad),cos(rad),0.f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	);
	return RZ;
}
mat4 buidTranslate(float x,float y,float z){
	mat4 trans=mat4(
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		x,y,z,1.0f
	);
	return trans;
}