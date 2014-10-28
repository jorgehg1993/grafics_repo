#pragma once
#include "Classes.h"
#include "SceneObject.h"

class Cube : SceneObject
{
	public: 
		Cube(GLfloat size);
		~Cube();
		void render();
	private:
		GLfloat size;
};

