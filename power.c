#include <stdio.h>
#include <time.h>                            // time 함수를 사용하기 위한 헤더 파일

// 반복적 방법으로 거듭제곱을 계산하는 함수
long long power_iter(long long n1, int n2) {    // 반복적 함수 정의
    long long result = 1;                       // 결과를 저장할 변수
    while (n2 > 0) {                            // n2가 0보다 클 때까지 반복
        result *= n1;                           // n1을 result에 곱함
        n2--;                                   // n2를 1 감소
    }
    return result;
}

// 재귀적 방법으로 거듭제곱을 계산하는 함수
long long power_rec(long long n1, int n2) {     // 재귀적 함수 정의
    if (n2 == 0) return 1;                      // 종료 조건
    return n1 * power_rec(n1, n2 - 1);          // 재귀 호출
}

int main(void) {
    clock_t start, end;                         // 시간 측정을 위한 변수
    long long result_iter, result_rec;          // 거듭제곱 계산 결과를 저장할 변수
    double duration_iter, duration_rec;         // 거듭제곱 계산 시간을 저장할 변수

    // 거듭제곱 계산 및 시간 측정 - 반복적 방법
    start = clock();                            // 시간 측정 시작
    result_iter = power_iter(13, 21);           // 거듭제곱 계산
    end = clock();                              // 시간 측정 종료
    duration_iter = (double)(end - start) / CLOCKS_PER_SEC; // 경과 시간 계산

    // 거듭제곱 계산 및 시간 측정 - 재귀적 방법
    start = clock();                            // 시간 측정 시작
    result_rec = power_rec(13, 21);             // 거듭제곱 계산
    end = clock();                              // 시간 측정 종료
    duration_rec = (double)(end - start) / CLOCKS_PER_SEC;  // 경과 시간 계산

    printf("Power Iterative Result: %lld, Time: %.6f seconds\n", result_iter, duration_iter);   // 결과 출력
    printf("Power Recursive Result: %lld, Time: %.6f seconds\n", result_rec, duration_rec);     // 결과 출력

    return 0;
}
