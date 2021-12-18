#include <stdio.h>
#include <stdlib.h>
#include "LinkedListSet.h"

int main() {
    Set s1, s2, s3;
    setInit(&s1);
    setInit(&s2);
    setInit(&s3);

    int intArr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arrLen1 = sizeof(intArr1) / sizeof(int);
    void** arr1 = (void**)malloc(arrLen1 * sizeof(void*));
    
    for (int i = 0; i < arrLen1; i++) {
        arr1[i] = malloc(sizeof(void*));
        arr1[i] = &intArr1[i];
    }
    
    for (int i = 0; i < arrLen1; i++) {
        setAdd(&s1, arr1[i]);
        printf("%d ", *(int*)arr1[i]);
    } printf("\n");

    for (int i = 0; i < 5; i++) {
        setAdd(&s2, arr1[i]);
        printf("%d ", *(int*)arr1[i]);
    } printf("\n");

    int intArr2[] = { 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19 };
    int arrLen2 = sizeof(intArr2) / sizeof(int);
    void** arr2 = (void**)malloc(arrLen2 * sizeof(void*));

    for (int i = 0; i < arrLen2; i++) {
        arr2[i] = malloc(sizeof(void*));
        arr2[i] = &intArr2[i];
    }

    for (int i = 0; i < arrLen2; i++) {
        setAdd(&s3, arr2[i]);
        printf("%d ", *(int*)arr2[i]);
    } printf("\n");

    printf("size of s1: %d\nsize of s2: %d\n", setSize(&s1), setSize(&s2));

    int num = 10;
    void* pNumTen = (void*)&num;

    if (setIsMember(&s1, pNumTen)) {
        printf("s1 has 10\n");
    } else {
        printf("s1 doesn't have 10\n");
    }

    num = 20;

    if (setIsMember(&s1, pNumTen)) {
        printf("s1 has 20\n");
    } else {
        printf("s1 doesn't have 20\n");
    }

    if (isSubset(&s1, &s2)) {
        printf("s1 is a subset of s2\n");
    } else if (isSubset(&s2, &s1)) {
        printf("s2 is a subset of s1\n");
    } else {
        printf("nothing1\n");
    }

    if (isSubset(&s1, &s3)) {
        printf("s1 is not a subset of s2\n");
    } else if (isSubset(&s3, &s1)) {
        printf("s3 is not a subset of s1");
    } else {
        printf("nothing2\n");
    }

    return 0;
}