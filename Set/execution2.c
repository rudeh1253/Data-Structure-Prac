#include <stdio.h>
#include <stdlib.h>
#include "SetOperation.h"
#include "LinkedList.h"
#include "LinkedListSet.h"

typedef int ArrElem;

void printElem(Element* e) {
    printf("%d ", *(int*)e);
}

Set setExp(ArrElem intArr1[], ArrElem intArr2[], int intArr1Len, int intArr2Len) {
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
    printf("\n");
    listPrintAll(s2.list, printElem);
    printf("\n");

    Set unionSet = setUnion(&s1, &s2);

    listPrintAll(unionSet.list, printElem);
    printf("\n");
    printf("size of union: %d\n", setSize(&unionSet));

    return unionSet;
}

Set unionSet(Set* s1, Set* s2) {
    Set u = setUnion(s1, s2);
    listPrintAll(u.list, printElem);
    printf("\n");
    printf("size of union: %d\n", setSize(&u));

    return u;
}

int main() {
    ArrElem intArr1[] = { 3, 5, 6, 7, 1, 8, 2, 4, 9 };
    ArrElem intArr2[] = { 7, 9, 5, 12, 6, 13, 10, 11, 8 };
    Set union1 = setExp(intArr1, intArr2, sizeof(intArr1) / sizeof(ArrElem), sizeof(intArr2) / sizeof(ArrElem));

    ArrElem intArr3[] = { 14, 5, 22, 9, 1, 23, 55, 33, 3, 5, 6, 7, 27, 1, 8, 2, 4, 9 };
    ArrElem intArr4[] = { 7, 45, 61, 22, 55, 9, 36, 26, 27, 9, 5, 12, 6, 13, 10, 11, 8 };
    Set union2 = setExp(intArr3, intArr4, sizeof(intArr3) / sizeof(ArrElem), sizeof(intArr4) / sizeof(ArrElem));

    ArrElem intArr5[] = { 67, 28, 42, 14, 21, 66, 51, 46 };
    ArrElem intArr6[] = { 2, 34, 35, 17, 69, 42, 18 };
    Set union3 = setExp(intArr5, intArr6, sizeof(intArr5) / sizeof(ArrElem), sizeof(intArr6) / sizeof(ArrElem));

    unionSet(&union2, &union3);
    printf("\n");

    return 0;
}