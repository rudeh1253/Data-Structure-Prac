#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

Node* getNode(Node* prevNode, Node* nextNode, Element e);

void listInit(List* list) {
    list->size = 0;
    list->header = getNode(NULL, NULL, NULL_ELEMENT);
    list->trailer = getNode(NULL, NULL, NULL_ELEMENT);
    list->header->next = list->trailer;
    list->trailer->prev = list->header;
}

void listAdd(List* list, int r, Element e) {
    if (r < 1 || r > list->size + 1) {
        printf("invalid position\n");

        return;
    }

    Node* p = list->header;
    for (int i = 0; i < r - 1; i++) {
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
    if (r < 1 || r > list->size) {
        printf("invalid position\n");

        return NULL_ELEMENT;
    }

    Node* p = list->header;
    for (int i = 0; i < r - 1; i++) {
        p = p->next;
    }

    Node* deletedNode = p;
    deletedNode->prev->next = deletedNode->next;
    deletedNode->next->prev = deletedNode->prev;
    free(deletedNode);

    list->size--;

    return deletedNode->elem;
}

Element listGet(List* list, int r) {
    if (r < 1 || r > list->size) {
        printf("invalid position\n");

        return NULL_ELEMENT;
    }

    Node* p = list->header;
    for (int i = 0; i < r - 1; i++) {
        p = p->next;
    }

    return p->elem;
}

void listPrint(List* list) {
    Node* p = list->header;

    for (int i = 0; i < list->size; i++) {
        p = p->next;
        printf("%d ", p->elem);
    } printf("\n");
}

Node* getNode(Node* prevNode, Node* nextNode, Element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = prevNode;
    node->next = nextNode;
    node->elem = e;
}