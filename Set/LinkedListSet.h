#ifndef __LINKED_LIST_SET_H_
#define __LINKED_LIST_SET_H_

#include <stdbool.h>
#include "LinkedList.h"

typedef Element SetElem;

typedef struct _linked_list_set {
    List* list;
    _Bool (*equalityComparator)(SetElem e1, SetElem e2);
} LinkedListSet;

typedef LinkedListSet Set;

void setInit(Set* set);

int setSize(Set* set);
_Bool setIsEmpty(Set* set);
// iterator elemtents()

_Bool setIsMember(Set* set, SetElem e);
_Bool isSubset(Set* subset, Set* superset);

void setAdd(Set* set, SetElem e);
SetElem setRemove(Set* set, SetElem e);

void emptySetException();

void setEqualityComparator(Set* set, _Bool (*equalityComparator)(SetElem e1, SetElem e2));

void setPrintAll(Set* set, void (*method)(Element e));

#endif