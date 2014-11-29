#include "LightManager.h"

LightManager::LightManager()
{
	shadeModel = GL_SMOOTH;
	for (int i=0; i<MAX_LIGHTS; i++) {
		lights[i] = new Light();
	}
}
LightManager::~LightManager()
{
	printf("~LightManager() cleanup:\n");
	deleteLights();
}
void LightManager::deleteLights()
{
	for (int i = 0; i<MAX_LIGHTS; i++) {
		delete lights[i];
	}
}
void LightManager::lightScene()
{
	GLenum lightNames[] = { GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3,
		GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7 };
	GLfloat specularMat[] = { 0.3, 0.3, 0.3, 1.0 };

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glShadeModel(shadeModel);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularMat);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, SPECULAR_SHININESS);
	for (int i = 0; i<MAX_LIGHTS; i++)
	{
		if (lights[i]->isEnabled())
		{
			if (!isZero(lights[i]->getAmbient()))
				glLightfv(lightNames[i], GL_AMBIENT, lights[i]->getAmbient());

			if (!isZero(lights[i]->getDiffuse()))
				glLightfv(lightNames[i], GL_DIFFUSE, lights[i]->getDiffuse());

			if (!isZero(lights[i]->getSpecular()))
				glLightfv(lightNames[i], GL_SPECULAR, lights[i]->getSpecular());

			switch (lights[i]->getSource()) {
				case DIRECTIONAL:
					glLightfv(lightNames[i], GL_POSITION, lights[i]->getLightPosition());
					break;
				case POINT:
					glLightfv(lightNames[i], GL_POSITION, lights[i]->getLightPosition());
					glLightf(lightNames[i], GL_QUADRATIC_ATTENUATION, lights[i]->getAttenuation());
					break;

				case SPOT:
					glLightfv(lightNames[i], GL_POSITION, lights[i]->getLightPosition());
					glLightfv(lightNames[i], GL_SPOT_DIRECTION, lights[i]->getDirection());
					glLightf(lightNames[i], GL_SPOT_CUTOFF, lights[i]->getCutOff());
					glLightf(lightNames[i], GL_QUADRATIC_ATTENUATION, lights[i]->getAttenuation());
					break;
			}

			glEnable(lightNames[i]);

			if (markers)
				showLight(lights[i]);
		}
		else
			glDisable(lightNames[i]);	
	}
}

void LightManager::showLight(Light *light)
{
	GLfloat defaultLightColor[] = { 0.7, 0.7, 0.7 };

	//Select a color for the light marker
	if (!isZero(light->getAmbient()))
		glColor3fv(light->getAmbient());
	else if (!isZero(light->getDiffuse()))
		glColor3fv(light->getDiffuse());
	else if (!isZero(light->getSpecular()))
		glColor3fv(light->getSpecular());
	else
		glColor3fv(defaultLightColor);
	//Draw the marker
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(light->getLightPosition()[0], light->getLightPosition()[1], light->getLightPosition()[2]);
	glutWireSphere(MARKER_RADIUS, MARKER_SECTIONS, MARKER_SECTIONS);
	glPopMatrix();

}

void LightManager::setShadeModel(GLenum shadeModel){
	LightManager::shadeModel = shadeModel;
}

void LightManager::setEnabled(int lightIndex, bool enabled){
	lights[lightIndex]->setEnabled(enabled);
}

void LightManager::setAmbient(int lightIndex, GLfloat r, GLfloat g, GLfloat b){
	lights[lightIndex]->setAmbient(r, g, b);
}

void LightManager::setDiffuse(int lightIndex, GLfloat r, GLfloat g, GLfloat b){
	lights[lightIndex]->setDiffuse(r, g, b);
}

void LightManager::setSpecular(int lightIndex, GLfloat r, GLfloat g, GLfloat b, GLfloat shininess){
	lights[lightIndex]->setSpecular(r, g, b, shininess);
}

void LightManager::setDirectional(int lightIndex, GLfloat x, GLfloat y, GLfloat z){
	lights[lightIndex]->setDirectional(x, y, z);
}

void LightManager::setPoint(int lightIndex, GLfloat x, GLfloat y, GLfloat z, GLfloat attenuation){
	lights[lightIndex]->setPoint(x, y, z, attenuation);
}

void LightManager::setSpot(int lightIndex, GLfloat x, GLfloat y, GLfloat z, GLfloat xd, GLfloat yd, GLfloat zd, GLfloat cutOff, GLfloat attenuation){
	lights[lightIndex]->setSpot(x, y, z, xd, yd, zd, cutOff, attenuation);
}

bool LightManager::isEnabled(int LightIndex){
	return lights[LightIndex]->isEnabled();
}

void LightManager::setMarkers(bool markers){
	LightManager::markers = markers;
}

bool LightManager::isZero(GLfloat vectorParameter[]){
	for (int i = 0; i < 4; i++){
		if (vectorParameter[i] != 0.0)
			return false;
	}
	return true;
}