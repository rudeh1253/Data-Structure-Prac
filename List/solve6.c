#include <stdlib.h>
#include "LinkedList.h"

int main() {
    const int OPERATION_COUNT = 18;

    List list;
    listInit(&list);

    Element elem;
    for (int i = 0; i < OPERATION_COUNT - 12; i++) {
        elem = (Element)malloc(sizeof(Data));
        elem->data1 = i + '0';
        listAdd(&list, i, elem);
    }
    listPrintAll(&list);

    int arr[] = { 0, 3, 2 };
    for (int i = 0; i < 3; i++) {
        elem = listDelete(&list, arr[i]);

        if (elem != NULL) { free(elem); }
    }
    listPrintAll(&list);

    for (int i = 0; i < 3; i++) {
        elem = (Element)malloc(sizeof(Data));
        elem->data1 = '9' - i;
        listAdd(&list, 0, elem);
    }
    for (int i = 0; i < 3; i++) {
        elem = listDelete(&list, 5 - i);
        if (elem != NULL) {
            free(elem);
        }
    }
    listPrintAll(&list);

    return 0;
}