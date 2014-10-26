#include "Cube.h"

Cube::Cube(GLfloat size) :SceneObject()
{
	this->size = size;
}

void Cube::render()
{
	glColor3f(r, g, b);
	glutSolidCube(size);
}
