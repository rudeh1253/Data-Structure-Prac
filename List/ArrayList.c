#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

#define EXTENDED_SIZE 10

#define FORWARD 1
#define BACKWARD 0

Element* getExtendedContainer(List* list);
void extendContainer(List* list);
void shift(List* list, int from, int direction);
void printException(char* exceptionName);

void listInit(List* list) {
    list->size = 0;
    list->fullSize = 10;
    list->container = (Element*)malloc(sizeof(Element) * list->fullSize);
}

Boolean listIsEmpty(List* list) { return list->size == 0; }

int sizeOfList(List* list) { return list->size; }
// iterator listElements();

Element listGet(List* list, int r) {
    if (r < 0 || r > list->size - 1) {
        printException("InvalidRankExcpetion");

        return FALSE;
    }

    return list->container[r];
}

Element listSet(List* list, int r, Element e) {
    if (r < 0 || r > list->size - 1) {
        printException("InvalidRankExcpetion");
 
        return FALSE;
    }

    int returnElement = list->container[r];
    list->container[r] = e;

    return returnElement;
}

void listAdd(List* list, int r, Element e) {
    if (r < 0 || r > list->size) {
        printException("InvalidRankException");

        return;
    }

    if (list->size >= list->fullSize) {
        extendContainer(list);
    }

    shift(list, r, FORWARD);
    list->container[r] = e;
    list->size++;
}

void listAddFirst(List* list, Element e) { listAdd(list, 0, e); }

void listAddLast(List* list, Element e) { listAdd(list, list->size, e); }

Element listRemove(List* list, int r) {
    if (list->size == 0) {
        printException("ListEmptyException");

        return FALSE;
    }

    if (r < 0 || r > list->size - 1) {
        printException("InvalidRankException");

        return FALSE;
    }

    Element e = list->container[r];
    shift(list, r, BACKWARD);
    list->size--;
}

Element listRemoveFirst(List* list) { listRemove(list, 0); }

Element listRemoveLast(List* list) { listRemove(list, list->size - 1); }

void listTraversal(List* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d\t", list->container[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

Element* getExtendedContainer(List* list) {
    Element* newContainer = (Element*)malloc(sizeof(Element) * (list->fullSize + EXTENDED_SIZE));
    for (int i = 0; i < list->size; i++) {
        newContainer[i] = list->container[i];
    }

    return newContainer;
}

void extendContainer(List* list) {
    list->container = getExtendedContainer(list);
    list->fullSize += EXTENDED_SIZE;
}

void shift(List* list, int from, int direction) {
    if (direction == FORWARD) {
        for (int i = list->size - 1; i >= from; i--) {
            list->container[i + 1] = list->container[i];
        }
    } else if (direction == BACKWARD) {
        for (int i = from; i < list->size - 1; i++) {
            list->container[i] = list->container[i + 1];
        }
    } else {
        return;
    }
}

void printException(char* exceptionName) { printf("%s\n", exceptionName); }