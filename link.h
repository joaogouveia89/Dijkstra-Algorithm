#ifndef LINK_H
#define LINK_H

struct _link
{
	int size;
	Node* node;
};

Link* link_create(Link* l, int size, Node* node){
	l = (Link*) malloc(sizeof(Link));
	l->size = size;
	l->node = node;
	return l;
}

#endif // LINK_H