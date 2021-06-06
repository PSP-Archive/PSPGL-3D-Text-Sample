#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include "gltextlight.h"


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
//	GLfloat drawnWidth;
//} ;

int DrawGLChar(struct gltext_Param * agl_Char)
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat width;
	GLfloat height;
	GLfloat endwidth;

	x = agl_Char->x;
	y = agl_Char->y;
	z = agl_Char->z;
	width = agl_Char->width;
	height = agl_Char->height;
	endwidth = agl_Char->endwidth;
	agl_Char->drawnWidth = width;

	glColor3f((*agl_Char).Red, (*agl_Char).Green, (*agl_Char).Blue);				// vertexcolor
	switch ((*agl_Char).unicodechar)
	{
	case 65:
	glBegin(GL_POLYGON);
		glVertex3f(x - (width/2), y, z);
		glVertex3f(x - (width/2) + endwidth, y, z);
		glVertex3f(x, y + height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x + (width/2), y, z);
		glVertex3f(x + ((width/2) - endwidth), y, z);
		glVertex3f(x, y + height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x - width/4, y + height/2, z);
		glVertex3f(x + width/4, y + height/2, z);
		glVertex3f(x + width/4, y + height/2 - endwidth, z);
	glEnd();
	agl_Char->drawnWidth = width-endwidth;

	break;
	case 66:
	//b
	glBegin(GL_POLYGON);
		glVertex3f(x-(width/2), y+height, z);
		glVertex3f(x-(width/2), y, z);
		glVertex3f(x-(width/2)+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height-(height/4 + endwidth/2), z);
		glVertex3f(x+width/2, y+height-(height/4 - endwidth/2), z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*(0.75f), z);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x-width/2, y+height/2-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x+width/2, y+height*(0.25f)+endwidth/2, z);
		glVertex3f(x+width/2, y+height*(0.25f)-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*(0.25f), z);
		glVertex3f(x-width/2, y+endwidth, z);
		glVertex3f(x-width/2, y, z);
	glEnd();
	break;
	case 67:
//C
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	break;
	case 68:
//D
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x-width/2, y+endwidth, z);
		glVertex3f(x-width/2, y, z);
	glEnd();
	break;
	case 69:
//E
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2, y+height-endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+endwidth, z);
		glVertex3f(x+width/2, y+endwidth, z);
		glVertex3f(x+width/2, y, z);
	glEnd();
	break;
	case 70:

	//F
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2,y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2,y+height, z);
		glVertex3f(x+width/2,y+height, z);
		glVertex3f(x+width/2, y+height-endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2-endwidth/2, z);
	glEnd();
		break;
	case 71:

//G
	glBegin(GL_POLYGON);
		glVertex3f(x,y+height, z);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y, z);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x+width/2-endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x, y+height/2-endwidth/2, z);
		glVertex3f(x, y+height/2+endwidth/2, z);
	glEnd();
		break;
	case 72:

//H
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2,y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2,y+height, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2-endwidth/2, z);
	glEnd();
	break;
	case 73:
