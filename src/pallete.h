#ifndef PALLETE_H
#define PALLETE_H 

//colors
#define NODE_R 0.99f
#define NODE_G 0.25f
#define NODE_B 0.01f

#define LINK_R 0.99f
#define LINK_G 0.89f
#define LINK_B 0.01f

#define SQUARE_MINIMUM_SIZE 2.0f

typedef struct pallete_node_position PalleteNodePosition;

struct pallete_node_position
{
	Point point;
	PalleteNodePosition* next;
};

PalleteNodePosition* calculateNodesPositions(Matrix* matrix){
	PalleteNodePosition* root = NULL;
	return root;
}

void drawLink(int fromX, int fromY, int toX, int toY){
	glColor3f(LINK_R, LINK_G,LINK_B);
	glLineWidth(2.0);
	glBegin(GL_LINES);
            glVertex2f(fromX,fromY);
            glVertex2f(toX,toY); 
     glEnd();
}

void drawNode(Point nodeCenterPoint, int nodeId, int nodeCount){
 	glColor3f(NODE_R, NODE_G, NODE_B);
    float squareSize;
    float factor = 0;

    int aux = nodeCount/10;
    while(aux > 0){
        factor += 0.3;
        aux /= 10;
    }

    squareSize = SQUARE_MINIMUM_SIZE + factor;
     
    float halfSquareSize = squareSize/(float)2;
    glBegin(GL_POLYGON);
    	glVertex2f(nodeCenterPoint.x-halfSquareSize, nodeCenterPoint.y+halfSquareSize);
    	glVertex2f(nodeCenterPoint.x+halfSquareSize, nodeCenterPoint.y+halfSquareSize);
    	glVertex2f(nodeCenterPoint.x+halfSquareSize, nodeCenterPoint.y-halfSquareSize);
    	glVertex2f(nodeCenterPoint.x-halfSquareSize, nodeCenterPoint.y-halfSquareSize);
	 glEnd();
     renderNumber(nodeCenterPoint.x,nodeCenterPoint.y, nodeId, factor);
}

#endif