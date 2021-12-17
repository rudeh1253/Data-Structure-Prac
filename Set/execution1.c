#include <stdio.h>
#include <stdlib.h>
#include "LinkedListSet.h"

int main() {
    Set s1, s2, s3;
    setInit(&s1);
    setInit(&s2);
    setInit(&s3);

    int intArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    void** arr = (void**)malloc(sizeof(intArr) * sizeof(void*));
    int arrLen = sizeof(intArr) / sizeof(int);
    for (int i = 0; i < arrLen; i++) {
        arr[i] = malloc(sizeof(void*));
        arr[i] = &intArr[i];
    }
    
    for (int i = 0; i < arrLen; i++) {
        setAdd(&s1, arr[i]);
        printf("%d ", *(int*)arr[i]);
    } printf("\n");

    for (int i = 0; i < 5; i++) {
        setAdd(&s2, arr[i]);
        printf("%d ", *(int*)arr[i]);
    } printf("\n");

    printf("size of s1: %d\nsize of s2: %d\n", setSize(&s1), setSize(&s2));

    int numTen = 10;
    void* pNumTen = (void*)&numTen;

    if (setIsMember(&s1, pNumTen)) {
        printf("s1 has 10\n");
    } else {
        printf("s1 doesn't have 10\n");
    }

    if (isSubset(&s1, &s2)) {
        printf("s1 is not a subset of s2\n");
    } else if (isSubset(&s2, &s1)) {
        printf("s2 is a subset of s2\n");
    }

    return 0;
}