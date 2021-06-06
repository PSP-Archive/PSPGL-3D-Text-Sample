
struct gltext_Param {
	int unicodechar;
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat width;
	GLfloat height;
	GLfloat endwidth;	
	GLfloat Red;
	GLfloat Green;
	GLfloat Blue;
	GLfloat Alpha;
	GLfloat drawnWidth;
} ;

/* structure containing the parameters for the DrawGLChar function */
/* */

int DrawGLChar(struct gltext_Param * agl_Char);
/* Draw a character as described by the structure */
