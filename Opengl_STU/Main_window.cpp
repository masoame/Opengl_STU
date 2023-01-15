#include "Utils.h"
#include"using_Data.h"

using namespace Mydef;
using namespace Data_3D;
using namespace build_VMat;

int main(void) {

	if (!glfwInit()) { exit(EXIT_FAILURE); }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(1200, 800, "测试窗口", NULL, NULL);


	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);
	glfwSetWindowSizeCallback(window, tool::window_reshape_callback);



	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwGetCursorPos(window, &temp_x, &temp_y);
	glfwSetCursorPosCallback(window, mouse_callback);

	double time;
	init(window);

	while (!glfwWindowShouldClose(window)) {
		time = glfwGetTime();
		mMat = glm::rotate(mMat,0.003f,glm::vec3(0,1,0));
		tool::back_ground(window);
		UserEvent(window,time);
		tool::draw_xyz(window);
		display(window, time);
		glfwPollEvents();
		glfwSwapBuffers(window);
		tool::message(time);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}