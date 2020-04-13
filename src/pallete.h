#ifndef PALLETE_H
#define PALLETE_H 


void drawLink(int fromX, int fromY, int toX, int toY){
	glColor3f(1.0,1.0,1.0); 
	glLineWidth(2.0);
	glBegin(GL_LINES);
            glVertex2f(fromX,fromY);
            glVertex2f(toX,toY); 
     glEnd();
}

void drawNode(int originX, int originY, int id){
 	glColor3f(0.0, 1.0, 0.0);
 	int theta = 0;
 	float radius = 2.5;
    float x,y;
    glBegin(GL_POLYGON);
    for(theta = 0; theta < 360; theta++){
    	x = radius * sin(theta) + originX;
    	y = -radius * cos(theta) + originY;
		glVertex2f(x, y);
    }
	 glEnd();
}

#endif