#include "Scene.h"

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;

Scene::Scene(){
	lightManager = new LightManager();
}

void Scene::begin(int left, int top, int width, int height,
	string title, GLfloat r, GLfloat g, GLfloat b)
{
	srand(time(NULL));
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(left, top);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glClearColor(r, g, b, 1.0);
	setFrameRate(30);
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	addCamera("default", true, 45, 1.0, 1000.0);
	cameras["default"]->setPosition(0.0, 0.0, -5.0);
	currentCamera = cameras["default"];
}


void Scene::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	lightManager->lightScene();
	glLoadIdentity();
	map<string, SceneObject *>::const_iterator iter;
	for (iter = objects.begin(); iter != objects.end(); ++iter)
	{
		SceneObject *o = (SceneObject *)iter->second;
		o->update();
	}
	glutSwapBuffers();
}

void Scene::resize(int currentWidth, int currentHeight)
{
	windowWidth = currentWidth;
	windowHeight = currentHeight;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (currentCamera->getPerspective())
	{
		GLfloat aspect = (GLfloat)windowWidth / (GLfloat)windowHeight;
		gluPerspective(currentCamera->getFovy(), aspect,
			currentCamera->getNear(), currentCamera->getFar());
	}
	else
	{
		glOrtho(currentCamera->getLeft(), currentCamera->getRight(),
			currentCamera->getBottom(), currentCamera->getTop(),
			currentCamera->getNear(), currentCamera->getFar());
	}
	Vec *position = currentCamera->getPosition();
	Vec *rotation = currentCamera->getRotation();
	glRotatef(rotation->x, 1.0, 0.0, 0.0);
	glRotatef(rotation->y, 0.0, 1.0, 0.0);
	glRotatef(rotation->z, 0.0, 0.0, 1.0);
	glTranslatef(position->x, position->y, position->z);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_MODELVIEW);
}

