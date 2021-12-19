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
    int intArr1Len = sizeof(intArr1) / sizeof(ArrElem);
    int intArr2Len = sizeof(intArr2) / sizeof(ArrElem);
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

    Set unionSet1 = setUnion(&s1, &s2);

    listPrintAll(unionSet1.list, printElem);
    printf("\n");
    printf("size of union: %d\n", setSize(&unionSet1));

    ArrElem intArr3[] = { 14, 5, 22, 9, 1, 23, 55, 33, 3, 5, 6, 7, 27, 1, 8, 2, 4, 9 };
    ArrElem intArr4[] = { 7, 45, 61, 22, 55, 9, 36, 26, 27, 9, 5, 12, 6, 13, 10, 11, 8 };
    int intArr3Len = sizeof(intArr3) / sizeof(ArrElem);
    int intArr4Len = sizeof(intArr4) / sizeof(ArrElem);
    void** pArr3 = (void**)malloc(intArr3Len * sizeof(void*));
    void** pArr4 = (void**)malloc(intArr4Len * sizeof(void*));

    for (int i = 0; i < intArr3Len; i++) {
        pArr3[i] = malloc(sizeof(ArrElem));
        pArr3[i] = &intArr3[i];
    }

    for (int i = 0; i < intArr4Len; i++) {
        pArr4[i] = malloc(sizeof(ArrElem));
        pArr4[i] = &intArr4[i];
    }

    Set s3, s4;
    setInit(&s3);
    setInit(&s4);

    for (int i = 0; i < intArr3Len; i++) {
        setAdd(&s3, pArr3[i]);
    }

    for (int i = 0; i < intArr4Len; i++) {
        setAdd(&s4, pArr4[i]);
    }

    listPrintAll(s3.list, printElem);
    printf("\n");
    listPrintAll(s4.list, printElem);
    printf("\n");

    Set unionSet2 = setUnion(&s3, &s4);

    listPrintAll(unionSet2.list, printElem);
    printf("\n");
    printf("size of union: %d\n", setSize(&unionSet2));

    return 0;
}