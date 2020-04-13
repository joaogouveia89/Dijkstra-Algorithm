#include "init.h"

char* inputFileName;

void display();
void resize(int w, int h);
int isTest(char* input);
void testFunction();

int main(int argc, char *argv[])
{	
	if(argc == 2){
		inputFileName = argv[1];
		if(isTest(inputFileName) == 1){
			testFunction();
		}else{
			glutInit(&argc, argv);
		    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		    glutInitWindowPosition(100, 100);
		    glutCreateWindow(APP_NAME);
		    glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
			glMatrixMode(GL_PROJECTION);              // setup viewing projection
			glLoadIdentity();                           // start with identity matrix
			glOrtho(0.0, 50.0, 0.0, 50.0, 0.0, 0.1);   // setup a 10x10x2 viewing world
		    glutDisplayFunc(display);
		    glutReshapeFunc(resize);
		    glutMainLoop();
		}
	}else{
		printf("Input must be only the file path with the input file\n");
	}
	return 0;
}

/**
* OPEN GL
*/

void display() {
	Matrix* distanceMatrix = NULL;
	distanceMatrix = fromFile(inputFileName);
	printf("Finish input parsing...\n");
	glClear( GL_COLOR_BUFFER_BIT);
    drawNode(20, 20, 1);
    drawNode(35, 35, 2);
    drawLink(10, 10, 18, 18);
    glFlush();
}

void resize(int w, int h){
    glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

/**
* TEST
*/

 void testFunction(){
 	Matrix* distanceMatrix = NULL;
 	distanceMatrix = fromFile("input.txt");
 	float a = get(distanceMatrix, 4, 2);
 	printf("a = %f\n", a);
 }

 int isTest(char* input){
 	int response = 0;
 	if(input[0] == '-' &&
 		input[1] == '-' &&
 		input[2] == 't' &&
 		input[3] == 'e' &&
 		input[4] == 's' &&
 		input[5] == 't'){
 		response = 1;
 	}
 	return response;
 }