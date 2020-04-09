#include "init.h"

 int isTest(char* input);
 void testFunction();

int main(int argc, char *argv[])
{	
	if(argc == 2){
		char* inputFileName = argv[1];
		Matrix* distanceMatrix = NULL;
		if(isTest(inputFileName) == 1){
			testFunction();
		}else{
			distanceMatrix = fromFile(inputFileName);
			printf("Finish input parsing...\n");
		}
	}else{
		printf("Input must be only the file path with the input file\n");
	}
	return 0;
}

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