#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INPUT_TYPE_ID  0;
#define INPUT_TYPE_SIZE  1;

int is_valid_input(char c, int inputType){

}

void readFromFIle(char* path){
	FILE* file = fopen(path, "r");
	if( file == NULL){
		printf("Error openning the file. Program will exit\n");
		exit(1);
	}
	int c;
	int inputType = INPUT_TYPE_ID;
	while ((c = fgetc(file)) != EOF){
		char character = (char) c;
		if(character != ' ' && is_valid_input(character, inputType)){
			
		}
		printf("%c", (char)c);
	}
}

void run_djikstra(char* path){
	readFromFIle(path);
}

#endif // DIJKSTRA_H