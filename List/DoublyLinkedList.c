#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* getNode(Node* prevNode, Node* nextNode, Element e);

void listInit(List* list) {
    list->size = 0;
    list->header = getNode(NULL, NULL, NULL_ELEMENT);
    list->trailer = getNode(NULL, NULL, NULL_ELEMENT);
    list->header->next = list->trailer;
    list->trailer->prev = list->header;
    list->func = NULL;
}

void listAdd(List* list, int r, Element e) {
    if (r < 0 || r > list->size) {
        printf("invalid position\n");

        return;
    }

    Node* p = list->header;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }

/*
    Node* newNode = getNode(p->prev, p, e);
    p->next->prev = newNode;
    p->next = newNode;*/
    Node* newNode = getNode(p, p->next, e);
    p->next->prev = newNode;
    p->next = newNode;

    list->size++;
}

Element listDelete(List* list, int r) {
    if (r < 0 || r >= list->size) {
        printf("invalid position\n");

        return NULL_ELEMENT;
    }

    Node* p = list->header->next;
    if (p == list->trailer) {
        printf("List is empty\n");

        return NULL_ELEMENT;
    }

    for (int i = 0; i < r; i++) {
        p = p->next;
    }

    Node* deletedNode = p;
    Element elem = p->elem;

    deletedNode->prev->next = deletedNode->next;
    deletedNode->next->prev = deletedNode->prev;
    free(deletedNode);

    list->size--;

    return elem;
}

Element listGet(List* list, int r) {
    if (r < 0 || r >= list->size) {
        printf("invalid position\n");

        return NULL_ELEMENT;
    }

    Node* p = list->header->next;
    if (p == list->trailer) {
        printf("List is empty\n");

        return NULL_ELEMENT;
    }

    for (int i = 0; i < r; i++) {
        p = p->next;
    }

    return p->elem;
}

void listTraverse(List* list) {
    Node* p = list->header;

    if (list->func == NULL) {
        for (int i = 0; i < list->size; i++) {
            p = p->next;
            printf("%p ", p->elem);
        } printf("\n");
    } else {
        for (int i = 0; i < list->size; i++) {
            p = p->next;
            if (!list->func(p->elem)) {
                break;
            }
        } printf("\n");
    }
}

void listDestroy(List* list) {
    for (int i = 0; i < list->size; i++) {
        listDelete(list, i);
    }
    if (list->header != NULL) {
        free(list->header);
    }
    if (list->trailer != NULL) {
        free(list->trailer);
    }
}

void listSetTraversalFunction(List* list, _Bool (*func)(Element elements)) {
    list->func = func;
}

Node* getNode(Node* prevNode, Node* nextNode, Element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = prevNode;
    node->next = nextNode;
    node->elem = e;
}