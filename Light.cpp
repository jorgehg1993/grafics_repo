#include "Light.h"


Light::Light(){

	source = DIRECTIONAL;
	enabled = false;
	shininess = 0.0;
	cutOff = 0.0;
	attenuation = 0.0;
	for (int i = 0; i<4; i++)
	{
		lightPosition[i] = 0.0;
		ambient[i] = 0.0;
		diffuse[i] = 0.0;
		specular[i] = 0.0;
		if (i<3)
			direction[i] = 0.0;
	}
}

Light::~Light(){
	printf("luz borrada");
}

void Light::setSpot(GLfloat x, GLfloat y, GLfloat z,
	GLfloat xd, GLfloat yd, GLfloat zd,
	GLfloat cutOff, GLfloat attenuation)
{
	source = SPOT;
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = 1.0;
	direction[0] = xd;
	direction[1] = yd;
	direction[2] = zd;
	enabled = true;
	this->cutOff = cutOff;
	this->attenuation = attenuation;

}

void Light::setPoint(GLfloat x, GLfloat y, GLfloat z, GLfloat attenuation)
{
	source = POINT;
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = 1.0;
	enabled = true;
	this->attenuation = attenuation;
}

void Light::setDirectional(GLfloat x, GLfloat y, GLfloat z)
{
	source = DIRECTIONAL;
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = 0.0;
	enabled = true;
	attenuation = 0.0;
}

bool Light::isEnabled(){
	return enabled;
}

void Light::setEnabled(bool enabled){
	Light::enabled = enabled;
}

LightSource Light::getSource(){
	return source;
}

GLfloat* Light::getLightPosition(){
	return lightPosition;
}

void Light::setPosition(GLfloat x, GLfloat y, GLfloat z){
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
}

GLfloat* Light::getAmbient(){
	return ambient;
}

void Light::setAmbient(GLfloat r, GLfloat g, GLfloat b){
	ambient[0] = r;
	ambient[1] = g;
	ambient[2] = b;
}

GLfloat* Light::getDiffuse(){
	return diffuse;
}

void Light::setDiffuse(GLfloat r, GLfloat g, GLfloat b){
	diffuse[0] = r;
	diffuse[1] = g;
	diffuse[2] = b;
}

GLfloat* Light::getSpecular(){
	return specular;
}

void Light::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat shininess){
	specular[0] = r;
	specular[1] = g;
	specular[2] = b;
	specular[3] = shininess;
}

GLfloat* Light::getDirection(){
	return direction;
}

void Light::setDirection(GLfloat x, GLfloat y, GLfloat z){
	direction[0] = x;
	direction[1] = y;
	direction[2] = z;
}

GLfloat Light::getShininess(){
	return shininess;
}

GLfloat Light::getCutOff(){
	return cutOff;
}

void Light::setCutOff(GLfloat cutOff){
	Light::cutOff = cutOff;
}

GLfloat Light::getAttenuation(){
	return attenuation;
}

void Light::setAttenuation(GLfloat attenuation){
	Light::attenuation = attenuation;
}