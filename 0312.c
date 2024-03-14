#include <stdio.h>

// 함수 선언
int isPrime(int num);

int main(void) {
    int sum = 0; // 소수의 합을 저장할 변수
    for (int i = 2; i <= 100; i++) { // 0과 1은 소수가 아니므로 2부터 시작
        if (isPrime(i)) { // i가 소수인 경우
            printf("%d ", i); // 출력
            sum += i; // 합산
        }
    }

    printf("0부터 100까지의 소수의 합은 %d입니다.\n", sum);
    return 0;
}

// 소수 판별 함수
int isPrime(int num) {
    if (num <= 1) return 0; // 0과 1은 소수가 아님
    for (int i = 2; i*i <= num; i++) { // 제곱근까지만 검사
        if (num % i == 0) return 0; // 나누어 떨어지면 소수가 아님
    }
    return 1; // 소수임
}
