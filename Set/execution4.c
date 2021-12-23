#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedListSet.h"
#include "SetOperation.h"

typedef int Data;

void printElem(Element e) {
    printf("%d ", *(int*)e);
}

void expressSet(Set* set) {
    listPrintAll(set->list, printElem);
    putchar('\n');
    printf("size: %d\n\n", setSize(set));
}

Set arrToSet(Data arr[], int length) {
    Set set;
    setInit(&set);

    for (int i = 0; i < length; i++) {
        setAdd(&set, &arr[i]);
    }

    return set;
}

int main() {
    /*
    int sizeOfA, sizeOfB;
    scanf("%d", &sizeOfA);
    Data arr1[sizeOfA];
    for (int i = 0; i < sizeOfA; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &sizeOfB);
    Data arr2[sizeOfB];
    for (int i = 0; i < sizeOfB; i++) {
        scanf("%d", &arr2[i]);
    }

    Set s1 = arrToSet(arr1, sizeOfA);
    Set s2 = arrToSet(arr2, sizeOfB);

    if (isSubset(&s1, &s2)) {
        printf("%d\n", 0);
    } else {
        while (setIsMember(&s2, listGet(s1.list))) {
            if (!listToNext(s2.list)) {
                goto out_of;
            }
        }
        printf("%d\n", *(int*)listGet(s1.list));
    }
    out_of:
    */

    int sizeOfA, sizeOfB;
    scanf("%d", &sizeOfA);
    Data arr3[sizeOfA];
    for (int i = 0; i < sizeOfA; i++) {
        scanf("%d", &arr3[i]);
    }
    scanf("%d", &sizeOfB);
    Data arr4[sizeOfB];
    for (int i = 0; i < sizeOfB; i++) {
        scanf("%d", &arr4[i]);
    }

    Set s3 = arrToSet(arr3, sizeOfA);
    Set s4 = arrToSet(arr4, sizeOfB);

    Set sUnion = setUnion(&s3, &s4);
    Set intersect = setIntersect(&s3, &s4);

    setPrintAll(&sUnion, printElem);
    putchar('\n');
    setPrintAll(&intersect, printElem);
    putchar('\n');

    return 0;
}