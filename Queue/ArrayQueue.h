#ifndef __ARRAY_QUEUE_H_
#define __ARRAY_QUEUE_H_

#include <stdbool.h>

#define MAX_LEN    100
#define EMPTY_QUEUE_EXCEPTION    -134135

typedef int QElem;

typedef struct _array_queue {
    QElem queue[MAX_LEN];
    int f, r;    
} ArrayQueue;

typedef ArrayQueue Queue;

void queueInit(Queue* queue);

bool enqueue(Queue* queue, QElem e);
QElem dequeue(Queue* queue);

QElem qFront(Queue* queue);
bool qIsEmpty(Queue* queue);
bool qIsFull(Queue* queue);
int qSize(Queue* queue);

bool fullQueueException();
QElem emptyQueueException();

#endif