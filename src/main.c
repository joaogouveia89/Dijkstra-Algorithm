#include "init.h"

int main(int argc, char *argv[])
{	
	if(argc == 2){
		char* inputFileName = argv[1];
	}else{
		printf("Input must be only the file path with the input file\n");
	}
	return 0;
}