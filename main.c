#include <stdio.h>
#include "./List/LinkedList.h"

int main() {
    int rank, executeNum, element;
    List list; List* l = &list;
    listInit(l);

    for (int i = 0; i < 100; i++) {
        listAdd(l, 1, (i + 1) * 2);
    }
    listPrint(l);

    for (int i = 1; i <= 50; i++) {
        listDelete(l, i * 2);
    }
    listPrint(l);
    printf("\n");

    Element j;
    int i = 1;
    do {
        j = listGet(l, i++);
    } while (j != NULL_ELEMENT);
    printf("\n");

    return 0;
}