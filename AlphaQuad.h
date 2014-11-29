#pragma once
#include "Classes.h"
#include "SceneObject.h"
using namespace std;

class AlphaQuad : SceneObject
{
public:
    AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height);
    AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height,
              GLfloat alpha,GLfloat alphaSpeed);
    AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height,
              GLfloat alpha,GLfloat alphaSpeed,GLfloat positionS,GLfloat positionT,
              GLfloat speedS,GLfloat speedT);
    ~AlphaQuad();
    void render();
    void setExpansionMode(GLenum expansionMode);
    void setWidth(GLfloat width);
    void setHeight(GLfloat height);
    void setAlpha(GLfloat alpha);
    void setAlphaSpeed(GLfloat alphaSpeed);
    void setPositionS(GLfloat positionS);
    void setPositionT(GLfloat positionT);
    void setSpeedS(GLfloat speedS);
    void setSpeedT(GLfloat speedT);
    void setTextureScale(GLfloat textureScale);
    void setTextureScaleSpeed(GLfloat textureScaleSpeed);
    
private:
    GLuint textureID;
    GLenum expansionMode;
    GLfloat width;
    GLfloat height;
    GLfloat alpha;
    GLfloat alphaSpeed;
    GLfloat positionS;
    GLfloat positionT;
    GLfloat speedS;
    GLfloat speedT;
    GLfloat textureScale;
    GLfloat textureScaleSpeed;
};



