#include <stdlib.h>
#include <stdio.h>
#include "SetOperation.h"
#include "LinkedListSet.h"
#include "LinkedList.h"

int count = 0;

void setUnionImpl(Set* sUnion, Set* setA, Set* setB);
void setIntersectImpl(Set* sIntersect, Set* setA, Set* setB);
void setSubtractImpl(Set* minuend, Set* subtrahend);

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
        if (setB->list->cur->next != setB->list->trailer) {
            //printf("if1 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setB->list));
            listToNext(setB->list);
            setUnionImpl(sUnion, setA, setB);
        } else {
            //printf("if2 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            setAdd(sUnion, listGet(setB->list));

            return;
        }
    } else if (setB->list->cur->next == setB->list->trailer) {
        if (setA->list->cur->next != setA->list->trailer) {
            //printf("if3 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            listToNext(setA->list);
            setUnionImpl(sUnion, setA, setB);
        } else {
            //printf("if4 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            setAdd(sUnion, listGet(setB->list));

            return;
        }
    } else {
        if (setA->list->cur == setA->list->header || setB->list->cur == setB->list->header) {
            //printf("if5 - %d\n", ++count);
            setA->list->cur = setA->list->header->next;
            setB->list->cur = setB->list->header->next;
        }

        if (setA->list->comparator(listGet(setA->list), listGet(setB->list))) {
            //printf("if6 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setA->list));
            listToNext(setA->list);
            setUnionImpl(sUnion, setA, setB);
        } else {
            //printf("if7 - %d - %d, %d\n", ++count, *(int*)listGet(setA->list), *(int*)listGet(setB->list));
            setAdd(sUnion, listGet(setB->list));
            listToNext(setB->list);
            setUnionImpl(sUnion, setA, setB);
        }
    }
}

Set setIntersect(Set* setA, Set* setB) {
    Set sIntersect;
    setInit(&sIntersect);

    setA->list->cur = setA->list->header->next;
    setB->list->cur = setB->list->header->next;

    if (setA->list->cur == setA->list->trailer || setB->list->cur == setB->list->trailer) {

        return sIntersect;
    }

    setIntersectImpl(&sIntersect, setA, setB);

    return sIntersect;
}

void setIntersectImpl(Set* sIntersect, Set* setA, Set* setB) {
    if (setA->list->cur->next == setA->list->trailer) {
        if (setIsMember(setB, listGet(setA->list))) {
            setAdd(sIntersect, listGet(setA->list));
        }

        return;
    } else if (setB->list->cur->next == setB->list->trailer) {
        if (setIsMember(setA, listGet(setB->list))) {
            setAdd(sIntersect, listGet(setB->list));
        }

        return;
    }

    if (setA->equalityComparator(listGet(setA->list), listGet(setB->list))) {
        setAdd(sIntersect, listGet(setA->list));
        listToNext(setA->list);
        listToNext(setB->list);
        setIntersectImpl(sIntersect, setA, setB);
    } else if (setA->list->comparator(listGet(setA->list), listGet(setB->list))) {
        listToNext(setA->list);
        setIntersectImpl(sIntersect, setA, setB);
    } else {
        listToNext(setB->list);
        setIntersectImpl(sIntersect, setA, setB);
    }
}

void setCopy(Set* from, Set* to) {
    listToFirst(to->list);
    if (listToFirst(from->list)) {
        listAddLast(to->list, listGet(from->list));
    }

    while (listToNext(from->list)) {
        listAddLast(to->list, listGet(from->list));
    }
}

Set setSubtract(Set* minuend, Set* subtrahend) {
    Set sSubtracted;
    setInit(&sSubtracted);
    setCopy(minuend, &sSubtracted);

    Set intersect = setIntersect(minuend, subtrahend);

    sSubtracted.list->cur = sSubtracted.list->header->next;
    intersect.list->cur = intersect.list->header->next;

    if (sSubtracted.list->cur == sSubtracted.list->trailer || intersect.list->cur == intersect.list->trailer) {

        return sSubtracted;
    }

    setSubtractImpl(&sSubtracted, &intersect);

    return sSubtracted;
}

void setSubtractImpl(Set* minuend, Set* subtrahend) {
    /*
     * listDelete를 통해 반환받은 void pointer가 가리키는 memory는 stack 영역의 memory일 수 있고
     * heap 영역의 memory일 수 있다. Element가 둘 중에 어떤 것에 해당하는지는 이 모듈을 사용하는 사용자만이 알고 있다.
     * listDelete 메소드를 통해 반환된 값을 그대로 user에게 전달하여 메모리 해제를 사용자에게 인가하는
     * 방법은 구현하기 번거롭고 또 그렇게 할 필요도 없다.
     * 사용자가 정의한 Element 삭제 절차를 입력받는 방법이 가장 적절한 방법이다.
     */
    if (minuend->list->cur->next == minuend->list->trailer) {
        if (setIsMember(subtrahend, listGet(minuend->list))) {
            Element e = listDelete(minuend->list);
        }

        return;
    }

    if (minuend->equalityComparator(listGet(minuend->list), listGet(subtrahend->list))) {
        Element e = listDelete(minuend->list);
        listToNext(minuend->list);
        listToNext(subtrahend->list);
        setSubtractImpl(minuend, subtrahend);
    } else if (minuend->list->comparator(listGet(minuend->list), listGet(subtrahend->list))) {
        listToNext(minuend->list);
        setSubtractImpl(minuend, subtrahend);
    } else {
        listToNext(subtrahend->list);
        setSubtractImpl(minuend, subtrahend);
    }
}