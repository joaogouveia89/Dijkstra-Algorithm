#ifndef PARSER_H
#define PARSER_H

void fromJson(char* path)
{
	char buffer[5000];
	FILE* json;
	json = fopen(path, "r");
	int blockCounter = 0; // must finish == 0 otherwise json is invalid

	int linePosition = 0;
	int isLinkBlock = 0;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), json) != NULL){
		linePosition = 0;
		/*reading line*/
		while(buffer[linePosition] != '\0'){
			if(buffer[linePosition] != '\t' && buffer[linePosition] != ' ' && buffer[linePosition] != '\n'){
				//block counter control
				if(buffer[linePosition] == '{' || buffer[linePosition] == '['){
					blockCounter++;
				}else if(buffer[linePosition] == '}' || buffer[linePosition] == ']'){
					blockCounter--;
				}

				if(buffer[linePosition] == '"' &&
				 buffer[linePosition + 1] == 'l' &&
				  buffer[linePosition + 2] == 'i' &&
				   buffer[linePosition + 3] == 'n' &&
				    buffer[linePosition + 4] == 'k' &&
				     buffer[linePosition + 5] == 's' &&
				      buffer[linePosition + 6] == '"'){
					isLinkBlock = 1;
				}

			}
			linePosition++;
		}
	}
	printf("isLinkBlock = %i\n", isLinkBlock);
}

#endif