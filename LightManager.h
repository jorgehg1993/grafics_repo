#pragma once
#include "Classes.h"
#include "Light.h"
class LightManager
{
public:
	LightManager();
	~LightManager();
	void setShadeModel(GLenum shadeModel);
	void setEnabled(int lightIndex, bool enabled);
	void setAmbient(int lightIndex, GLfloat r, GLfloat g, GLfloat b);
	void setDiffuse(int lightIndex, GLfloat r, GLfloat g, GLfloat b);
	void setSpecular(int lightIndex, GLfloat r, GLfloat g, GLfloat b, GLfloat shininess);
	void setDirectional(int lightIndex, GLfloat x, GLfloat y, GLfloat z);
	void setPoint(int lightIndex, GLfloat x, GLfloat y, GLfloat z, GLfloat attenuation);
	void setSpot(int lightIndex, GLfloat x, GLfloat y, GLfloat z, GLfloat xd, GLfloat yd, GLfloat zd, GLfloat cutOff, GLfloat attenuation);
	bool isEnabled(int lightIndex);
	bool isZero(GLfloat vectorParameter[]);
	void setMarkers(bool markers);
	void lightScene();
	void deleteLights();

private:
	GLenum shadeModel;
	Light *lights[MAX_LIGHTS];
	bool markers;
	void showLight(Light *light);
};