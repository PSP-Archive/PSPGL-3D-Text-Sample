//From cygwin version of Nehe tutorial lesson 6

// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//

// this was modified to work on PSP by Edorul (edorul@free.fr)
// Many Thanks to  jared bruni (jared@lostsidedead.com) for is
// MasterPiece3D port to PSP : it gave me a good sample and not
// the least a working makefile !

// important notes :  - all modified portion of code from cygwin version
//                                  of Nehe tutorial are marked with @@@
//                                - I leaved many printf in this source code to stay
//                                  as close as possible of the cygwin version of 
//                                  Nehe tutorial, but they won't be displayed on screen

// Used keys :
// START = exit 

#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <gltextlight.h>
//#include <unistd.h>     // needed to sleep. @@@

/* ascii code for the escape key */
//#define ESCAPE 27 @@@lsgl
//gl

/* The number of our GLUT window */
int window; 

/* floats for x rotation, y rotation, z rotation */
GLfloat xrot, yrot, zrot;
GLfloat zoom = 1.0f;
GLfloat animDir = -1.0f;
GLfloat xmov;				// X Movement ( AvA )

/* storage for one texture  */
unsigned int texture[1]; // @@@ int to GLuint

/* 3D character parameters */
//struct gltext_Param {
//	int unicodechar;
//	GLfloat x;
//	GLfloat y;
//	GLfloat z;
//	GLfloat width;
//	GLfloat height;
//	GLfloat endwidth;	
//	GLfloat Red;
//	GLfloat Green;
//	GLfloat Blue;
//	GLfloat Alpha;
//};
//
//typedef struct gltext_Param gltext_Param;


/* Image type - contains height, width, and data */
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};


typedef struct gltext_Param gltext_Param;
typedef struct Image Image;

// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  
// See http://www.dcs.ed.ac.uk/~mxr/gfx/2d/BMP.txt for more info.
int ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL)
    {
	printf("File Not Found : %s\n",filename);
	return 0;
    }
    
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
	printf("Error reading width from %s.\n", filename);
	return 0;
    }
    printf("Width of %s: %lu\n", filename, image->sizeX);
    
    // read the height 
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
	printf("Error reading height from %s.\n", filename);
	return 0;
    }
    printf("Height of %s: %lu\n", filename, image->sizeY);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
	printf("Error reading planes from %s.\n", filename);
	return 0;
    }
    if (planes != 1) {
	printf("Planes from %s is not 1: %u\n", filename, planes);
	return 0;
    }

    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
	printf("Error reading bpp from %s.\n", filename);
	return 0;
    }
    if (bpp != 24) {
	printf("Bpp from %s is not 24: %u\n", filename, bpp);
	return 0;
    }
	
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data. 
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
	printf("Error allocating memory for color-corrected image data");
	return 0;	
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
	printf("Error reading image data from %s.\n", filename);
	return 0;
    }

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
	temp = image->data[i];
	image->data[i] = image->data[i+2];
	image->data[i+2] = temp;
    }
    
    // we're done.
    return 1;
}
    
