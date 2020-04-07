#include "init.h"

int main(int argc, char *argv[])
{	
	if(argc == 2){
		char* inputFileName = argv[1];
		fromFile(inputFileName);
	}else{
		float a = readNumber("3.12", 4);
		printf("number is %f\n", a);
		printf("Input must be only the file path with the input file\n");
	}
	return 0;
}