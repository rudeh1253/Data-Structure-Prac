#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
typedef struct _linked_list {
    int size;
    Node* header;
    Node* trailer;
    _Bool (*func)(Element elements);
} LinkedList;
*/

// wouldn't use List.trailer
void listInit(List* list) {
    // initializing list
    list->header = (Node*)malloc(sizeof(Node));
    list->trailer = NULL; // This will not be used
    list->func = NULL;
    list->size = 0;

    // initializing header
    list->header->prev = NULL;
    list->header->next = list->header;
    list->header->elem = NULL_ELEM;
}

void listAdd(List* list, int r, Element e) {
    if (r < 0 || r > list->size) {
        printf("invaild position\n");

        return;
    }

    // Searching position
    Node* p = list->header;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }

    // Allocating and initializing a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = e;
    newNode->next = p->next;
    newNode->prev = p;

    p->next->prev = newNode;
    p->next = newNode;

    list->size++;
}

Element listDelete(List* list, int r) {
    if (r < 0 || r > list->size - 1) {
        printf("invaild position\n");

        return NULL_ELEM;
    }

    if (list->size == 0) {
        printf("List is empty\n");

        return NULL_ELEM;
    }

    Node* p = list->header->next;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }

    p->next->prev = p->prev;
    p->prev->next = p->next;

    Element returnElem = p->elem;
    free(p);
    
    list->size--;

    return returnElem;
}

Element listGet(List* list, int r) {
    if (r < 0 || r > list->size - 1) {
        printf("invaild position\n");

        return NULL_ELEM;
    }

    if (list->size == 0) {
        printf("List is empty\n");

        return NULL_ELEM;
    }

    Node* p = list->header->next;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }

    return p->elem;
}

void listPrintAll(List* list) {
    if (list->size == 0) {
        printf("List is empty\n");

        return;
    }

    Node* p = list->header;
    for (int i = 0; i < list->size; i++) {
        p = p->next;
        printf("%c ", p->elem->data1);
    } printf("\n");
}