// Load Bitmaps And Convert To Textures
void LoadGLTextures() {	
    // Load Texture
    Image *image1;
    
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
	printf("Error allocating space for image");
	exit(0);
    }

    if (!ImageLoad("Data/NeHe.bmp", image1)) {
	exit(1);
    }        

    // Create Texture	
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
};

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
//    LoadGLTextures();				// Load The Texture(s) 
//    glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);	// Clear The Background Color To Blue 
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    
    gluPerspective(105.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
    
    glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
    if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
	Height=1;

    glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(70.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}


int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	float drawWidth = 0;
	float charWidth = 0.6f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View
	glTranslatef(xmov,-3.0f,-12.0f);
	xmov+=((0.01f)*animDir);

		if(((xmov < -10.0f) && (animDir==-1.0f)) | ((xmov > 10.0f) && (animDir==1.0f)))
		{
			animDir = animDir * -1.0f;
//			xmov = 0;
		}

	glRotatef(45.5f,0.0f,1.0f,0.0f);
	glRotatef(45.5f,0.0f,0.0f,1.0f);

	gltext_Param myGLChar;

	char myText[] = "I'M HAVIN' A GOOD TIME! ... OPENGL ROCKS! ... PSPGL 2!!'";

	myGLChar.x = 0.0f;
	myGLChar.y = -1.0f;
	myGLChar.z = 0.0f;
	myGLChar.height = 1.0f * (zoom);
	myGLChar.width = charWidth * (zoom);
	myGLChar.Red = 0.0f;
	myGLChar.Green = 0.0f;
	myGLChar.Blue = 0.0f;
	myGLChar.endwidth = 0.1f;
	myGLChar.unicodechar = 65;
	//for(int i=0;i<6;i++)
	//{
	int i=0;
	while(myText[i] != '\0')
	{
	glRotatef(xrot,1.0f,0.0f,0.0f);
		myGLChar.x = drawWidth;
		myGLChar.z = 0.0f;
		myGLChar.y = myGLChar.y - (zoom / 18.0f *i-1.0f);
		myGLChar.unicodechar = myText[i];
		myGLChar.endwidth = charWidth*0.2f*zoom;
		myGLChar.width = charWidth*zoom;
		myGLChar.height = charWidth*2.0f*zoom;
		myGLChar.Red = 0.0f;
		myGLChar.Green = 0.0f;
		myGLChar.Blue = 0.0f;
		DrawGLChar(&myGLChar);
		
//		myGLChar.y = myGLChar.y + ((zoom / 15 *i)-1.0f);
		myGLChar.z = -0.02f;
		myGLChar.y += 0.0001f;//*animDir;
		myGLChar.width = charWidth*zoom+0.05f;
		myGLChar.endwidth = charWidth*0.2f*zoom+0.05f;
		myGLChar.height = charWidth*2.0f*zoom+0.05f;
		myGLChar.Red = 0.7f;
		myGLChar.Green = 0.6f;
		myGLChar.Blue = 0.5f;
		DrawGLChar(&myGLChar);

		i++;
		//myGLChar.Red = 0.0f;
		//myGLChar.endwidth = 0.10f*zoom;
		//myGLChar.width = 0.5f*zoom;
		//myGLChar.height = 1.0*zoom;
		//DrawGLChar(&myGLChar);
//		drawWidth = 0.60f;
		drawWidth += myGLChar.drawnWidth+(0.15f*zoom);
		
		xrot += 0.002f;
//		yrot += 0.03f;
		//zrot += 0.004f;
// 		zoom+=(0.0001f*animDir); 
	}
	glutSwapBuffers();
	return 1;										// Keep Going
}

/* The function called whenever a key is pressed. */
// @@@ this function is modified to use PSP pad
void keyPressed(unsigned char key, int x, int y) 
{
	switch(key){
		/* If START is pressed, kill everything. */
		case 'a':			/* startbutton */
			/* shut down our window */
			// but don't exist in pspgl
//			glutDestroyWindow(window);  @@@
	
			/* exit the program...normal termination. */
			exit(0);                   
	default:
		;
	}
}

int main(int argc, char **argv) 
{  
    /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
       X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
    glutInit(&argc, argv);  

    /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Alpha components supported 
     Depth buffer */  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

    /* get a 640 x 480 window */
    glutInitWindowSize(480, 272);  // @@@ 

    /* the window starts at the upper left corner of the screen */
    glutInitWindowPosition(0, 0);  

    /* Open a window */  
    window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(&DrawGLScene);  

    /* Go fullscreen.  This is as soon as possible. */
//    glutFullScreen(); @@@  there is no glutFullScreen in pspgl

    /* Even if there are no events, redraw our gl scene. */
    glutIdleFunc(&DrawGLScene);

    /* Register the function called when our window is resized. */
    glutReshapeFunc(&ReSizeGLScene);

    /* Register the function called when the keyboard is pressed. */
    glutKeyboardFunc(&keyPressed);

    /* Initialize our window. */
    InitGL(480, 272);  // @@@
  
    /* Start Event Processing Engine */  
    glutMainLoop();  

    return 1;
}

