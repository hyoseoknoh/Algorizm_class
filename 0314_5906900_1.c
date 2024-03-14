#include <stdio.h>
#include <time.h>

// 함수 선언
int isPrime(int num);

int main(void) {
    clock_t start, end; // 시간 측정을 위한 변수
    double cpu_time_used;   // 소요된 시간을 저장할 변수
    int sum = 0;    // 소수의 합을 저장할 변수

    start = clock(); // 시간 측정 시작

    // 소수의 합 계산
    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    end = clock(); // 시간 측정 종료
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // 소요된 시간 계산

    // 결과 출력
    printf("0부터 100까지의 소수의 합: %d\n", sum);
    printf("수행 시간: %f 초\n", cpu_time_used);

    return 0;
}

// 소수 판별 함수
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}