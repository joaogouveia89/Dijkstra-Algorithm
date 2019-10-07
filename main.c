#include "init.h"

int main(int argc, char *argv[])
{	if(argc == 2){
	char* inputFileName = argv[1];
	run_djikstra(inputFileName);

		// Node* a = init_node(1);
		// Node* b = init_node(2);
		// Link* l = link_create(l, 2, a);
		// b->links = lll_add(b->links, l);
		// lll_print_linked_nodes(b->links);
	}else{
		printf("Input must be only the file path with the input file\n");
	}

	int c = strtoi("392");
	int d = c + 4;
	printf("n = %i\n", d);
	return 0;
}