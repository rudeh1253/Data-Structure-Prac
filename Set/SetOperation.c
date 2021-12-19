#include <stdlib.h>
#include <stdio.h>
#include "SetOperation.h"
#include "LinkedListSet.h"
#include "LinkedList.h"

int count = 0;

void setUnionImpl(Set* sUnion, Set* setA, Set* setB);

Set setUnion(Set* setA, Set* setB) {
    Set sUnion;
    setInit(&sUnion);
    
    setA->list->cur = setA->list->header;
    setB->list->cur = setB->list->header;

    setUnionImpl(&sUnion, setA, setB);

    return sUnion;
}

void setUnionImpl(Set* sUnion, Set* setA, Set* setB) {
    /*
    if (setA->list->cur->next == setA->list->trailer
        && setB->list->cur->next == setB->list->trailer) {

            return;
    }*/

    if (setA->list->cur->next == setA->list->trailer) {
        if (listToNext(setB->list)) {
            printf("if1 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setB->list));
            setUnionImpl(sUnion, setA, setB);
        } else {
            printf("if2 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));

            return;
        }
    } else if (setB->list->cur->next == setB->list->trailer) {
        if (listToNext(setA->list)) {
            printf("if3 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            setUnionImpl(sUnion, setA, setB);
        } else {
            printf("if4 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setB->list));

            return;
        }
    } else {
        if (setA->list->cur == setA->list->header || setB->list->cur == setB->list->header) {
            printf("if5 - %d\n", ++count);
            setA->list->cur = setA->list->header->next;
            setB->list->cur = setB->list->header->next;
        }

        if (setA->list->comparator(listGet(setA->list), listGet(setB->list))) {
            printf("if6 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            listToNext(setA->list);
            setUnionImpl(sUnion, setA, setB);
        } else {
            printf("if7 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setB->list));
            listToNext(setB->list);
            setUnionImpl(sUnion, setA, setB);
        }
    }
}

Set setIntersect(Set* setA, Set* setB) {
     
}

Set setSubtract(Set* setA, Set* setB) {

}