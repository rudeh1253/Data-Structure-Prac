#ifndef __LINKED_LIST_QUEUE_H_
#define __LINKED_LIST_QUEUE_H_

#include <stdbool.h>

#define EMPTY_QUEUE_EXCEPTION    -13513

typedef int QElem;

typedef struct _node {
    QElem e;
    struct _node* next;
} Node;

typedef struct _linked_list_queue {
    Node* front;
    Node* rear;
    int size;
} LinkedListQueue;

typedef LinkedListQueue Queue;

void queueInit(Queue* queue);

void enqueue(Queue* queue, QElem e);
QElem dequeue(Queue* queue);

QElem qFront(Queue* queue);
bool qIsEmpty(Queue* queue);
int qSize(Queue* queue);

QElem emptyQueueException();

#endif