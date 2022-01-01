/*
재귀를 이용하여 10진수를 2진수로 변환하여 출력하시오. (반복문 사용시 감점 0점처리) - 입력은 10진수 정수 n이 입력된다. 
*/

#include <stdio.h>

void printBinary(int decimal) {
    if (decimal <= 1) {
        printf("%d ", decimal % 2);

        return;
    }

    printBinary(decimal / 2);

    if (decimal % 2 == 1) {
        printf("1 ");
    } else {
        printf("0 ");
    }
}

int main() {
    int n; scanf("%d", &n);

    printBinary(n);
    printf("\n");

    return 0;
}