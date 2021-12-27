#include <stdio.h>
#include "ArrayStack.h"

#define PUSH_ELEM    (i + 1) * 3

int main() {
    Stack stack;
    Stack* s = &stack;
    sInit(s);

    for (int i = 0; i < 35; i++) {
        if (sPush(s, (i + 1) * 20) == FULL_STACK_EXCEPTION) {
            printf("Full stack Exception\n");
        }
    }

    printf("-------------------------\n");

    SElem e;
    while ((e = sPop(s)) != EMPTY_STACK_EXCEPTION) {
        printf("%d  ", e);
    } printf("\n");

    printf("-------------------------\n");

    for (int i = 0; i < 100; i++) {
        if (sPush(s, PUSH_ELEM) == FULL_STACK_EXCEPTION) {
            printf("Full stack exception\n");
            increaseSize(s);
            sPush(s, PUSH_ELEM);
        }
    }

    printf("-------------------------\n");

    printf("size: %d\n", sSize(s));
    printf("peek: %d\n", sPeek(s));

    printf("-------------------------\n");

    while ((e = sPop(s)) != EMPTY_STACK_EXCEPTION) {
        printf("%d  ", e);
    } printf("\n");

    return 0;
}