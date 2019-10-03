#ifndef NODE_H
#define NODE_H

struct _node
{
	char id;
	LinkLinkedList* links;
};

Node* init_node(char id){
	Node* n = (Node*) malloc(sizeof(Node));
	n->id = id;
	n->links = NULL;
}

#endif // NODE_H