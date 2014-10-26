#include "Teapot.h"

Teapot::Teapot(GLfloat size):SceneObject()
{
    this->size=size;
}

void Teapot::render()
{
    glColor3f(r,g,b);
    glutSolidTeapot(size);
}
