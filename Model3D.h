#pragma once
#include "Classes.h"
#include "SceneObject.h"
#include "glm.h"

using namespace std;

class Model3D : SceneObject
{
	public:
		GLMmodel *model;
		GLuint displayList;
		Model3D(string modelName);
		void setPosition(GLfloat x, GLfloat y, GLfloat z);
		void setSpeed(GLfloat x, GLfloat y, GLfloat z);
		void setRotation(GLfloat x, GLfloat y, GLfloat z);
		void setRotationSpeed(GLfloat x, GLfloat y, GLfloat z);
		~Model3D();
		void render();

};

