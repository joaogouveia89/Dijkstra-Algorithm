#ifndef NODE_H
#define NODE_H

struct _node
{
	int id;
	LinkLinkedList* links;
};

Node* init_node(int id){
	Node* n = (Node*) malloc(sizeof(Node));
	n->id = id;
	n->links = NULL;
}


#endif // NODE_H