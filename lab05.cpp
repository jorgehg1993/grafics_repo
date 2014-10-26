// Autor: Jorge Hernandez Gomez

#include "Classes.h"
#include "Scene.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"

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
	char name[100];
	GLfloat x = -5;
	

	/*for (int i=0; i < 20; i++){
		sprintf_s(name, 100,"taza%i", i);
		printf("%s creada\n", name);
		scene->add((SceneObject *)new Teapot(0.2), name);
		scene->objects[name]->setRandomColor();
		scene->objects[name]->setRandomSpeed(-0.01, 0.01);
		scene->objects[name]->setRandomRotation(-10.0, 10.0);
		scene->objects[name]->setRandomRotationSpeed(-1.0, 1.0);
		scene->objects[name]->setRandomScale(0.5, 1.2);
		scene->objects[name]->setRandomScaleSpeed(-0.001, 0.001);
		x += 1.0;
	}*/

	for (int i = 0; i < 10; i++){
		sprintf_s(name, 100, "cubo%i", i);
		printf("%s creada\n", name);
		scene->add((SceneObject *)new Cube(0.2), name);
		scene->objects[name]->setRandomColor();
		scene->objects[name]->setRandomPosition(-1.5, 1.5);
		scene->objects[name]->setRandomSpeed(-0.001, 0.001);
		scene->objects[name]->setRandomRotation(-10.0, 10.0);
		scene->objects[name]->setRandomRotationSpeed(-0.01, 0.01);
		scene->objects[name]->setRandomScale(0.5, 1.5);
		scene->objects[name]->setRandomScaleSpeed(-0.0001, 0.0001);
		x += 1.0;
	}

	for (int i = 0; i < 20; i++){
		sprintf_s(name, 100, "esfera%i", i);
		printf("%s creada\n", name);
		scene->add((SceneObject *)new Sphere(0.2, 20, 20), name);
		scene->objects[name]->setRandomColor();
		scene->objects[name]->setRandomPosition(-2.5, 2.5);
		scene->objects[name]->setSpeed(0.005 * pow(-1, i), 0, 0);
		scene->objects[name]->setRandomRotation(-10.0, 10.0);
		scene->objects[name]->setRandomRotationSpeed(-1.0, 1.0);
		scene->objects[name]->setRandomScale(0.5, 1.5);
		scene->objects[name]->setRandomScaleSpeed(-0.001, 0.001);
		x += 1.0;
	}

	scene->add((SceneObject *)new Teapot(1.0), "taza_origen");

}

void idle()
{
	scene->idle();
}

void createCameras(){
	scene->addCamera("perspective", true, 45, 1.0, 1000.0);
	scene->cameras["perspective"]->setPosition(0.0, 0.0, -10.0);

	scene->addCamera("front", false, 5.0, 1.0, 100.0);
	scene->cameras["front"]->setPosition(0.0, 0.0, -5.0);

	scene->addCamera("side", false, 5.0, 1.0, 100.0);
	scene->cameras["side"]->setRotation(0.0, 90.0, 0.0);
	scene->cameras["side"]->setPosition(0.0, 0.0, -5.0);

	scene->addCamera("top", false, 5.0, 1.0, 100.0);
	scene->cameras["top"]->setRotation(90.0, 0.0, 0.0);
	scene->cameras["top"]->setPosition(0.0, 0.0, -5.0);

	scene->setCurrentCamera("perspective");
}

void keyboardSpecial(int key, int x, int y){
	scene->keyboardSpecial(key, x, y);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	scene->begin(0, 0, 800, 600, "OO Premiere", 0, 0, 0);
	scene->lighting();
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










