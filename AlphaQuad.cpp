#include "AlphaQuad.h"


AlphaQuad::AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height,
                     GLfloat alpha,GLfloat alphaSpeed,GLfloat positionS,GLfloat positionT,
                     GLfloat speedS,GLfloat speedT)
{
    this->textureId=textureId;
    this->expansionMode=expansionMode;
    this->alpha=alpha;
    this->alphaSpeed=alphaSpeed;
    this->width=width;
    this->height=height;
    this->positionS=positionS;
    this->positionT=positionT;
    this->speedS=speedS;
    this->speedT=speedT;
    this->textureScale=1;
    this->textureScaleSpeed=0;
}

AlphaQuad::AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height)
{
    AlphaQuad(textureId,expansionMode,width,height,1,0,0,0,0,0);
}

AlphaQuad::AlphaQuad(int textureId,GLenum expansionMode,GLfloat width,GLfloat height,
          GLfloat alpha,GLfloat alphaSpeed)
{
    AlphaQuad(textureId,expansionMode,width,height,alpha,alphaSpeed,0,0,0,0);
}

AlphaQuad::~AlphaQuad()
{
    
}

void AlphaQuad::render()
{
    printf("AlphaQuad render\n");
    //Enables texturing
    glEnable(GL_TEXTURE_2D);
    //Disable lighting to use original texture lighting
    glDisable(GL_LIGHTING);
    
    
    //Enables texture blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0f,1.0f,1.0f,alpha);
    
    
    //Calculate center
    GLfloat x = 0.0 - (width/2.0);
    GLfloat y = 0.0 - (height/2.0);
    
    // Texture activation
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    /*
    //Texture displacement
    
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(positionS,positionT,0.0);
    glScalef(textureScale,textureScale,0.0);
    */
    
    // Quad drawing
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width,y,0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y + height,0.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,0.0);
    glEnd();
    
    
    /*
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
     */
    
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    positionS+=speedS;
    positionT+=speedT;
    textureScale+=textureScaleSpeed;
    alpha+=alphaSpeed;
}

void AlphaQuad::setExpansionMode(GLenum expansionMode) {
    this->expansionMode=expansionMode;
}
void AlphaQuad::setWidth(GLfloat width){
    this->width=width;
}
void AlphaQuad::setHeight(GLfloat height){
    this->height=height;
}
void AlphaQuad::setAlpha(GLfloat alpha){
    this->alpha=alpha;
}
void AlphaQuad::setAlphaSpeed(GLfloat alphaSpeed){
    this->alphaSpeed=alphaSpeed;
}
void AlphaQuad::setPositionS(GLfloat positionS){
    this->positionS=positionS;
}
void AlphaQuad::setPositionT(GLfloat positionT){
    this->positionT=positionT;
}
void AlphaQuad::setSpeedS(GLfloat speedS){
    this->speedS=speedS;
}
void AlphaQuad::setSpeedT(GLfloat speedT){
    this->speedT=speedT;
}
void AlphaQuad::setTextureScale(GLfloat textureScale){
    this->textureScale=textureScale;
}
void AlphaQuad::setTextureScaleSpeed(GLfloat textureScaleSpeed){
    this->textureScaleSpeed=textureScaleSpeed;
}



