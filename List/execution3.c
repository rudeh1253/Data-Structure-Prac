/*
정렬을 유지하며 LinkedList에 element 삽입 실험
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

_Bool comp(Element e1, Element e2) {
    return e1->data1 < e2->data1;
}

int main() {
    List l; List* list = &l;

    listSetComparator(list, comp);

    srand(time(NULL));
    
    for (int i = 0; i < 20; i++) {
        Element e = (Element)malloc(sizeof(Data));
        e->data1 = rand() % 100;
        listAddByOrder(list, e);
    }

    for (int i = 0; i < 20; i++) {
        listGet(list, i);
    }

    return 0;
}