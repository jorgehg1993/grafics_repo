#include "TextureManager.h"


TextureManager::TextureManager()
{
    
}

TextureManager::~TextureManager()
{
    
}

int TextureManager::loadTextureError(string name)
{
    textures[name]=INVALID_TEXTURE;
    printf("Error loading %s\n",name.c_str());
    return INVALID_TEXTURE;
}

int TextureManager::loadTexture(string name)
{
    GLuint texid=0;
    char path[MAXFILENAME];
    
    FILE *pFile;			   // File pointer
    TGAHEADER tgaHeader;	   // TGA file header
    unsigned long lImageSize;  // Size in bytes of image
    short sDepth;			   // Pixel depth;
    GLbyte	*pBits = NULL;     // Pointer to bits
    
    // Default/Failed values
    GLint iWidth = 0;
    GLint iHeight = 0;
    GLenum eFormat = GL_BGR_EXT;
    GLint iComponents = GL_RGB8;
    sprintf(path,"textures/%s.tga",name.c_str());
    // Attempt to open the file
    pFile = fopen(path, "rb");
    if(pFile == NULL)
        return loadTextureError(name);
        
    fread(&tgaHeader, sizeof(TGAHEADER), 1, pFile);
    
    // Get width, height, and depth of texture
    iWidth = tgaHeader.width;
    iHeight = tgaHeader.height;
    sDepth = tgaHeader.bits / 8;
    
    if(tgaHeader.bits != 8 && tgaHeader.bits != 24 && tgaHeader.bits != 32)
      return loadTextureError(name);
        
    // Calculate size of image buffer
    lImageSize = tgaHeader.width * tgaHeader.height * sDepth;
    pBits = (GLbyte*)malloc(lImageSize * sizeof(GLbyte));
    if(pBits == NULL)
       return loadTextureError(name);
        
        
        // Read in the bits
        // Check for read error. This should catch RLE or other
        // weird formats that I don't want to recognize
        if(fread(pBits, lImageSize, 1, pFile) != 1)
        {
            free(pBits);
            return loadTextureError(name);
        }
    
    // Set OpenGL format expected
    switch(sDepth)
    {
        case 3:     // Most likely case
            eFormat = GL_BGR_EXT;
            iComponents = GL_RGB8;
            break;
        case 4:
            eFormat = GL_BGRA_EXT;
            iComponents = GL_RGBA8;
            break;
        case 1:
            eFormat = GL_LUMINANCE;
            iComponents = GL_LUMINANCE8;
            break;
    };
    
    
    // Done with File
    fclose(pFile);
    
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D,texid);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_LINEAR);
    
    gluBuild2DMipmaps(GL_TEXTURE_2D,iComponents,iWidth,iHeight,eFormat,GL_UNSIGNED_BYTE,pBits);
    
    textures[name]=texid;
    printf("Texture %s loaded with id %d\n",name.c_str(),texid);
    free(pBits);
    return texid;
}

int TextureManager::getTextureId(string name)
{
    if(textures.count(name)==0)
        return loadTexture(name);
    return textures[name];
}

void TextureManager::activateTexture(int textureId)
{
    // Texture activation
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void TextureManager::activateTexture(string name)
{
    // Texture activation
    int textureId=getTextureId(name);
    if(textureId >= 0)
        activateTexture(textureId);
}

void TextureManager::textureCoordsGen(GLenum mode)
{
    if(mode!=DEFAULT_MODE)
    {
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        // Possible modes: GL_OBJECT_LINEAR GL_EYE_LINEAR GL_SPHERE_MAP
        glTexGenf(GL_S,GL_TEXTURE_GEN_MODE,mode);
        glTexGenf(GL_T,GL_TEXTURE_GEN_MODE,mode);
    }
}

void TextureManager::resetTexturing()
{
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}









