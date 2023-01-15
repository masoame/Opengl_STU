#include"using_Data.h"
using namespace Data_3D;
using namespace build_VMat;


void UserEvent(GLFWwindow * window,double currentTime) 
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	else if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	

	spend = currentTime - temp_time;
	temp_time = currentTime;
	spend *= 4;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, spend)) * Temp_Mat;
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -spend))* Temp_Mat;
		}

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(spend, 0, 0)) * Temp_Mat;
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(-spend, 0, 0)) * Temp_Mat;
		}

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(0, -spend, 0)) * Temp_Mat;
		}
		else if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
			Temp_Mat = glm::translate(glm::mat4(1.0f), glm::vec3(0, spend, 0)) * Temp_Mat;
		}

		Loca_Mat = glm::transpose(LR_Mat) * Temp_Mat;

		V_Mat = UD_Mat * Temp_Mat;

}
void mouse_callback(GLFWwindow* window, double xpos, double ypos) 
{
	LR_Mat = glm::rotate(glm::mat4(1.0f), (float)(xpos - temp_x) * 0.001f, glm::vec3(0, 1, 0)) * LR_Mat;
	Temp_Mat = glm::rotate(glm::mat4(1.0f), (float)(xpos - temp_x) * 0.001f, glm::vec3(0, 1, 0)) * Temp_Mat;

	UD_Mat = glm::rotate(UD_Mat, (float)(ypos - temp_y) * 0.001f, glm::vec3(1, 0, 0));

	temp_x = xpos;
	temp_y = ypos;

	V_Mat = UD_Mat * Temp_Mat;
}