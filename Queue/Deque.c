#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void addNodeInCaseOfEmpty(struct deque* d, struct node* p);
DElem emptyDequeException();

void dequeInit(struct deque* d) {
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
}

void dAddFront(struct deque* d, DElem e) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->e = e;

    if (dIsEmpty(d)) {
        addNodeInCaseOfEmpty(d, p);
    } else {
        p->next = d->head;
        d->head->prev = p;
        d->head = p;
    }

    d->size++;
}

void dAddLast(struct deque* d, DElem e) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->e = e;

    if (dIsEmpty(d)) {
        addNodeInCaseOfEmpty(d, p);
    } else {
        p->prev = d->tail;
        d->tail->next = p;
        d->tail = p;
    }

    d->size++;
}

void addNodeInCaseOfEmpty(struct deque* d, struct node* p) {
    d->head = p;
    d->tail = p;

    p->prev = NULL;
    p->next = NULL;
}

DElem dRemoveFirst(struct deque* d) {
    if (dIsEmpty(d)) {

        return emptyDequeException();
    }

    struct node* p = d->head;
    DElem e = p->e;

    d->head = p->next;
    free(p);

    d->size--;

    return e;
}

DElem dRemoveLast(struct deque* d) {
    if (dIsEmpty(d)) {

        return emptyDequeException();
    }

    struct node* p = d->tail;
    DElem e = p->e;

    d->tail = p->prev;
    free(p);

    d->size--;

    return e;
}

bool dIsEmpty(struct deque* d) { return d->size == 0; }

int dSize(struct deque* d) { return d->size; }

void printAll(struct deque* d) {
    struct node* p = d->head;
    for (int i = 0; i < d->size; i++) {
        printf("%d ", p->e);
        p = p->next;
    }
}

DElem emptyDequeException() {
    printf("Empty Deque Exception\n");
    
    return EMPTY_DEQUE_EXCEPTION;
}