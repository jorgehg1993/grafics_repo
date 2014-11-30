// Equipo Medieval Age

#include "Classes.h"
#include "Scene.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Model3D.h"

Scene *scene = new Scene();

void render()
{
	scene->render();
}

void resize(int width, int height)
{
	scene->resize(width, height);
}

void keyboard(unsigned char key, int x, int y)
{
	scene->keyboard(key, x, y);
}

void createScene()
{
	/*scene->add((SceneObject *) new Model3D("sword"), "sword");
	scene->objects["sword"]->setRotation(0.0, -90.0, 0.0);
	scene->objects["sword"]->setScale(1.8, 1.8, 1.8);
	scene->objects["sword"]->setPosition(0.0, 1.0, 0.0);
	scene->objects["sword"]->setRotationSpeed(0.0, 3.0, 0.0);

	scene->add((SceneObject *) new Model3D("throne"), "throne");
	scene->objects["throne"]->setPosition(0.0, 1.0, -1.5);


	scene->add((SceneObject *) new Model3D("roman_helmet"), "helmet");
	scene->objects["helmet"]->setPosition(1.0, 1.2, 0.0);
	scene->objects["helmet"]->setRotation(0.0, 180.0, 0.0);
	scene->objects["helmet"]->setScale(0.5, 0.5, 0.5);
	scene->objects["helmet"]->setRotationSpeed(0.0, 3.0, 0.0);


	scene->add((SceneObject *) new Model3D("shield"), "shield");
	scene->objects["shield"]->setPosition(-1.0, 1.0, 0.0);
	scene->objects["shield"]->setScale(0.5, 0.5, 0.5);
	scene->objects["shield"]->setRotationSpeed(0.0, 3.0, 0.0);*/

	scene->add((SceneObject *) new Model3D("castle"), "castle");
	scene->objects["castle"]->setScale(20.0, 20.0, 20.0);
	scene->objects["castle"]->setRotation(0.0, -90.0, 2.0);

	scene->add((SceneObject *) new Teapot(1.0), "taza");
	scene->objects["taza"]->setPosition(30.0, 0.0, -7.0);

}

void idle()
{
	scene->idle();
}

void createLights()
{
	LightManager *l = scene->getLightManager();
	//light 0
	l->setDirectional(0, 1.8, 6.9, 16.99);
	l->setDiffuse(0, 1.0, 0.84, 0.0);
	l->setAmbient(0, 0.3, 0.3, 0.3);
	//l->setSpecular(0, 1.0, 0.84, 0.0, 10.0);
	//Turn markers on
	l->setMarkers(true);
}

void createCameras(){
	scene->addCamera("perspective", true, 45, 1.0, 1000.0);
	scene->cameras["perspective"]->setPosition(-2.0, 0.0, -7.0);


	scene->addCamera("front", false, 5.0, 1.0, 100.0);
	scene->cameras["front"]->setPosition(0.0, 0.0, -5.0);

	scene->addCamera("side", false, 5.0, 1.0, 100.0);
	scene->cameras["side"]->setRotation(0.0, 90.0, 0.0);
	scene->cameras["side"]->setPosition(0.0, 0.0, -5.0);

	scene->addCamera("top", false, 5.0, 1.0, 100.0);
	scene->cameras["top"]->setRotation(90.0, 0.0, 0.0);
	scene->cameras["top"]->setPosition(0.0, 0.0, -5.0);

	scene->addCamera("custom", true, 45, 1.0, 1000.0);
	scene->cameras["custom"]->setPosition(0.0, -1.2, -2.6);
	scene->cameras["custom"]->setRotation(0.0, 180.0, 0.0);

	scene->addCamera("taza_cam", true, 45.0, 1.0, 1000.0);
	scene->cameras["taza_cam"]->setPosition(-24.0, 0.0, 0.0);
	scene->cameras["taza_cam"]->setRotation(0.0, 45.0, 0.0);

	scene->setCurrentCamera("perspective");
}

void keyboardSpecial(int key, int x, int y){
	scene->keyboardSpecial(key, x, y);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	scene->begin(0, 0, 800, 600, "OO Premiere", 0, 0, 0);
	createLights();
	createScene();
	createCameras();
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}










