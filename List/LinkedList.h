#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#define NULL_ELEMENT    -1

typedef int Element;

typedef struct _node {
    Element elem;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _linked_list {
    int size;
    Node* header;
    Node* trailer;
    int (*func)(Element* elements);
} LinkedList;

typedef LinkedList List;

void listInit(List* list);

void listAdd(List* list, int r, Element e);
Element listDelete(List* list, int r);
Element listGet(List* list, int r);
void listTraverse(List* list);

void listSetTraversalFunction(List* list, int (*func)(Element* elements));

#endif