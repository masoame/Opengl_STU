#include"using_Data.h"

namespace Mydef {

	GLuint renderingProgram,model_renderingProgram;
	GLuint brickTexture;
	Sphere mySphere(108);
	int temp;
}

namespace Data_3D
{
	int FPS=0;
	int win_width, win_height;
	float aspect;
	glm::mat4 pMat, mMat, mvMat;
	GLuint pLoc, mvLoc, mLoc, vLoc, tLoc;
	double now;
	GLuint vao[VAOnums];
	GLuint vbo[VBOnums];

	namespace build_VMat {
		glm::mat4 V_Mat, UD_Mat, LR_Mat, Loca_Mat, Temp_Mat;
		float aa, ab, ac, ad, bb, bc, bd, cc, cd, dd, temp_time;
		double  temp_x=0, temp_y=0;
		double spend;
	}
}