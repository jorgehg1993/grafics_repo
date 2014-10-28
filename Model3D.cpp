#include "Model3D.h"


Model3D::Model3D(string modelName) : SceneObject()
{
	char fileName[MAXFILENAME];

	sprintf_s(fileName, MAXFILENAME, "models/%s.obj", modelName.c_str());
	displayList = 0;
	model = glmReadOBJ(fileName);
	if (model){
		glmUnitize(model);
		glmFacetNormals(model);
		glmVertexNormals(model, 90.0);
	}
}

void Model3D::render()
{
	glPushAttrib(GL_COLOR_MATERIAL); 
	
	// First time, create display list!
	if (displayList)
		displayList = glmList(model, GLM_SMOOTH | GLM_MATERIAL); 
	

	// If displayList is available, draws from it, else draws from model structure!
	if (displayList)
		glCallList(displayList); 
	else
		glmDraw(model, GLM_SMOOTH | GLM_MATERIAL); 
	

	glPopAttrib(); 
}

Model3D::~Model3D()
{
	printf("~Model3D()");

	if(model)
		glmDelete(model);
	
	deleteVectors();
}

void Model3D::setPosition(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setPosition(x, y, z);
}

void Model3D::setSpeed(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setSpeed(x, y, z);
}

void Model3D::setRotation(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setRotation(x, y, z);
}

void Model3D::setRotationSpeed(GLfloat x, GLfloat y, GLfloat z){
	SceneObject::setRotationSpeed(x, y, z);
}