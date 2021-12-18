#include <stdlib.h>
#include "SetOperation.h"
#include "LinkedListSet.h"
#include "LinkedList.h"

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
    if (setA->list->cur->next == setA->list->trailer
        && setB->list->cur->next == setB->list->trailer) {

            return;
    }

    if (setIsEmpty(setA)) {
        if (listToNext(setB->list)) {
            setAdd(sUnion, listGet(setB->list));
            setUnionImpl(sUnion, setA, setB);
        } else {

            return;
        }
    } else if (setIsEmpty(setB)) {
        if (listToNext(setA->list)) {
            setAdd(sUnion, listGet(setA->list));
            setUnionImpl(sUnion, setA, setB);
        } else {

            return;
        }
    } else {
        if (setA->list->comparator(listGet(setA->list), listGet(setB->list))) {
            setAdd(sUnion, listGet(setA->list));
            listToNext(setA->list);
            setUnionImpl(sUnion, setA, setB);
        } else {
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