#pragma once
#include "Classes.h"
#include "SceneObject.h"

class Teapot : SceneObject
{
    public:
       Teapot(GLfloat size);
	   ~Teapot();
       void render();
    
    private:
       GLfloat size;
};
