#include"Utils.h"
#include"using_Data.h"

using namespace Mydef;
using namespace Data_3D;
using namespace build_VMat;

void init(GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("vshader.glsl", "fshader.glsl");
	model_renderingProgram = Utils::createShaderProgram("m_vshader.glsl", "m_fshader.glsl");
	brickTexture = Utils::loadTexture("earthmap1k.jpg");


	glfwGetWindowSize(window, &win_width, &win_height);
	aspect = (float)win_width / (float)win_height;
	pMat = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 1000.0f);

	Loca_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -1.0f, -8.0f));
	UD_Mat = glm::mat4(1.0f);
	LR_Mat = glm::mat4(1.0f);
	Temp_Mat = Loca_Mat;
	V_Mat = Temp_Mat;

	mMat = glm::translate(glm::mat4(1.0f),glm::vec3(2,0,2));
	glGenVertexArrays(VAOnums, vao);
	glGenBuffers(VBOnums, vbo);
	glBindVertexArray(vao[0]);
	setup_xyz();
	setupVertices();
	
}

