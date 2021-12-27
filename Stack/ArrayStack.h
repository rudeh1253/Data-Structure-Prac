/*
 * ADT Method header file of stack based on array.
 */

#include <stdbool.h>

#define EMPTY_STACK_EXCEPTION    -152152
#define FULL_STACK_EXCEPTION    -1691615

#define NULL_ELEM    0

typedef int SElem;

struct _stack {
    SElem* container;
    int top;
    int maxSize;
};

typedef struct _node Node;
typedef struct _stack Stack;

/* Initialization of stack */
void sInit(Stack*);

/* Main ADT Method */
SElem sPush(Stack*, SElem);
SElem sPop(Stack*);

/* Secondary ADT Method */
SElem sPeek(Stack*);
int sSize(Stack*);
bool sIsEmpty(Stack*);
// iterator elements();

/* support */
void increaseSize(Stack*);