#include "Vec.h"


Vec::Vec(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vec::add(Vec *other)
{
	this->x += other->x;
	this->y += other->y;
	this->z += other->z;
}

void Vec::setRandom(GLfloat min, GLfloat max)
{
	this->x = rval(min, max);
	this->y = rval(min, max);
	this->z = rval(min, max);
}

void Vec::printVec(){
	printf("(%lf, %lf, %lf)", this->x, this->y, this->z);
}