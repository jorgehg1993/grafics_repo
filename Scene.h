#pragma once
#include "Classes.h"
#include "SceneObject.h"
#include "Camera.h"

using namespace std;

class Scene {

private:
	int windowWidth;
	int windowHeight;
	unsigned long currentFrame;
	GLint frameRate;
	GLint frameTime;
	GLint currentTime;
	Camera *currentCamera;

public:
	map <string, SceneObject *> objects;
	void begin(int x, int y, int width, int height,
		string title, GLfloat r, GLfloat g, GLfloat b);
	void lighting();
	void render();
	void resize(int currentWidth, int currentHeight);
	void keyboard(unsigned char key, int x, int y);
	void end();
	void add(SceneObject *newObject, string name);
	void keyboardSpecial(int key, int x, int y);

	map <string, Camera *> cameras;
	void addCamera(string name, bool perspective, GLfloat fovy, GLfloat nearPlane, GLfloat farPlane);
	void setCurrentCamera(string name);
	void setFrameRate(int frameRate);
	void idle();
};