void Scene::keyboard(unsigned char key, int x, int y)
{
	int yrotation = currentCamera->getRotation()->y;
	yrotation = yrotation % 360;
	printf("%i", yrotation);

	currentCamera->getRotation()->printVec();
	switch (key) {
		case 'w':
		case 'W':
			
			//Diagonal arriba derecha
			if ((yrotation > 0.0  && yrotation <= 90) || (yrotation < -270)){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, DELTA_TRAN);
			}
			//Diagonal abajo derecha
			else if ((yrotation > 90 && yrotation <= 180) || (yrotation < -180 && yrotation >= -270)){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, -DELTA_TRAN);
			}
			//Diagonal abajo izquierda
			else if (yrotation > 180 && yrotation <= 270 || (yrotation < -90 && yrotation >= -180)){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, -DELTA_TRAN);
			}
			else if (yrotation == 0.0){
				currentCamera->setSpeed(0.0, 0.0, DELTA_TRAN);
			}
			//Diagonal arriba izquierda
			else if (yrotation > 270 || (yrotation < 0 && yrotation >= -90)){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, DELTA_TRAN);
			}

			currentCamera->getPosition()->add(currentCamera->getSpeed());
			resize(windowWidth, windowHeight);

			resize(windowWidth, windowHeight);

			break;
		case 's':
		case 'S':
			if ((yrotation > 0.0  && yrotation <= 90) || (yrotation < -270)){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, -DELTA_TRAN);
			}
			else if ((yrotation > 90 && yrotation <= 180) || (yrotation < -180 && yrotation >= -270)){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, DELTA_TRAN);
			}
			else if (yrotation == 0.0){
				currentCamera->setSpeed(0.0, 0.0, -DELTA_TRAN);
			}
			else if (yrotation > 180 && yrotation <= 270 || (yrotation < -90 && yrotation >= -180)){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, DELTA_TRAN);
			}
			else if (yrotation > 270 || (yrotation < 0 && yrotation >= -90)){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, -DELTA_TRAN);
			}

			currentCamera->getPosition()->add(currentCamera->getSpeed());
			resize(windowWidth, windowHeight);
			break;
		case 'a':
		case 'A':
			currentCamera->setRotationSpeed(0.0, -DELTA_ROT, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;
		
		case 'd':
		case 'D':
			currentCamera->setRotationSpeed(0.0, DELTA_ROT, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;
		case 'p':
		case 'P':
			setCurrentCamera("perspective");
			resize(windowWidth, windowHeight);
			break;
		case 'f':
		case 'F':
			setCurrentCamera("front");
			resize(windowWidth, windowHeight);
			break;
		//case 's':
		//case 'S':
		//	setCurrentCamera("side");
		//	resize(windowWidth, windowHeight);
		//	break;
		case 't':
		case 'T':
			setCurrentCamera("top");
			resize(windowWidth, windowHeight);
			break;
		case 'c':
		case 'C':
			setCurrentCamera("custom");
			resize(windowWidth, windowHeight);
			break;
		case 'q':
		case 'Q':
			setCurrentCamera("taza_cam");
			resize(windowWidth, windowHeight);
			break;
		case 'x':
			currentCamera->setRotationSpeed(DELTA_ROT, 0.0, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;
		case 'X':
			currentCamera->setRotationSpeed(-DELTA_ROT, 0.0, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;
		case 'y':
			currentCamera->setRotationSpeed(0.0, DELTA_ROT, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);	
			break;
		case 'Y':
			currentCamera->setRotationSpeed(0.0, -DELTA_ROT, 0.0);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;
		case 'z':
			currentCamera->setRotationSpeed(0.0, 0.0, DELTA_ROT);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);			
			break;
		case 'Z':
			currentCamera->setRotationSpeed(0.0, 0.0, -DELTA_ROT);
			currentCamera->getRotation()->add(currentCamera->getRotationSpeed());
			resize(windowWidth, windowHeight);
			break;

		case ESC:
			end();
			break;

	}
}

void Scene::keyboardSpecial(int key, int x, int y)
{
	int yrotation = currentCamera->getRotation()->y;
	yrotation = yrotation % 360;
	printf("%d", yrotation);

	currentCamera->getRotation()->printVec();

	switch (key){
		case GLUT_KEY_UP:
			currentCamera->setSpeed(0.0, DELTA_TRAN, 0.0);
			currentCamera->getPosition()->add(currentCamera->getSpeed());
			currentCamera->getPosition()->printVec();
			resize(windowWidth, windowHeight);
			break;

		case GLUT_KEY_DOWN:
			currentCamera->setSpeed(0.0, -DELTA_TRAN, 0.0);
			currentCamera->getPosition()->add(currentCamera->getSpeed());
			currentCamera->getPosition()->printVec();
			resize(windowWidth, windowHeight);
			break;

		case GLUT_KEY_RIGHT:
			currentCamera->setSpeed(-DELTA_TRAN, 0.0, 0.0);
			currentCamera->getPosition()->add(currentCamera->getSpeed());
			currentCamera->getPosition()->printVec();
			resize(windowWidth, windowHeight);
			break;

		case GLUT_KEY_LEFT:
			currentCamera->setSpeed(DELTA_TRAN, 0.0, 0.0);
			currentCamera->getPosition()->add(currentCamera->getSpeed());
			currentCamera->getPosition()->printVec();
			resize(windowWidth, windowHeight);
			break;

		case GLUT_KEY_PAGE_UP:			
			if (yrotation > 0.0  && yrotation <= 180 || yrotation < -180){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, DELTA_TRAN);
			} else if (yrotation == 0.0){
				currentCamera->setSpeed(0.0, 0.0, DELTA_TRAN);
			} else if (yrotation < 0.0 || yrotation > 180 ){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, DELTA_TRAN);
			}

			currentCamera->getPosition()->add(currentCamera->getSpeed());
			resize(windowWidth, windowHeight);
			break;

		case GLUT_KEY_PAGE_DOWN:

			if (yrotation > 0.0  && yrotation <= 180 || yrotation < -180){
				currentCamera->setSpeed(DELTA_TRAN, 0.0, -DELTA_TRAN);
			}
			else if (yrotation == 0.0){
				currentCamera->setSpeed(0.0, 0.0, -DELTA_TRAN);
			}
			else if (yrotation < 0.0 || yrotation > 180){
				currentCamera->setSpeed(-DELTA_TRAN, 0.0, -DELTA_TRAN);
			}
			currentCamera->getPosition()->add(currentCamera->getSpeed());
			resize(windowWidth, windowHeight);
			break;
		default:
			break;

	}
}

void Scene::end()
{
	map<string, SceneObject *>::const_iterator iter; 
	for (iter = objects.begin(); iter != objects.end(); ++iter){
		SceneObject *o = (SceneObject *)iter->second; 
		printf("object:%s cleanup:", ((string)iter->first).c_str()); 
		delete o; 
	}

	map<string, Camera *>::const_iterator itercam; 
	for (itercam = cameras.begin(); itercam != cameras.end(); ++itercam){
		SceneObject *c = (SceneObject *)itercam->second; 
		printf("camera:%s cleanup:", ((string)itercam->first).c_str()); 
		delete c; 
	}

	cameras.clear(); 
	objects.clear(); 
	exit(0);
}

void Scene::add(SceneObject *newObject, string name)
{
	objects[name] = newObject;
}

void Scene::addCamera(string name, bool perspective, GLfloat fovy, GLfloat nearPlane, GLfloat farPlane)
{
	cameras[name] = new Camera(perspective, fovy, nearPlane, farPlane);
}

void Scene::setCurrentCamera(string name)
{
	currentCamera = cameras[name];
}

void Scene::idle()
{
	GLint timeDifference = glutGet(GLUT_ELAPSED_TIME) - currentTime;
	if (timeDifference > frameTime)
	{
		currentFrame++;
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();
	}
}

void Scene::setFrameRate(int frameRate)
{
	this->frameRate = frameRate;
	this->frameTime = 1000 / frameRate;
}

LightManager* Scene::getLightManager(){
	return lightManager;
}