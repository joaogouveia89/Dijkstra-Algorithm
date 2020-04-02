#ifndef PARSER_H
#define PARSER_H

#define EMPTY_SPACE ' '
#define LINE_BREAK '\0'
#define INFINITE 'i'

#define KRED  "\x1B[31m"
#define KWHT  "\x1B[37m"

#define STATE_0 0
#define STATE_1 1
#define STATE_2 2
#define STATE_3 3

/*
GRAMMAR

0 -> NUMBER - 1; (EMPTY_SPACE/LINE_BREAK) - 0; INFINITE - 3
1 -> NUMBER - 1; (EMPTY_SPACE/LINE_BREAK) - 2
2 -> (EMPTY_SPACE/LINE_BREAK) - 0
3 -> (EMPTY_SPACE/LINE_BREAK) - 2
*/

void throwInvalidCharacterError(char* line, int linePosition){
	printf("%sERROR:\n", KRED);
	printf("Invalid character: %c%s\n", line[linePosition], KWHT);
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
	int currentNumber = 0;
	int currentPosition;
	int hasError = 0;
	int state = STATE_0;
	int currentNumberChar;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), file) != NULL && hasError == 0){
		linePosition = 0;
		/*reading line*/
		while(buffer[linePosition] != LINE_BREAK && hasError == 0){
			if(state == STATE_0){
				currentNumberChar = ctoi(buffer[linePosition]);
				if(currentNumberChar != -1){
					currentNumber = currentNumber * 10 + currentNumberChar;
					state = STATE_1;
				}else if(buffer[linePosition] == INFINITE){
					state = STATE_3;
				}else if(buffer[linePosition] != EMPTY_SPACE && buffer[linePosition] != LINE_BREAK){
					hasError = 1;
				}
				linePosition++;
			}else if(state == STATE_1){
				currentNumberChar = ctoi(buffer[linePosition]);
				if(currentNumberChar != -1){
					currentNumber = currentNumber * 10 + currentNumberChar;
				}else if(buffer[linePosition] == EMPTY_SPACE || buffer[linePosition] == LINE_BREAK){
					state = STATE_2;
				}else{
					hasError = 1;
				}
			}else if(state == STATE_2){
				matrix = add(matrix, (float) currentNumber);
				currentNumber = 0;
				if(buffer[linePosition] == EMPTY_SPACE || buffer[linePosition] == LINE_BREAK){
					state = STATE_0;
				}else{
					hasError = 1;
				}
			}else if(state == STATE_3){
				matrix = add(matrix, (float) -1);
				if(buffer[linePosition] == EMPTY_SPACE || buffer[linePosition] == LINE_BREAK){
					state = STATE_0;
					linePosition++;
				}else{
					hasError = 1;
				}
			}
		}
	}

	array_print_debug(matrix->root);
	printf("has error %i\n", hasError);
}

#endif