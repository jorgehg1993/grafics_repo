//Enforces to compile only once
#pragma once

//Standard libraries includes
#include <map>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <cstdlib>
// Uncomment the corresponding include:
// For Windows:
#include <gl/glut.h>
// For Mac OS:
//#include <GLUT/glut.h>

//Add every new class in the project, in alphabetical order
class Scene;
class SceneObject;
class Teapot;
class Vec;
class Camera;
#define ESC 27

#define RFACTOR 1000
#define rval(min,max) min+(max-min)*(rand() % RFACTOR)/RFACTOR
#define DELTA_TRAN 0.2
#define DELTA_ROT 3.0
#define MAXFILENAME 50
#define MAX_LIGHTS 8
#define MARKER_RADIUS 0.15
#define MARKER_SECTIONS 7
#define SPECULAR_SHININESS 64.0

enum LightSource {DIRECTIONAL, POINT, SPOT};

#define INVALID_TEXTURE -1 
#define DEFAULT_MODE 0


