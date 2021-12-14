#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./List/LinkedList.h"

_Bool func(Element elements) {
    printf("%d ", elements->data2);

    return true;
}

int main() {
    int rank, executeNum, element;
    List list; List* l = &list;
    listInit(l);
    listSetTraversalFunction(l, func);

    for (int i = 0; i < 100; i++) {
        Element e = (Element)malloc(sizeof(Data));
        e->data2 = (i + 1) * 2;
        listAdd(l, 0, e);
    }
    listTraverse(l);

    Element e;
    for (int i = 0; i < 50; i++) {
        e = listDelete(l, i * 2);
        if (e != NULL) {
            free(e);
        }
    }
    listTraverse(l);
    printf("\n");

    Element j;
    int i = 0;
    while ((j = listGet(l, i++)) != NULL_ELEM) {
        printf("%d ", j->data2);
    }
    printf("\n");

    return 0;
}