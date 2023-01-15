#pragma once
#include"head.h"
using namespace std;
using namespace glm;
struct Sphere
{
private:
	int numVertices;
	int numIndices;
	vector<int>indices;
	vector<vec3>vertices;
	vector<vec2>texCoords;
	vector<vec3>normals;
	void init(int);
	float toRadians(float degrees);
public:
	Sphere(int prec);
	int getnumVertices();
	int getnumIndices();
	vector<int> getIndices();
	vector<vec3> getVertices();
	vector<vec2> getTexCoords();
	vector<vec3> getNormals();
};