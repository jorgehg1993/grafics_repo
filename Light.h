#pragma once
#include "Classes.h"
using namespace std;

class Light{
	public:
		//Constructor/Destructor
		Light();
		~Light();
		//Property getters
		bool isEnabled();
		LightSource getSource();
		GLfloat *getLightPosition();
		GLfloat *getAmbient();
		GLfloat *getDiffuse();
		GLfloat *getSpecular();
		GLfloat *getDirection();
		GLfloat getShininess();
		GLfloat getCutOff();
		GLfloat getAttenuation();

		//Property setters
		void setEnabled(bool enabled);
		void setAmbient(GLfloat r, GLfloat g, GLfloat b);
		void setDiffuse(GLfloat r, GLfloat g, GLfloat b);
		void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat shininess);
		void setPosition(GLfloat x, GLfloat y, GLfloat z);
		void setDirection(GLfloat x, GLfloat y, GLfloat z);
		void setCutOff(GLfloat cutOff);
		void setAttenuation(GLfloat attenuation);

		//Combined settings for the three light source types
		void setDirectional(GLfloat x, GLfloat y, GLfloat z);
		void setPoint(GLfloat x, GLfloat y, GLfloat z, GLfloat attenuation);
		void setSpot(GLfloat x, GLfloat y, GLfloat z, GLfloat xd, GLfloat yd, GLfloat zd, GLfloat cutOff, GLfloat attenuation);

	private:
		bool enabled;
		LightSource source;
		GLfloat lightPosition[4];
		GLfloat ambient[4];
		GLfloat diffuse[4];
		GLfloat specular[4];
		GLfloat direction[3];
		GLfloat shininess;
		GLfloat cutOff;
		GLfloat attenuation;
};