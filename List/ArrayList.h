#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int Element;
typedef int Boolean;

typedef struct _array_list {
    Element* container;
    int size;
    int fullSize;
} ArrayList;

typedef ArrayList List;

void listInit(List* list);

Boolean listIsEmpty(List* list);
int sizeOfList(List* list);
// iterator listElements();

Element listGet(List* list, int r);

Element listSet(List* list, int r, Element e);
void listAdd(List* list, int r, Element e);
void listAddFirst(List* list, Element e);
void listAddLast(List* list, Element e);

Element listRemove(List* list, int r);
Element listRemoveFirst(List* list);
Element listRemoveLast(List* list);

void listTraversal(List* list);

#endif