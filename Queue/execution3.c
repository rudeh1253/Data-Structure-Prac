#include <stdio.h>
#include <stdbool.h>
#include "Deque.h"

int main() {
    struct deque d;
    dequeInit(&d);

    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int n2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &n2);
        dAddLast(&d, n2);
    }

    while (true) {
        printf("What kind of task: ");
        scanf("%d", &n);

        if (n == 0) { break; }

        switch (n) {
        case 1:
            printf("Enter number: ");
            scanf("%d", &n);
            dAddFront(&d, n);
            break;
        case 2:
            printf("Enter number:");
            scanf("%d", &n);
            dAddLast(&d, n);
            break;
        case 3:
            dRemoveFirst(&d);
            break;
        case 4:
            dRemoveLast(&d);
            break;
        }

        printAll(&d);
        printf("\n");
    }

    return 0;
}