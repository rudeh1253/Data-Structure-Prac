/*
생일케이크

생일케이크에 n > 0개의 불 켜진 양초가 원형으로 빙둘러 서 있다.
첫 번째 양초부터 시작하여 k > 0 개의 양초를 건너뛰어 나타나는 양초의 불을 끄고 뽑아낸다
그리고는 다음 양초로부터 시작하여 k개의 양초를 건너뛰어 나타나는 양초의 불을 끄고 뽑아낸다
원을 돌면서 양초가 하나만 남을 때까지 촛불 끄고 뽑아내기를 계속
이 마지막 양초는 내부에 특수장치가 설치되어 있어서 불이 꺼짐과 동시에 멋진 축하쇼를 펼치도록 되어 있다
n과 k를 미리 알 경우, 원래 양초들의 원형 배치에서 특수 양초의 위치를 어디로 해 놓아야 마지막까지 남을지 알고 싶다
*/

#include <stdio.h>
#include "ArrayList.h"

void setCandles(List* list, int size) {
    for (int i = 0; i < size; i++) {
        listAddLast(list, i + 1);
    }
    printf("a: %d\n", sizeOfList(list));
}

int getLastCandle(List* list, int k, int start) {
    if (sizeOfList(list) == 1) { return listGet(list, 0); }

    int removeIdx = (start + k) % sizeOfList(list);
    printf("Remove candle: %d\n", listGet(list, removeIdx));
    listRemove(list, removeIdx);

    return getLastCandle(list, k, (sizeOfList(list) + removeIdx - 1) % sizeOfList(list));
}

int main() {
    int n, k;
    printf("Enter N, K: "); scanf("%d%d", &n, &k);

    List list; List* l = &list;
    listInit(l);

    setCandles(l, n);

    int lastCandle = getLastCandle(l, k, 0);
    printf("Last Candle: %d\n", lastCandle);

    return 0;
}

// 시간이 남으면 circular linked list로도 풀어 보도록 하자.