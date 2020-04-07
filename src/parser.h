#ifndef PARSER_H
#define PARSER_H

#define EMPTY_SPACE ' '
#define LINE_BREAK '\n'
#define INFINITE 'i'
#define DECIMAL_SEPARATOR '.'

#define KRED  "\x1B[31m"
#define KWHT  "\x1B[37m"

/*
	MAX GRAPH NODES NUMBER = 1000
	VARIABLE TYPE = FLOAT -> UNIT SIZE = 1.2E-38 to 3.4E+38, 6 decimal places
	MAX LINK NUMBER = 10.000(arbitrary choice for security)
*/
float readNumber(char* number, int numberSize){
	int beforeSeparator = 0;
	int afterSeparator = 0;
	int separatorDivider = 1;
	int index;
	int currentCharInt;
	int isReadingDecimal = 1;
	int hasError = 0;
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
	return beforeSeparator + afterSeparator/(float)separatorDivider;
}

int readLine(char* line){
	return 1;
}

void fromFile(char* path)
{
	char buffer[5000];
	FILE* file;
	file = fopen(path, "r");

	Matrix* matrix = newMatrix();

	int linePosition = 0;
	int width = 0;
	int height = 0;
	float currentNumber = 0;
	int currentPosition;
	int hasError = 0;
	int currentLine = 0;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), file) != NULL && hasError == 0){
		linePosition = 0;
		currentLine++;
		/*reading line*/
		readLine(buffer);
	}
}

#endif