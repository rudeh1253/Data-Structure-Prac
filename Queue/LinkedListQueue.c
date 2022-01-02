#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedListQueue.h"

void queueInit(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void enqueue(Queue* queue, QElem e) {
    Node* node = (Node*)malloc(sizeof(Node*));
    node->e = e;
    if (qIsEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
        node->next = NULL;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }

    queue->size++;
}

QElem dequeue(Queue* queue) {
    if (qIsEmpty(queue)) {

        return emptyQueueException();
    }

    Node* p = queue->front;
    QElem e = p->e;

    queue->front = queue->front->next;

    free(p);
    queue->size--;

    return e;
}

QElem qFront(Queue* queue) { return queue->front->e; }

bool qIsEmpty(Queue* queue) { return queue->size == 0; }

int qSize(Queue* queue) { return queue->size; }

QElem emptyQueueException() {
    printf("EmptyQueueException\n");

    return EMPTY_QUEUE_EXCEPTION;
}