#include "init.h"

int main(int argc, char const *argv[])
{	if(argc == 2){
		printf("%s\n", argv[1]);
		Node* a = init_node(1);
		Node* b = init_node(2);
		Link* l = link_create(l, 2, a);
		b->links = lll_add(b->links, l);
		lll_print_linked_nodes(b->links);
	}
	return 0;
}