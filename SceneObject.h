#pragma once
#include "Classes.h"
#include "Vec.h"

class SceneObject
{
public:
	SceneObject();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setSpeed(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLfloat r, GLfloat g, GLfloat b);
	void setRotation(GLfloat x, GLfloat y, GLfloat z);
	void setRotationSpeed(GLfloat x, GLfloat y, GLfloat z);
	void setScale(GLfloat x, GLfloat y, GLfloat z);
	void setScaleSpeed(GLfloat x, GLfloat y, GLfloat z);

	void setRandomColor();
	void setRandomPosition(GLfloat min, GLfloat max);
	void setRandomSpeed(GLfloat min, GLfloat max);
	void setRandomScale(GLfloat min, GLfloat max);
	void setRandomScaleSpeed(GLfloat min, GLfloat max);
	void setRandomRotation(GLfloat min, GLfloat max);
	void setRandomRotationSpeed(GLfloat min, GLfloat max);
	
	void update();
	virtual void render() {};

protected:
	Vec *position;
	Vec *speed;
	Vec *scale;
	Vec *scaleSpeed;
	Vec *rotation;
	Vec *rotationSpeed;
	
	GLfloat r;
	GLfloat g;
	GLfloat b;
};
