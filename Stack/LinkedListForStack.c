#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void listInit(List* list) {
    list->top = (Node*)malloc(sizeof(Node));
    list->top->next = NULL;
    list->size = 0;
}

void lAdd(List* list, Elem e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = e;

    newNode->next = list->top->next;
    list->top->next = newNode;
    
    list->size++;
}

Elem lRemove(List* list) {
    if (lIsEmpty(list)) {
        
        return -1;
    }

    Node* dNode = list->top->next;
    Elem re = dNode->elem;

    list->top->next = dNode->next;
    free(dNode);
    list->size--;

    return re;
}

Elem lGet(List* list) {
    if (lIsEmpty(list)) {

        return -1;
    }

    return list->top->next->elem;
}

bool lIsEmpty(List* list) {
    
    return list->size == 0;
}

int lSize(List* list) {

    return list->size;
}