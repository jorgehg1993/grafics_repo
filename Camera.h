#pragma once
#pragma once
#include "Classes.h"
#include "SceneObject.h"


class Camera : SceneObject{
	public:
		Camera(bool perspective, GLfloat fovy, GLfloat nearPlane, GLfloat farPlane);
		void setPosition(GLfloat x, GLfloat y, GLfloat z);
		void setSpeed(GLfloat x, GLfloat y, GLfloat z);
		void setRotation(GLfloat x, GLfloat y, GLfloat z);
		void setRotationSpeed(GLfloat x, GLfloat y, GLfloat z);
		bool getPerspective();
		GLfloat getFovy();
		GLfloat getNear();
		GLfloat getFar();
		GLfloat getLeft();
		GLfloat getRight();
		GLfloat getTop();
		GLfloat getBottom();
		Vec *getPosition();
		Vec *getRotation();
		Vec *getSpeed();
		Vec *getRotationSpeed();
	private: 
		bool perspective;
		GLfloat fovy;
		GLfloat nearPlane;
		GLfloat farPlane;
		
};

