#ifndef NODE_H
#define NODE_H

struct _node
{
	int number;
	LinkLinkedList* links;
};

Node* init_node(int number){
	Node* n = (Node*) malloc(sizeof(Node));
	n->number = number;
	n->links = NULL;
}

#endif // NODE_H