#ifndef LINK_LINKED_LIST_H
#define LINK_LINKED_LIST_H

typedef struct _linkLinkedList LinkLinkedList;

struct _linkLinkedList
{
	Link* link;
	LinkLinkedList* links;
};

#endif // LINK_LINKED_LIST_H