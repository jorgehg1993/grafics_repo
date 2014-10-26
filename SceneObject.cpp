#include "SceneObject.h"

SceneObject::SceneObject()
{
	position = new Vec(0.0, 0.0, 0.0);
	speed = new Vec(0.0, 0.0, 0.0);
	scale = new Vec(1.0, 1.0, 1.0);
	scaleSpeed = new Vec(0.0, 0.0, 0.0);
	rotation = new Vec(0.0, 0.0, 0.0);
	rotationSpeed = new Vec(0.0, 0.0, 0.0);
	r = 1.0;
	g = 1.0;
	b = 1.0;
}

void SceneObject::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
	position->x = x;
	position->y = y;
	position->z = z;
}

void SceneObject::setSpeed(GLfloat x, GLfloat y, GLfloat z)
{
	speed->x = x;
	speed->y = y;
	speed->z = z;
}

void SceneObject::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void SceneObject::update()
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRotatef(rotation->x, 1.0, 0.0, 0.0);
	glRotatef(rotation->y, 0.0, 1.0, 0.0);
	glRotatef(rotation->z, 0.0, 0.0, 1.0);
	glScalef(scale->x, scale->y, scale->z);
	render();
	glPopMatrix();
	position->add(speed);
	rotation->add(rotationSpeed);
	scale->add(scaleSpeed);
}

void SceneObject::setRandomColor()
{
	r = rval(0.0, 1.0);
	g = rval(0.0, 1.0);
	b = rval(0.0, 1.0);
}

void SceneObject::setRandomPosition(GLfloat min, GLfloat max){
	position->setRandom(min, max);
}

void SceneObject::setRotation(GLfloat x, GLfloat y, GLfloat z){
	rotation->x = x;
	rotation->y = y;
	rotation->z = z;
}

void SceneObject::setRotationSpeed(GLfloat x, GLfloat y, GLfloat z){
	rotationSpeed->x = x;
	rotationSpeed->y = y;
	rotationSpeed->z = z;
}

void SceneObject::setScale(GLfloat x, GLfloat y, GLfloat z){
	scale->x = x;
	scale->y = y;
	scale->z = z;
}

void SceneObject::setScaleSpeed(GLfloat x, GLfloat y, GLfloat z){
	scaleSpeed->x = x;
	scaleSpeed->y = y;
	scaleSpeed->z = z;
}

void SceneObject::setRandomSpeed(GLfloat min, GLfloat max){
	speed->setRandom(min, max);
}
void SceneObject::setRandomScale(GLfloat min, GLfloat max){
	scale->setRandom(min, max);
}
void SceneObject::setRandomScaleSpeed(GLfloat min, GLfloat max){
	scaleSpeed->setRandom(min, max);
}
void SceneObject::setRandomRotation(GLfloat min, GLfloat max){
	rotation->setRandom(min, max);
}
void SceneObject::setRandomRotationSpeed(GLfloat min, GLfloat max){
	rotationSpeed->setRandom(min, max);
}












