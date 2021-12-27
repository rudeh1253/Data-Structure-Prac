#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

/* Singly linked list ADT */

#include <stdbool.h>

typedef int Elem;

typedef struct _node {
    struct _node* next;
    Elem elem;
} Node;

typedef struct _linked_list {
    Node* top;
    int size;
} LinkedList;

typedef LinkedList List;

void listInit(List* list);

void lAdd(List* list, Elem e);
Elem lRemove(List* list);

Elem lGet(List* list);
bool lIsEmpty(List* list);
int lSize(List* list);

#endif