#pragma once
#include"head.h"
#include"model_class.h"
#define VAOnums 1
#define VBOnums 4

namespace Mydef {
	extern GLuint renderingProgram,model_renderingProgram;
	extern GLuint brickTexture;
	extern Sphere mySphere;
	extern int temp1,temp2;
}

namespace Data_3D
{
	extern int FPS;
	extern int win_width, win_height;
	extern float aspect;
	extern glm::mat4 pMat, mMat, mvMat;
	extern GLuint pLoc, mvLoc, mLoc, vLoc, tLoc;

	extern GLuint vao[VAOnums];
	extern GLuint vbo[VBOnums];

	namespace build_VMat {
		extern glm::mat4 V_Mat, UD_Mat, LR_Mat, Loca_Mat, Temp_Mat;
		extern float aa, ab, ac, ad, bb, bc, bd, cc, cd, dd, temp_time;
		extern double  temp_x, temp_y;
		extern double spend;
	}
}

void UserEvent(GLFWwindow* window, double currentTime);
void setup_xyz(void);
void setupVertices(void);
void init(GLFWwindow* window);
void display(GLFWwindow* window, double currentTime);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

struct tool
{
	static void message(double& currentTime);
	static void back_ground(GLFWwindow* window);
	static void window_reshape_callback(GLFWwindow* window, int newWith, int newHeight);
	static void draw_xyz(GLFWwindow* window);
	static void camera_face(GLFWwindow* window, double currentTime);
	static glm::mat4 R_Matrix(glm::vec3 vec, double radio);
};

