#ifndef DIJKSTRA_H
#define DIJKSTRA_H

void readFromFIle(char* path){
	Node* currentNode = NULL;
	NodeLinkedList* nodeList = NULL;
	Link* currentLink = NULL;
	int idx = 0;
	int currentNumber = 0;
	int size;

	FILE* file = fopen(path, "r");
	if( file == NULL){
		printf("Error openning the file. Program will exit\n");
		exit(1);
	}
	char line[200];
	int lineNumber = 1;
	while (fgets(line, 200, file) != NULL){
		currentNode = init_node(lineNumber);
		while(line[idx] != '\n'){
			char c = line[idx];
			if(is_valid_character(c)){
				if(c == '_'){
					// the _ separator indicates that the current number is a linked node
					Node* aux = node_exists(nodeList, currentNumber);
					// if node does not exist
					if(aux == NULL){
						aux = init_node(currentNumber);
						nodeList = nll_add(nodeList, aux);
					}
					currentLink = link_init_node(currentLink, aux);
					currentNumber = 0;
				}else if(c == ' '){
					// the _ separator indicates that the current number is the link size
					currentLink->size = currentNumber;
					printf("%i\n", currentLink->size);
					currentNode->links = lll_add(currentNode->links, currentLink);
					currentNumber = 0;
				}else if(c != '\n' /* whenever the code reaches here the number is or a line break or a number*/){
					currentNumber = currentNumber * 10 + ctoi(c);
				}
			}
			idx++;
			if(line[idx] == '\n'){
				nodeList = nll_add(nodeList, currentNode);

			}
		}
		lineNumber++;
		idx = 0;
	}
}

void run_djikstra(char* path){
	printf("Reading input from file\n");	
	readFromFIle(path);
}

#endif // DIJKSTRA_H