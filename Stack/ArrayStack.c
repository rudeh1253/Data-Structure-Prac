#include <stdlib.h>
#include "ArrayStack.h"

#define INIT_SIZE    30
#define INCREMENTAL_SIZE    10

void cpyArr(SElem* from, SElem* to, int length);

typedef SElem ExceptionIdentification;
ExceptionIdentification emptyStackException();
ExceptionIdentification fullStackException();

void sInit(Stack* stack) {
    stack->container = (SElem*)malloc(sizeof(SElem) * INIT_SIZE);
    stack->top = -1;
    stack->maxSize = INIT_SIZE;
}

SElem sPush(Stack* stack, SElem e) {
    if (stack->top >= stack->maxSize - 1) {

        return fullStackException();
    }

    stack->container[++stack->top] = e;

    return NULL_ELEM;
}

SElem sPop(Stack* stack) {
    if (sIsEmpty(stack)) {

        return emptyStackException();
    }

    return stack->container[stack->top--];
}

/* Secondary ADT Method */
SElem sPeek(Stack* stack) {
    if (stack->top <= -1) {

        return emptyStackException();
    }

    return stack->container[stack->top];
}

int sSize(Stack* stack) {

    return stack->top + 1;
}
bool sIsEmpty(Stack* stack) {
    
    return stack->top <= -1;
}

/* Exception */
ExceptionIdentification emptyStackException() {
    
    return EMPTY_STACK_EXCEPTION;
}

ExceptionIdentification fullStackException() {

    return FULL_STACK_EXCEPTION;
}

/* support */
void increaseSize(Stack* stack) {
    stack->maxSize += INCREMENTAL_SIZE;
    SElem* newContainer = (SElem*)malloc(sizeof(SElem) * stack->maxSize);
    cpyArr(stack->container, newContainer, stack->top + 1);
    free(stack->container);
    stack->container = newContainer;
}

void cpyArr(SElem* from, SElem* to, int length) {
    for (int i = 0; i < length; i++) {
        to[i] = from[i];
    }
}