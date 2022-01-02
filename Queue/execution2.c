#include <stdio.h>
#include "LinkedListQueue.h"

int main() {
    Queue q;
    queueInit(&q);

    for (int i = 10; i < 50; i += 2) {
        enqueue(&q, i);
        printf("%d  ", i);
    } printf("\n");

    QElem e = 0;
    while ((e = dequeue(&q)) != EMPTY_QUEUE_EXCEPTION) {
        printf("%d  ", e);
    } printf("\n");

    return 0;
}