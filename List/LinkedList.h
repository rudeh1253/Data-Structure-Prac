#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#define TRUE    1
#define FALSE    0

#define NULL_ELEMENT    -1

typedef int Element;
typedef int Boolean;

typedef struct _node {
    Element elem;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _linked_list {
    int size;
    Node* header;
    Node* trailer;
} LinkedList;

typedef LinkedList List;

void listInit(List* list);

void listAdd(List* list, int r, Element e);
Element listDelete(List* list, int r);
Element listGet(List* list, int r);
void listPrint(List* list);

#endif