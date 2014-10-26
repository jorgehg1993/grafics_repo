#include "Camera.h"

Camera::Camera(bool perspective, GLfloat fovy, GLfloat nearPlane, GLfloat farPlane){
	this->perspective = perspective;
	this->fovy = fovy;
	this->farPlane = farPlane;
	this->nearPlane = nearPlane;
}

void Camera::setPosition(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setPosition(x, y, z);
}

void Camera::setSpeed(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setSpeed(x, y, z);
}

void Camera::setRotation(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setRotation(x, y, z);
}

void Camera::setRotationSpeed(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setRotationSpeed(x, y, z);
}

bool Camera::getPerspective(){
	return perspective;
}

GLfloat Camera::getFovy(){
	return fovy;
}

GLfloat Camera::getNear(){
	return nearPlane;
}

GLfloat Camera::getFar(){
	return farPlane;
}

GLfloat Camera::getLeft(){
	return -fovy;
}

GLfloat Camera::getRight(){
	return fovy;
}

GLfloat Camera::getTop(){
	return fovy;
}

GLfloat Camera::getBottom(){
	return -fovy;
}

Vec* Camera::getPosition(){
	return position;
}

Vec* Camera::getRotation(){
	return rotation;
}

Vec* Camera::getSpeed(){
	return speed;
}

Vec* Camera::getRotationSpeed(){
	return rotationSpeed;
}