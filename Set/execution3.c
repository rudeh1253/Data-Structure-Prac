#include <stdio.h>
#include <stdlib.h>
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
    void** pArr = (void**)malloc(length * sizeof(void*));

    for (int i = 0; i < length; i++) {
        pArr[i] = &arr[i];
    }

    Set set;
    setInit(&set);

    for (int i = 0; i < length; i++) {
        setAdd(&set, pArr[i]);
    }

    free(pArr);

    return set;
}

int main() {
    Data intArr1[] = { 3, 5, 6, 7, 1, 8, 2, 4, 9 };
    Data intArr2[] = { 7, 9, 5, 12, 6, 13, 10, 11, 8 };

    Set s1 = arrToSet(intArr1, sizeof(intArr1) / sizeof(intArr1[0]));
    Set s2 = arrToSet(intArr2, sizeof(intArr2) / sizeof(intArr2[0]));
    expressSet(&s1); expressSet(&s2);

    Set subt1 = setSubtract(&s1, &s2);
    expressSet(&subt1);

    Set intersect1 = setIntersect(&s1, &s2);
    expressSet(&intersect1);

    Data intArr3[] = { 14, 5, 22, 9, 1, 23, 55, 33, 3, 5, 6, 7, 27, 1, 8, 2, 4, 9 };
    Data intArr4[] = { 7, 45, 61, 22, 55, 9, 36, 26, 27, 9, 5, 12, 6, 13, 10, 11, 8 };

    Set s3 = arrToSet(intArr3, sizeof(intArr3) / sizeof(intArr3[0]));
    Set s4 = arrToSet(intArr4, sizeof(intArr4) / sizeof(intArr4[0]));
    expressSet(&s3); expressSet(&s4);

    Set subt2 = setSubtract(&s3, &s4);
    expressSet(&subt2);

    Set intersect2 = setIntersect(&s3, &s4);
    expressSet(&intersect2);

    Data intArr5[] = { 67, 28, 42, 14, 21, 66, 51, 46 };
    Data intArr6[] = { 2, 34, 35, 17, 69, 42, 18 };

    Set s5 = arrToSet(intArr5, sizeof(intArr5) / sizeof(intArr5[0]));
    Set s6 = arrToSet(intArr6, sizeof(intArr6) / sizeof(intArr6[0]));
    expressSet(&s5); expressSet(&s6);

    Set subt3 = setSubtract(&subt1, &s5);
    Set intersect3 = setIntersect(&intersect2, &s6);
    expressSet(&subt3); expressSet(&intersect3);

    return 0;
}