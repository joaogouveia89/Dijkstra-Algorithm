#ifndef PARSER_H
#define PARSER_H

void fromJson(char* path)
{
	char buffer[5000];
	FILE* json;
	json = fopen(path, "r");
	int count = 0;

	int linePosition = 0;

	/*reading file*/
	while(fgets(buffer, sizeof(buffer), json) != NULL){
		linePosition = 0;
		/*reading line*/
		while(buffer[linePosition] != '\0'){
			if(buffer[linePosition] != '\t' && buffer[linePosition] != ' ' && buffer[linePosition] != '\n'){
				printf("%c", buffer[linePosition]);
			}
			linePosition++;
		}
	}
}

#endif