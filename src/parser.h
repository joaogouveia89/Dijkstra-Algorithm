#ifndef PARSER_H
#define PARSER_H

#define EMPTY_SPACE ' '
#define LINE_BREAK '\n'
#define INFINITE 'i'
#define DECIMAL_SEPARATOR '.'
#define END_OF_FILE '\0'

#define KRED  "\x1B[31m"
#define KWHT  "\x1B[37m"

/*
	MAX GRAPH NODES NUMBER = 1000
	VARIABLE TYPE = FLOAT -> UNIT SIZE = 1.2E-38 to 3.4E+38, 6 decimal places
	MAX LINK NUMBER = 10.000(arbitrary choice for security)
*/

/**
* function to convert a char* number to float
* params: 
* char* number => number to be converted
* numberSize => size of the number to be converted
* if the number is infinite, returns -1
* if the number is invalid returns -2
* otherwise returns the converted number
*/
float readNumber(char* number, int numberSize){
	int beforeSeparator = 0;
	int afterSeparator = 0;
	int separatorDivider = 1;
	int index;
	int currentCharInt;
	int isReadingDecimal = 1;
	int hasError = 0;

	if(numberSize == 1 && number[0] == 'i'){
		return -1.0;
	}
	for(index = 0; index < numberSize && hasError == 0; index++){
		currentCharInt = ctoi(number[index]);
		if(currentCharInt == -1 && number[index] != DECIMAL_SEPARATOR){
			hasError = 1;
		}else if(currentCharInt == -1){
			isReadingDecimal = 0;
		}else{
			if(isReadingDecimal){
				beforeSeparator = beforeSeparator * 10 + currentCharInt;
			}else{
				separatorDivider *= 10;
				afterSeparator = afterSeparator * 10 + currentCharInt;
			}
		}
	}
	if(hasError == 1){
		return -2.0;
	}
	return beforeSeparator + afterSeparator/(float)separatorDivider;
}

Matrix* readLine(Matrix* matrix, char* line){
	char numBuffer[11]; //consider that the max number lenght will be 9999.999999
	int lineIndex = 0;
	int bufferIndex = 0;
	float number;
	int isFirstLine = 0;

	if(matrix->root == NULL){
		isFirstLine = 1;
	}
	while(line[lineIndex] != LINE_BREAK && line[lineIndex] != END_OF_FILE){
		if(line[lineIndex] != EMPTY_SPACE){
			numBuffer[bufferIndex] = line[lineIndex];
			bufferIndex++;
		}else{
			number = readNumber(numBuffer, bufferIndex);
			matrix = add(matrix, number);
			if(isFirstLine == 1){
				matrix = set_matrix_width(matrix, matrix->width + 1);
			}
			bufferIndex = 0;
		}
		lineIndex++;
	}

	number = readNumber(numBuffer, bufferIndex);
	matrix = add(matrix, number);
	if(isFirstLine == 1){
		matrix = set_matrix_width(matrix, matrix->width + 1);
	}
	return matrix;
}

Matrix* fromFile(char* path)
{
	char buffer[5000];
	FILE* file;
	file = fopen(path, "r");

	Matrix* matrix = newMatrix();

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), file) != NULL){
		/*reading line*/
		matrix = readLine(matrix, buffer);
		matrix = set_matrix_height(matrix, matrix->height + 1);
	}

	return matrix;
}

#endif