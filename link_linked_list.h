#ifndef LINK_LINKED_LIST_H
#define LINK_LINKED_LIST_H

#include "node.h"

/**
* DOUBLE LINKED LIST
*/
struct _linkLinkedList
{
	Link* link;
	LinkLinkedList* next;
	LinkLinkedList* previous;
};

LinkLinkedList* lll_add(LinkLinkedList* list, Link* element){
	LinkLinkedList* newlllel = (LinkLinkedList*) malloc(sizeof(LinkLinkedList));
	newlllel->link = element;
	newlllel->next = newlllel;
	newlllel->next = newlllel;

	if(list == NULL){
		list = newlllel;
	}else{
		LinkLinkedList* lastNode = list->previous;
		newlllel->next = list;
		list->previous = newlllel;
		newlllel->previous = lastNode;
		lastNode->next = newlllel;
	}

	return list;
}

void lll_print_linked_nodes(LinkLinkedList* list){
	LinkLinkedList* aux = list->next;
	if(aux == list){
		printf("%c\n", aux->link->node->id);
	}else{
		while(aux != list){
			printf("%c, ", aux->link->node->id);
		}
		printf("\n");
	}
}

#endif // LINK_LINKED_LIST_H