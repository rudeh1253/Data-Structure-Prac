#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdbool.h>

#define EMPTY_DEQUE_EXCEPTION    -1341;

typedef int DElem;

struct node {
    DElem e;
    struct node* next;
    struct node* prev;
};

struct deque {
    struct node* head;
    struct node* tail;
    int size;
};

void dequeInit(struct deque* d);

void dAddFront(struct deque* d, DElem e);
void dAddLast(struct deque* d, DElem e);
DElem dRemoveFirst(struct deque* d);
DElem dRemoveLast(struct deque* d);

bool dIsEmpty(struct deque* d);
int dSize(struct deque* d);

void printAll(struct deque* d);

#endif