#include"Utils.h"
#include"using_Data.h"

using namespace Data_3D;
using namespace Mydef;

void setup_xyz() {
	float line[]{
		0.0f, 0.0f, 0.0f,  100.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,  0.0f,100.0f,  0.0f,
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 100.0f
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
}

void setupVertices(void) {
	vector<int> ind = mySphere.getIndices();
	vector<vec3> vert = mySphere.getVertices();
	vector<vec2> tex = mySphere.getTexCoords();
	vector<vec3> norm = mySphere.getNormals();

	vector<float> pvalues;
	vector<float> tvalues;
	vector<float> nvalues;

	int numIndies = mySphere.getnumIndices();
	for (int i = 0; i < numIndies; i++) {
		pvalues.push_back((vert[ind[i]]).x);
		pvalues.push_back((vert[ind[i]]).y);
		pvalues.push_back((vert[ind[i]]).z);
		tvalues.push_back((tex[ind[i]].s));
		tvalues.push_back((tex[ind[i]].t));
		nvalues.push_back((norm[ind[i]]).x);
		nvalues.push_back((norm[ind[i]]).y);
		nvalues.push_back((norm[ind[i]]).z);
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, pvalues.size() * sizeof(float), &pvalues[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, tvalues.size() * sizeof(float), &tvalues[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ARRAY_BUFFER, nvalues.size() * sizeof(float), &nvalues[0], GL_STATIC_DRAW);
}