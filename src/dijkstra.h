#ifndef DIJKSTRA_H
#define DIJKSTRA_H

NodeLinkedList* readFromFIle(char* path){
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
		currentNumber = 0;
		while(line[idx] != '\n'){
			char c = line[idx];
			if(is_valid_character(c)){
				if(c == '_'){
					// the _ separator indicates that the current number is a linked node
					Node* aux = node_exists(nodeList, currentNumber);
					// if node does not exist
					if(aux == NULL){
						printf("node %d does not exists\n", currentNumber);
						aux = init_node(currentNumber);
						nodeList = nll_add(nodeList, aux);
					}
					currentLink = link_init_node(currentLink, aux);
					currentNumber = 0;
				}else if(c == ' '){
					// the _ separator indicates that the current number is the link size
					currentLink->size = currentNumber;
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

	return nodeList;
}

void run_djikstra(char* path){
	NodeLinkedList* nodeList = NULL;
	printf("Reading input from file\n");	
	nodeList = readFromFIle(path);

	nll_print_linked_nodes(nodeList);
}

#endif // DIJKSTRA_H