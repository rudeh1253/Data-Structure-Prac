#include <stdio.h>
#include <stdlib.h>
#include "SetOperation.h"
#include "LinkedList.h"
#include "LinkedListSet.h"

typedef int ArrElem;

void printElem(Element* e) {
    printf("%d ", *(int*)e);
}

int main() {
    ArrElem intArr1[] = { 3, 5, 6, 7, 1, 8, 2, 4, 9 };
    ArrElem intArr2[] = { 7, 9, 5, 12, 6, 13, 10, 11, 8 };
    int intArr1Len = sizeof(intArr1) / sizeof(int);
    int intArr2Len = sizeof(intArr2) / sizeof(int);
    void** pArr1 = (void**)malloc(intArr1Len * sizeof(void*));
    void** pArr2 = (void**)malloc(intArr2Len * sizeof(void*));

    for (int i = 0; i < intArr1Len; i++) {
        pArr1[i] = malloc(sizeof(ArrElem));
        pArr1[i] = &intArr1[i];
    }

    for (int i = 0; i < intArr2Len; i++) {
        pArr2[i] = malloc(sizeof(ArrElem));
        pArr2[i] = &intArr2[i];
    }

    Set s1, s2;
    setInit(&s1);
    setInit(&s2);

    for (int i = 0; i < intArr1Len; i++) {
        setAdd(&s1, pArr1[i]);
    }

    for (int i = 0; i < intArr2Len; i++) {
        setAdd(&s2, pArr2[i]);
    }

    listPrintAll(s1.list, printElem);
    listPrintAll(s2.list, printElem);

    return 0;
}