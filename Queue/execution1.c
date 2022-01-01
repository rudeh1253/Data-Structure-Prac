#include <stdio.h>
#include "ArrayQueue.h"

int main() {
    Queue q;
    queueInit(&q);

    int n; scanf("%d", &n);
    int input;
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        enqueue(&q, input);
    }
    for (int i = 0; i < qSize(&q); i++) {
        printf("%d  ", dequeue(&q));
    } printf("\n");

    return 0;
}