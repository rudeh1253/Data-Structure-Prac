#ifndef __LINKED_LIST_SET_H_
#define __LINKED_LIST_SET_H_

#include <stdbool.h>
#include "../List/LinkedList.h"

typedef void* SetElem;

typedef List Set;

int setSize(Set* set);
_Bool setIsEmpty(Set* set);
// iterator elemtents()

_Bool setIsMember(Set* set, SetElem e);
_Bool isSubset(Set* setA, Set* setB);

void setAdd(Set* set, SetElem e);
SetElem setRemove(Set* set, SetElem e);

void emptySetException();   

#endif