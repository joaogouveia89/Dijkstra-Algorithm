#ifndef PARSER_H
#define PARSER_H

#define EMPTY_SPACE ' '
#define LINE_BREAK '\0'

void fromFile(char* path)
{
	char buffer[5000];
	FILE* file;
	file = fopen(path, "r");

	Matrix* matrix = newMatrix();

	int linePosition = 0;
	int width = 0;
	int height = 0;
	int numBuffer = 0;
	int currentPosition;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), file) != NULL){
		linePosition = 0;
		/*reading line*/
		while(buffer[linePosition] != LINE_BREAK){
			currentPosition = ctoi(buffer[linePosition]);
			if(currentPosition != -1){
				numBuffer = numBuffer * 10 + currentPosition;
			}else if(buffer[linePosition] == EMPTY_SPACE){
				matrix = add(matrix, (float) numBuffer);
				numBuffer = 0;
				if(matrix->height == 0){
					matrix = set_matrix_width(matrix, matrix->width + 1);
				}
			}
			
			linePosition++;
		}
		matrix = set_matrix_heigth(matrix, matrix->height + 1);
	}

	printf("width = %i, height = %i\n", matrix->width, matrix->height);
}

#endif