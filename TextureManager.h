#include "Classes.h"

using namespace std;

//Struct for the Targa format file header
#pragma pack(1)
typedef struct
{
    GLbyte	identsize;              // Size of ID field that follows header (0)
    GLbyte	colorMapType;           // 0 = None, 1 = paletted
    GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
    unsigned short	colorMapStart;  // First colour map entry
    unsigned short	colorMapLength; // Number of colors
    unsigned char 	colorMapBits;   // bits per palette entry
    unsigned short	xstart;         // image x origin
    unsigned short	ystart;         // image y origin
    unsigned short	width;          // width in pixels
    unsigned short	height;         // height in pixels
    GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
    GLbyte	descriptor;             // image descriptor
} TGAHEADER;
#pragma pack(8)

class TextureManager
{
   public:
       TextureManager();
       ~TextureManager();
       void addTexture(string name);
       int getTextureId(string name);
       void activateTexture(string name);
       void activateTexture(int textureId);
       void textureCoordsGen(GLenum mode);
       void resetTexturing();
    
   private:
       map <string, int> textures;
       int loadTexture(string name);
       int loadTextureError(string name);
    
};



















