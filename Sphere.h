#pragma once
#include "Classes.h"
#include "SceneObject.h"

class Sphere : SceneObject
{
public:
	Sphere(GLfloat radius, GLfloat slices, GLfloat stacks);
	~Sphere();
	void render();

private:
	GLfloat radius;
	GLfloat slices;
	GLfloat stacks;
};
