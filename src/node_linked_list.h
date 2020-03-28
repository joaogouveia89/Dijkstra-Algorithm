#ifndef NODE_LINKED_LIST_H
#define NODE_LINKED_LIST_H

#include "node.h"

/**
* DOUBLE LINKED LIST
*/
struct _nodeLinkedList
{
	Node* node;
	NodeLinkedList* next;
	NodeLinkedList* previous;
};

NodeLinkedList* nll_add(NodeLinkedList* list, Node* element){
	NodeLinkedList* newnllel = (NodeLinkedList*) malloc(sizeof(NodeLinkedList));
	newnllel->node = element;
	newnllel->next = newnllel;
	newnllel->previous = newnllel;

	if(list == NULL){
		list = newnllel;
	}else{
		NodeLinkedList* lastNode = list->previous;
		newnllel->next = list;
		list->previous = newnllel;
		newnllel->previous = lastNode;
		lastNode->next = newnllel;
	}

	return list;
}

Node* node_exists(NodeLinkedList* list, int nodeId){
	Node* node = NULL;
	if(list == NULL){
		return NULL;
	}
	NodeLinkedList* aux = list->next;
	if(aux == list){
		if(aux->node->id == nodeId){			
			node = aux->node;
		}
	}else{
		while(aux != list && aux->previous->node->id != nodeId){
			if(aux->node->id == nodeId){
				node = aux->node;
			}
			aux = aux->next;
		}
	}
	return node;
}


void nll_print_linked_nodes(NodeLinkedList* list){
	NodeLinkedList* aux = list->next;
	if(aux == list){
		printf("%d\n", aux->node->id);
	}else{
		printf("%d, ", list->node->id);
		while(aux != list){
			printf("%d, ", aux->node->id);
			aux = aux->next;
		}
		printf("\n");
	}
}

#endif // NODE_LINKED_LIST_H