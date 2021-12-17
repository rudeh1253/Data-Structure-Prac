#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "LinkedListSet.h"

_Bool setListDefaultComparator(SetElem e1, SetElem e2);
_Bool setDefaultEqualityComparator(SetElem e1, SetElem e2);

void setInit(Set* set) {
    set->list = (List*)malloc(sizeof(List));
    listInit(set->list);
    listSetComparator(set->list, setListDefaultComparator);
    set->equalityComparator = setDefaultEqualityComparator;
}

_Bool setDefaultEqualityComparator(SetElem e1, SetElem e2) {

    return *((int*)e1) == *((int*)e2);
}

_Bool setListDefaultComparator(SetElem e1, SetElem e2) {
    int* a = (int*)e1;
    int* b = (int*)e2;

    return *a < *b;
}

int setSize(Set* set) {

    return set->list->size;
}

_Bool setIsEmpty(Set* set) {

    return set->list->size == 0;
}

_Bool setIsMember(Set* set, SetElem e) {
    if (!listToFirst(set->list)) {
        printf("set is empty\n");

        return false;
    }

    if (set->equalityComparator(listGet(set->list), e)) {

        return true;
    }

    while (listToNext(set->list)) {
        if (set->equalityComparator(listGet(set->list), e)) {

            return true;
        }
    }

    return false;
}

_Bool isSubset(Set* setA, Set* setB) {
    if (!listToFirst(setB->list)) {
        if (!listToFirst(setA->list)) {

            return true;
        } else {

            return false;
        }
    } else {
        if (!listToFirst(setA->list)) {

            return true;
        } else if (!setIsMember(setB, listGet(setA->list))) {

            return false;
        }
    }

    while (listToNext(setA->list)) {
        if (!setIsMember(setB, listGet(setA->list))) {
            
            return false;
        }
    }

    return true;
}

void setAdd(Set* set, SetElem e) {
    if (setIsMember(set, e)) { return; }

    listAddByOrder(set->list, e);
}

SetElem setRemove(Set* set, SetElem e) {
    if (!listToFirst(set->list)) {
        // if DoublyLinkedList.listToFirst is modified, it should be modified here too.
        printf("set is empty\n");

        return NULL;
    }

    if (set->equalityComparator(listGet(set->list), e)) {
        listDelete(set->list);
    }

    while (listToNext(set->list)) {
        if (set->equalityComparator(listGet(set->list), e)) {

            return listDelete(set->list);
        }
    }

    printf("No such element\n");

    return NULL;
}

void emptySetException();

void setEqualityComparator(Set* set, _Bool (*equalityComparator)(SetElem e1, SetElem e2)) {
    set->equalityComparator = equalityComparator;
}