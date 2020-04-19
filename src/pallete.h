#ifndef PALLETE_H
#define PALLETE_H 

//colors
#define NODE_R 0.99f
#define NODE_G 0.25f
#define NODE_B 0.01f

#define LINK_R 0.99f
#define LINK_G 0.89f
#define LINK_B 0.01f

#define SQUARE_MINIMUM_SIZE 4.0f

typedef struct pallete_node_position PalleteNodePosition;

struct pallete_node_position
{
	Point point;
	PalleteNodePosition* next;
};

PalleteNodePosition* add_position(PalleteNodePosition* root, Point position){
    PalleteNodePosition* newPosition = (PalleteNodePosition*) malloc(sizeof(PalleteNodePosition));
    newPosition->point = position;
    newPosition->next = NULL;

    PalleteNodePosition* aux = root;

    if(aux == NULL){
        root = newPosition;
    }else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newPosition;
    }
    return root;
}

PalleteNodePosition* calculateNodesPositions(Matrix* matrix){
	PalleteNodePosition* root = NULL;
    int index = 0;
    float x = 30;
    float y = 90;
    for(index = 0; index < matrix->width; index++){
        Point point;
        point.x = x;
        point.y = y;
        root = add_position(root, point);
        x+=10;
        y-=10;
    }
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

void drawNodes(PalleteNodePosition* nodes, int nodeCount){
    PalleteNodePosition* aux = nodes;
    int index = 0;
    while(aux != NULL){
        drawNode(aux->point, index, nodeCount);
        index++;
        aux = aux->next;
    }

}

#endif