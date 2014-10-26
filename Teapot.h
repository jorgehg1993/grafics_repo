#pragma once
#include "Classes.h"
#include "SceneObject.h"

class Teapot : SceneObject
{
    public:
       Teapot(GLfloat size);
       void render();
    
    private:
       GLfloat size;
};
