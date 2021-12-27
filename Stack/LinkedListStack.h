#ifndef __LINKED_LIST_STACK_H_
#define __LINKED_LIST_STACK_H_

#include <stdbool.h>
#include "LinkedList.h"

typedef Elem SElem;

typedef List Stack;

void sInit(Stack* stack);

void sPush(Stack* stack, SElem e);
SElem sPop(Stack* stack);

SElem sPeek(Stack* stack);
bool sIsEmpty(Stack* stack);
int sSize(Stack* stack);

#endif