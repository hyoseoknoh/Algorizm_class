#include <stdio.h>
#include <time.h>                         // time 함수를 사용하기 위한 헤더 파일

// 반복적 방법으로 팩토리얼을 계산하는 함수
long long factorial_iter(int n) {    // 반복적 함수 정의
    long long result = 1;           // 결과를 저장할 변수
    for (int i = 2; i <= n; i++) {  // 2부터 n까지 반복
        result *= i;            // i를 result에 곱함
    }
    return result;              
}

// 재귀적 방법으로 팩토리얼을 계산하는 함수
long long factorial_rec(int n) {        // 재귀적 함수 정의
    if (n <= 1) return 1;               // 종료 조건
    return n * factorial_rec(n - 1);    // 재귀 호출
}

int main(void) {
    clock_t start, end;                     // 시간 측정을 위한 변수
    long long result_iter, result_rec;      // 팩토리얼 계산 결과를 저장할 변수
    double duration_iter, duration_rec;     // 팩토리얼 계산 시간을 저장할 변수

    // 팩토리얼 계산 및 시간 측정 - 반복적 방법
    start = clock();                    // 시간 측정 시작
    result_iter = factorial_iter(20);   // 팩토리얼 계산
    end = clock();                      // 시간 측정 종료
    duration_iter = (double)(end - start) / CLOCKS_PER_SEC;  // 경과 시간 계산

    // 팩토리얼 계산 및 시간 측정 - 재귀적 방법
    start = clock();                // 시간 측정 시작
    result_rec = factorial_rec(20); // 팩토리얼 계산
    end = clock();                  // 시간 측정 종료
    duration_rec = (double)(end - start) / CLOCKS_PER_SEC;  // 경과 시간 계산

    printf("Factorial Iterative Result: %lld, Time: %.6f seconds\n", result_iter, duration_iter);   // 결과 출력
    printf("Factorial Recursive Result: %lld, Time: %.6f seconds\n", result_rec, duration_rec);     // 결과 출력

    return 0;
}
