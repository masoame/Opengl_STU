#include"using_Data.h"
using namespace Mydef;
using namespace Data_3D;
using namespace build_VMat;
using namespace std;

void tool::message(double &currentTime) {
	static double before = 0;
	if (currentTime - before > 1) {
		before = currentTime;
		system("cls");
		cout << "fps:  " << FPS << endl;
		cout << "windows_Width:  " << win_width << endl;
		cout << "windows_Height:  " << win_height << endl << endl;

		cout << "xpos:  " << temp_x << endl;
		cout << "ypos:  " << temp_y << endl << endl;
		

		wcout.imbue(locale(""));
		wcout << L"x×ø±ê  " << -Loca_Mat[3][0] << endl;
		wcout << L"y×ø±ê  " << -Loca_Mat[3][1] << endl;
		wcout << L"z×ø±ê  " << -Loca_Mat[3][2] << endl << endl;

		cout << "LR: Matrix " << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << LR_Mat[i][j] << "    \t";
			cout << endl;
		}

		cout << "\nUD: Matrix " << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << UD_Mat[i][j] << "    \t";
			cout << endl;
		}
			
		cout << "\nM: Matrix " << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << mMat[i][j] << "    \t";
			cout << endl;
		}
		FPS = 0;
	}
	FPS++;
}

void tool::back_ground(GLFWwindow* window) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3, 0.4, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

}

void  tool::window_reshape_callback(GLFWwindow* window, int newWidth, int newHeight) {
	win_width = newWidth;
	win_height = newHeight;
	float aspect = (float)newWidth / (float)newHeight;
	glViewport(0, 0, newWidth, newHeight);
	pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);
}

void tool::draw_xyz(GLFWwindow* window) {

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glUseProgram(renderingProgram);
	pLoc = glGetUniformLocation(renderingProgram, "pMat");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(pMat));
	mvLoc = glGetUniformLocation(renderingProgram, "mvMat");
	//xyz
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(V_Mat));
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
	glEnableVertexAttribArray(0);
	glDrawArraysInstanced(GL_LINES, 0, 6, 1);

}

glm::mat4 tool::R_Matrix(glm::vec3 vec,double radio) {
	vec = glm::normalize(vec);
	glm::vec4 num = glm::vec4(cos(radio), glm::mat3(sin(radio))*vec);
	aa = num[0] * num[0];
	ab = num[0] * num[1];
	ac = num[0] * num[2];
	ad = num[0] * num[3];
	bb = num[1] * num[1];
	bc = num[1] * num[2];
	bd = num[1] * num[3];
	cc = num[2] * num[2];
	cd = num[2] * num[3];
	dd = num[3] * num[3];
	glm::mat4 fourMatrix(
		1-2*(cc+dd),  2*(bc+ad),    2*(bd-ac),   0,
		2*(bc-ad),    1-2*(bb+dd),  2*(ab+cd),   0,
		2*(ac+bd),    2*(cd-ab),    1-2*(bb+cc), 0,
		0,            0,            0,           1
	);
	return fourMatrix;
}

