#include <stdbool.h>
#include "LinkedListSet.h"

_Bool setDefaultComparator(Element e1, Element e2) {
    int* a = (int*)e1;
    int* b = (int*)e2;

    return *a < *b;
}

void setInit(Set* set) {
    listInit(set);
    listSetComparator(set, setDefaultComparator);
}

int setSize(Set* set) {

    return set->size;
}

_Bool setIsEmpty(Set* set) {

    return set->size == 0;
}

_Bool setIsMember(Set* set, SetElem e) {
    Node* p = set->header;

    while (p = p->next != set->trailer) {
        if (p->elem == e) {

            return true;
        }
    }

    return false;
}

_Bool isSubset(Set* setA, Set* setB) {
    Node* pa = setA->header;
    Node* pb = setB->header;

    while (true) {
        pa = pa->next;
        if (pa == setA->trailer) {
            break;
        }

        while (pb = pb->next != setB->trailer) {
            if (pa->elem == pb->elem) {
                break;
            } else {

                return false;
            }
        }
        pb = setB->header;
    }
}

void setAdd(Set* set, SetElem e) {
    listAddByOrder(set, e);
}

SetElem setRemove(Set* set, SetElem e) {
    if (!listToFirst(set)) {
        printf("cannot remove set element\n");

        return false;
    }

    Element pe;

    if (pe = listGet(set) == pe) {

        return pe;
    }

    while (listToNext(set)) {
        if (listGet(set == e)) {
            
        }
    }
}

void emptySetException();   