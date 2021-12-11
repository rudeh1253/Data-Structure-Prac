#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdbool.h>

#define NULL_ELEMENT    NULL

typedef struct _data {
    int exponent;
    int coefficient;
} Data;

typedef Data* Element;

typedef struct _node {
    Element elem;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _linked_list {
    int size;
    Node* header;
    Node* trailer;
    _Bool (*func)(Element elements);
} LinkedList;

typedef LinkedList List;

void listInit(List* list);

void listAdd(List* list, int r, Element e);
Element listDelete(List* list, int r);
Element listGet(List* list, int r);
void listTraverse(List* list);

void listSetTraversalFunction(List* list, _Bool (*func)(Element elements));

#endif