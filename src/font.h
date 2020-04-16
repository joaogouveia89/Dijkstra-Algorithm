#ifndef FONT_H
#define FONT_H 

// thanks to https://www.lighthouse3d.com/tutorials/glut-tutorial/bitmap-fonts/
void renderNumber(float x, float y, int id){
	char charNum =  itoc(id);
	glColor3f(1.0f, 1.0f,1.0f);
	glRasterPos2f(x-0.3, y-0.3);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, charNum);
}
#endif