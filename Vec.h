#pragma once
#include "Classes.h"

class Vec
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	Vec(GLfloat x, GLfloat y, GLfloat z);
	void add(Vec *other);
	void setRandom(GLfloat min, GLfloat max);
	void printVec();
};



