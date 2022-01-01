/*
 * 응용문제: 기간
 * 배열 X에 대해, X[i]의 기간(span) S[i]란 X[i] 바로 앞의
 * X[j] <= X[i]인 연속적인 X[j] 원소들의 최대 개수다
 */

#include <stdio.h>
#include "LinkedListStack.h"

void getSpanArr(int X[], int S[], int n);
void getSpan(int X[], int S[], int n, Stack* stack);

int main() {
    int n; scanf("%d", &n);
    int X[n], S[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    getSpanArr(X, S, n);

    for (int i = 0; i < n; i++) {
        printf("%d  ", S[i]);
    } printf("\n");

    return 0;
}

void getSpanArr(int X[], int S[], int n) {
    Stack idxStack;
    sInit(&idxStack);
    for (int i = 0; i < n; i++) {
        getSpan(X, S, i, &idxStack);
    }
}

void getSpan(int X[], int S[], int n, Stack* idxStack) {
    while (!sIsEmpty(idxStack) && X[sPeek(idxStack)] <= X[n]) {
        sPop(idxStack);
    }
    if (sIsEmpty(idxStack)) {
        S[n] = n + 1;
    } else {
        S[n] = n - sPeek(idxStack);
    }
    sPush(idxStack, n);
}