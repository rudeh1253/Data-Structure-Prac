#include <stdio.h>
#include "LinkedListStack.h"

#define PUSH_ELEM    (i + 1) * 3

int main() {
    Stack stack;
    Stack* s = &stack;
    sInit(s);

    printf("Push Elements: ");
    for (int i = 0; i < 35; i++) {
        printf("%d  ", (i + 1) * 20);
        sPush(s, (i + 1) * 20);
    } printf("\n");

    printf("-------------------------\n");

    SElem e;
    while ((e = sPop(s)) != -1) {
        printf("%d  ", e);
    } printf("\n");

    printf("-------------------------\n");
    
    printf("Push Elements: ");
    for (int i = 0; i < 100; i++) {
        printf("%d  ", PUSH_ELEM);
        sPush(s, PUSH_ELEM);
    } printf("\n");

    printf("-------------------------\n");

    printf("size: %d\n", sSize(s));
    printf("peek: %d\n", sPeek(s));

    printf("-------------------------\n");

    while ((e = sPop(s)) != -1) {
        printf("%d  ", e);
    } printf("\n");

    return 0;
}