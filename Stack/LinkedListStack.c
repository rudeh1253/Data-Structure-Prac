#include "LinkedList.h"
#include "LinkedListStack.h"

void sInit(Stack* stack) {
    listInit(stack);
}

void sPush(Stack* stack, SElem e) {
    lAdd(stack, e);
}

SElem sPop(Stack* stack) {

    return lRemove(stack);
}

SElem sPeek(Stack* stack) {

    return lGet(stack);
}

bool sIsEmpty(Stack* stack) {

    return lIsEmpty(stack);
}

int sSize(Stack* stack) {

    return lSize(stack);
}