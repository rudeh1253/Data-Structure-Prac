#include <stdio.h>
#include "ArrayQueue.h"

void queueInit(Queue* queue) {
    queue->f = 0;
    queue->r = MAX_LEN - 1;
}

bool enqueue(Queue* queue, QElem e) {
    if (qIsFull(queue)) {

        return fullQueueException();
    }

    queue->r = (queue->r + 1) % MAX_LEN;
    queue->queue[queue->r] = e;

    return true;
}

QElem dequeue(Queue* queue) {
    if (qIsEmpty(queue)) {
        
        return emptyQueueException();
    }

    QElem e = queue->queue[queue->f];

    queue->f = (queue->f + 1) % MAX_LEN;

    return e;
}

QElem qFront(Queue* queue) {
    if (qIsEmpty(queue)) {
        
        return emptyQueueException();
    }

    return queue->queue[queue->f];
}

bool qIsEmpty(Queue* queue) {
    
    return (queue->r + 1) % MAX_LEN == queue->f;
}

bool qIsFull(Queue* queue) {

    return (queue->r + 2) % MAX_LEN == queue->f;
}

int qSize(Queue* queue) {
    
    return (queue->f - queue->r + MAX_LEN - 1) % MAX_LEN;
}

bool fullQueueException() {
    printf("FullQueueException\n");

    return false;
}

QElem emptyQueueException() {
    printf("emptyQueueExcpetion\n");

    return EMPTY_QUEUE_EXCEPTION;
}