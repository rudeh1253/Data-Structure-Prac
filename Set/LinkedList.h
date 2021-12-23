#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdbool.h>

#define NULL_ELEM    NULL

typedef void* Element;

typedef struct _node {
    Element elem;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _linked_list {
    int size;
    Node* header;
    Node* trailer;
    _Bool (*traversalFunc)(Element elements);
    _Bool (*comparator)(Element element1, Element element2);
    Node* cur;
} LinkedList;

typedef LinkedList List;

void listInit(List* list);

_Bool listIsEmpty(List* list);

_Bool listToFirst(List* list);
_Bool listToNext(List* list);

void listAdd(List* list, int r, Element e);
void listAddFirst(List* list, Element e);
void listAddLast(List* list, Element e);
void listAddByOrder(List* list, Element e);

Element listDelete(List* list);
Element listDeleteAt(List* list, int r);
Element listDeleteFirst(List* list);
Element listDeleteLast(List* list);

Element listGet(List* list);
Element listGetAt(List* list, int r);
void listTraverse(List* list);

void listDestroy(List* list);

void listSetTraversalFunction(List* list, _Bool (*func)(Element elements));
void listSetComparator(List* list, _Bool (*comparator)(Element element1, Element element2));

void listPrintAll(List* list, void (*printFunc)(Element e));

#endif