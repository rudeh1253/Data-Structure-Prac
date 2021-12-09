/*
원시 데이터값들로 구성된 배열 X의 i-번째 누적평균(prefix average)이란 X의 i-번째에
이르기까지의 (i + 1)개 원소들의 평균이다. 즉, A[i] = (X[0] + X[1] + … + X[i])/(i + 1)
누적평균은 경제, 통계 분야에서 오르내림 변동을 순화시킴으로써 대략적 추세를 얻어내기 위해
사용된다. 일례로 부동산, 주식, 펀드 등에도 자주 활용된다.. 이 문제는 배열 X의 누적평균(prefix
average) 배열 A를 구하는 프로그램을 구현하고 테스트하는데 관한 것이다.
prefixAverages1는 i 번째 외부 반복에서는, 바로 전 i – 1번째 반복에서 구했던 [0 ~ i – 1]의 합에, i + 1 번째 원소 값 한 개만을 더해 현재 합을
얻어 평균을 구한다.
 중간 합을 보관하는 방식으로 알고리즘을 개선한 함수
prefixAverage2는 누적평균값들을 선형 시간에 구할 수 있게 된다.
함수 prefixAverages1과 prefixAverages2, 그리고 이들을 테스트할 수 있는 main 함수를
구현하여 아래 테스트를 수행하라.
1) main 함수는 아래 형식의 표준입력을 사용하여 배열 X를 초기화한 후 각 함수를 호출한다. 입력 : main 함수는 다음 값들을 표준입력 받는다. 첫 번째 라인: 정수 n (배열 X의 크기)
두 번째 이후 라인: X[0] X[1] X[2] ... (배열 X, 한 라인 상의 양의 정수 수열)
※ 힌트: n의 크기에는 제한이 없다. 따라서 동적 할당을 사용하여야 함)
2) main 함수는 아래 형식의 표준출력을 사용하여 각 함수로부터 반환된 배열 A를 출력한다. 출력 : A[0] A[1] A[2] ... (배열 X와 같은 크기의 배열 A의 원소들을 나타내는 한 라인 상의 양의 정수 수열로
서 첫 번째 라인은 prefixAverages1의 출력을, 두 번째 라인은 prefixAverages2의 출
력을 나타낸다)
3) 평균 계산 시 소수점 이하를 반올림하여 정수로 구한다. 정확한 반올림을 위해, %.f를 쓰지 말
고 int 성질을 이용해서 반올림하라. 
*/

#include <stdio.h>

void prefixAverages1(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += arr[j];
        }
        float average = sum / (i + 1);
        if (average >= ((int)average) + 0.5) {
            printf("%d", ((int)average) + 1);
        } else {
            printf("%d ", ((int)average));
        }
    }
    printf("\n");
}

void prefixAverages2(int* arr, int n) {
    int sum = 0;
    float average;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        average = (float)sum / (i + 1);
        if (average >= ((int)average) + 0.5) {
            printf("%d", ((int)average) + 1);
        } else {
            printf("%d ", ((int)average));
        }
    }
    printf("\n");
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    prefixAverages1(arr, n);
    prefixAverages2(arr, n);

    return 0;
}