//I
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2,y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	agl_Char->drawnWidth = endwidth;
	break;
	case 74:
	//J
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2, y+height*0.25f, z);
		glVertex3f(x+width/2-endwidth, y+height*0.25f, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*0.25f, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();

	break;
	case 75:
	//K
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2-endwidth, z);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	break;
	case 76:

	//l
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2, y+endwidth, z);
	glEnd();
	//agl_Char->drawnWidth = width;
	break;
	case 77:

	//m
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+endwidth/2, y, z);
		glVertex3f(x-endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2-endwidth, y, z);
		glVertex3f(x+width/2, y, z);
	glEnd();
	break;
	case 78:

	//n
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	break;
	case 79:

	//o
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y, z);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x+width/2-endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x-endwidth/2, y+height, z);
		glVertex3f(x+endwidth/2, y+height, z);
	glEnd();
	break;
	case 80:

	//p
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height*0.75f+endwidth/2, z);
		glVertex3f(x+width/2, y+height*0.75f-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*0.75f, z);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x-width/2, y+height/2-endwidth/2, z);
	glEnd();
	break;
	case 81:

	//q
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y, z);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x+width/2-endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x-endwidth/2, y+height, z);
		glVertex3f(x+endwidth/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height/2, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	break;
	case 82:

	//r
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height*0.75f+endwidth/2, z);
		glVertex3f(x+width/2, y+height*0.75f-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*0.75f, z);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x-width/2, y+height/2-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height/2, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y, z);
	glEnd();
	break;
	case 83:
	//s
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x, y+height-endwidth, z);
		glVertex3f(x-width/2, y+height*0.65f, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height*0.65f, z);
		glVertex3f(x+width/2, y+height*0.35f+endwidth/2, z);
		glVertex3f(x+width/2, y+height*0.35f-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*0.35f, z);
		glVertex3f(x-width/2, y+endwidth, z);
		glVertex3f(x-width/2, y, z);
	glEnd();

	break;
	case 84:
	//t
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y+height - endwidth/2, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	break;
	case 85:
	//u
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y+(height*0.25f)-endwidth/2, z);
		glVertex3f(x+width/2, y+(height*0.25f)+endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	break;
	case 86:
	//v
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
		glVertex3f(x, y, z);
	glEnd();
	break;
	case 87:

	//w
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth, y, z);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth, y, z);
		glVertex3f(x-endwidth/2, y+height, z);
		glVertex3f(x+endwidth/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2-endwidth, y, z);
		glVertex3f(x+endwidth/2, y+height, z);
		glVertex3f(x-endwidth/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2-endwidth, y, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
		break;
	case 88:

	//x
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x+width/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	break;
	case 89:

	//y
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x, y+height/2, z);
	glEnd();
	break;
	case 90:
	//z
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y+height-endwidth, z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2, y+endwidth, z);
	glEnd();
	break;
	case 49:
	//1
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height*(0.75f), z);
		glVertex3f(x, y+height, z);
		glVertex3f(x, y+height-endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	agl_Char->drawnWidth = width/2;
	break;
	case 50:
	//2
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height*(0.75f), z);
		glVertex3f(x, y+height, z);
		glVertex3f(x, y+height-endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x+width/2, y+height*(0.75f)-endwidth/2, z);
		glVertex3f(x+width/2, y+height*(0.75f)+endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*0.75f, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2, y+endwidth, z);
	glEnd();
	break;
	case 51:
	//3
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height-(height/4 + endwidth/2), z);
		glVertex3f(x+width/2, y+height-(height/4 - endwidth/2), z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*(0.75f), z);
		glVertex3f(x-width/2, y+height/2+endwidth/2, z);
		glVertex3f(x-width/2, y+height/2-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x+width/2, y+height*(0.25f)+endwidth/2, z);
		glVertex3f(x+width/2, y+height*(0.25f)-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*(0.25f), z);
		glVertex3f(x-width/2, y+endwidth, z);
		glVertex3f(x-width/2, y, z);
	glEnd();
	break;
	case 52:
	//4
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-endwidth/2, y, z);
		glVertex3f(x+endwidth/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-width/2, y+height*0.5f-endwidth/2, z);
		glVertex3f(x-width/2, y+height*0.5f+endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height*(0.5f), z);
		glVertex3f(x+width/2, y+height/2+endwidth/2, z);
		glVertex3f(x+width/2, y+height/2-endwidth/2, z);
	glEnd();
	break;
	case 53:
	//5
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2, y+height-(endwidth/2), z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y+height*0.66f, z);
		glVertex3f(x-width/2+endwidth, y+height*0.66f, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height*0.66f, z);
		glVertex3f(x+width/2, y+height*(0.33f)+endwidth/2, z);
		glVertex3f(x+width/2, y+height*(0.33f)-endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height*(0.33f), z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2, y+endwidth, z);
	glEnd();
	break;
	case 54:
	//6
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width/2, y+endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y, z);
		glVertex3f(x+width*0.165f, y+height*(0.33f), z);
		glVertex3f(x-width*0.165f-(endwidth/2), y+height*(0.33f)+endwidth/2, z);
	glEnd();
	break;
	case 55:
	//7
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y+height-(endwidth/2), z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth/2, y, z);
	glEnd();
	//glBegin(GL_POLYGON);
	//	glVertex3f(x-width/2, y+height/2, z);
	//	glVertex3f(x+width/2, y+height*(0.25)+endwidth/2, z);
	//	glVertex3f(x+width/2, y+height*(0.25)-endwidth/2, z);
	//glEnd();
	break;
	case 56:
	//8
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width/2, y+height-(endwidth/2), z);
		glVertex3f(x+width/2, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x+width/2, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y+endwidth, z);
		glVertex3f(x+width/2, y, z);
	glEnd();
	break;
	case 57:
	//9
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2, y+height-endwidth, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x+width/2, y+height, z);
		glVertex3f(x+width/2-endwidth, y+height, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x+width*0.165f, y+height*(0.66f), z);
		glVertex3f(x+width*0.165f-(endwidth/2), y+height*(0.66f)-endwidth/2, z);
	glEnd();
	break;
	case 48:
	//0
	//o
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height/2, z);
		glVertex3f(x-width/2+endwidth, y+height/2, z);
		glVertex3f(x, y, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y, z);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x+width/2-endwidth, y+height/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x+width/2, y+height/2, z);
		glVertex3f(x+width/2-endwidth, y+height/2, z);
		glVertex3f(x, y+height, z);
	glEnd();
	break;
	case 39:
	//'
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x-width/2+endwidth/2, y+height*0.75f, z);
	glEnd();
	agl_Char->drawnWidth = endwidth;
	break;
	case 33:
	//!
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x-width/2+endwidth/2, y+height*0.25f, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth/2, y+endwidth, z);
		glVertex3f(x-width/2, y+endwidth/2, z);
		glVertex3f(x-width/2+endwidth, y+endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth/2, y, z);
		glVertex3f(x-width/2, y+endwidth/2, z);
		glVertex3f(x-width/2+endwidth, y+endwidth/2, z);
	glEnd();
	agl_Char->drawnWidth = endwidth;
	break;
	case 34:
	//"
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y+height, z);
		glVertex3f(x-width/2+endwidth, y+height, z);
		glVertex3f(x-width/2+endwidth/2, y+height*0.75f, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x, y+height, z);
		glVertex3f(x-endwidth, y+height, z);
		glVertex3f(x-endwidth/2, y+height*0.75f, z);
	glEnd();
	agl_Char->drawnWidth = endwidth*2.0f;
	break;
	case 44:
	//,
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2, y, z);
		glVertex3f(x-width/2+endwidth, y, z);
		glVertex3f(x-width/2, y-height*0.25f, z);
	glEnd();
	agl_Char->drawnWidth = endwidth;
	break;
	case 46:
	//.
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth/2, y+endwidth, z);
		glVertex3f(x-width/2, y+endwidth/2, z);
		glVertex3f(x-width/2+endwidth, y+endwidth/2, z);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x-width/2+endwidth/2, y, z);
		glVertex3f(x-width/2, y+endwidth/2, z);
		glVertex3f(x-width/2+endwidth, y+endwidth/2, z);
	glEnd();
	agl_Char->drawnWidth = endwidth;
	break;
	case 32:
	agl_Char->drawnWidth = endwidth;

	}
	return 1;
}
