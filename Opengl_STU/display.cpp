#include"using_Data.h"

using namespace Data_3D;
using namespace Mydef;
using namespace build_VMat;

void display(GLFWwindow* window, double currentTime) {

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glUseProgram(model_renderingProgram);
	pLoc = glGetUniformLocation(model_renderingProgram, "pMat");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(pMat));
	mvLoc = glGetUniformLocation(model_renderingProgram, "mvMat");
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(V_Mat * mMat));


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, brickTexture);

	glDrawArrays(GL_TRIANGLES, 0, mySphere.getnumIndices());
}