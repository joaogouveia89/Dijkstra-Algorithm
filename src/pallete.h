#ifndef PALLETE_H
#define PALLETE_H 

//colors
#define NODE_R 0.99f
#define NODE_G 0.25f
#define NODE_B 0.01f

#define LINK_R 0.99f
#define LINK_G 0.89f
#define LINK_B 0.01f

#define NODE_CIRCLE_RADIUS 2.5f

void drawLink(int fromX, int fromY, int toX, int toY){
	glColor3f(LINK_R, LINK_G,LINK_B); 
	glLineWidth(2.0);
	glBegin(GL_LINES);
            glVertex2f(fromX,fromY);
            glVertex2f(toX,toY); 
     glEnd();
}

void drawNode(int originX, int originY, int id){
 	glColor3f(NODE_R, NODE_G, NODE_B);
 	int theta = 0;
    float x,y;
    glBegin(GL_POLYGON);
    for(theta = 0; theta < 360; theta++){
    	x = NODE_CIRCLE_RADIUS * sin(theta) + originX;
    	y = -NODE_CIRCLE_RADIUS * cos(theta) + originY;
		glVertex2f(x, y);
    }
	 glEnd();
}

#endif