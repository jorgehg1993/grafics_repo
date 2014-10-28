#include "Sphere.h"

Sphere::Sphere(GLfloat radius, GLfloat slices, GLfloat stacks) :SceneObject()
{
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
}

void Sphere::render()
{
	glColor3f(r, g, b);
	glutSolidSphere(radius, slices, stacks);
}

Sphere::~Sphere(){
	deleteVectors();
	printf("~Sphere() \n");
}