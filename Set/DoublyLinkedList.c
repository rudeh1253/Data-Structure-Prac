#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* getNode(Node* prevNode, Node* nextNode, Element e);
//void linkNode(List* list, Node* front, Node* back);
_Bool compare(Element e1, Element e2);

void listInit(List* list) {
    list->size = 0;
    list->header = getNode(NULL, NULL, NULL_ELEM);
    list->trailer = getNode(NULL, NULL, NULL_ELEM);
    list->header->next = list->trailer;
    list->trailer->prev = list->header;
    list->cur = list->header;
    list->func = NULL;
    list->comparator = compare;
}

_Bool compare(Element e1, Element e2) {

    return *((int*)e1) < *((int*)e2);
}

_Bool listIsEmpty(List* list) {

    return list->size == 0;
}

_Bool listToFirst(List* list) {
    if (list->header->next == list->trailer) {
        
        return false;
    }

    list->cur = list->header->next;

    return true;
}

_Bool listToNext(List* list) {
    if (list->cur->next == list->trailer) {
        
        return false;
    }

    list->cur = list->cur->next;

    return true;
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

    Node* newNode = getNode(p, p->next, e);
    //linkNode(list, p, newNode);
    list->size++;
}

void listAddByOrder(List* list, Element e) {
    Node* p = list->header->next;
    while (p != list->trailer && list->comparator(p->elem, e)) {
        p = p->next;
    }

    Node* newNode = getNode(p->prev, p, e);
    //linkNode(list, newNode, p);
    list->size++;
}

//void linkNode(List* list, Node* front, Node* back) {
    /*
    Node* newNode = getNode(p->prev, p, e);
    p->next->prev = newNode;
    p->next = newNode;*/
//}

Node* getNode(Node* prevNode, Node* nextNode, Element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = prevNode;
    node->next = nextNode;
    if (prevNode != NULL) {
        prevNode->next = node;
    }
    if (nextNode != NULL) {
        nextNode->prev = node;
    }
    node->elem = e;
}

void listAddFirst(List* list, Element e) {
    listAdd(list, 0, e);
}

void listAddLast(List* list, Element e) {
    listAdd(list, list->size, e);
}

Element listDelete(List* list) {
    if (list->size == 0) {
        
        return NULL;
    }

    Element re = list->cur->elem;

    list->cur->next->prev = list->cur->prev;
    list->cur->prev->next = list->cur->next;
    free(list->cur);

    return re;
}

Element listDeleteAt(List* list, int r) {
    if (r < 0 || r >= list->size) {
        printf("invalid position\n");

        return NULL_ELEM;
    }

    Node* p = list->header->next;
    if (p == list->trailer) {
        printf("List is empty\n");

        return NULL_ELEM;
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

Element listDeleteFirst(List* list) {
    // TODO
}

Element listDeleteLast(List* list) {
    // TODO
}

Element listGet(List* list) {
    if (list->size == 0) {

        return NULL;
    }

    return list->cur->elem;
}

Element listGetAt(List* list, int r) {
    if (r < 0 || r >= list->size) {
        printf("invalid position\n");

        return NULL_ELEM;
    }

    Node* p = list->header->next;
    if (p == list->trailer) {
        printf("List is empty\n");

        return NULL_ELEM;
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
        listDeleteAt(list, i);
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

void listSetComparator(List* list, _Bool (*comparator)(Element element1, Element element2)) {
    list->comparator = comparator;
}