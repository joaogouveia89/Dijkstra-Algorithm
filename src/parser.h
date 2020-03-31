#ifndef PARSER_H
#define PARSER_H

void fromFile(char* path)
{
	char buffer[5000];
	FILE* file;
	file = fopen(path, "r");

	Matrix* matrix = newMatrix();

	matrix = add(matrix, '1');

	printf("%f\n", matrix->root->element);

	int linePosition = 0;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), file) != NULL){
		linePosition = 0;
		/*reading line*/
		while(buffer[linePosition] != '\0'){
			linePosition++;
		}
	}
}

#endif