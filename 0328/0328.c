#include <stdio.h>
#define MAX_DEGREE 101  // 최대 차수 정의

// 다항식 구조체 정의
struct polynomial {
    int degree;                 // 다항식의 최고 차수
    float coef[MAX_DEGREE];    // 계수 배열
};

// 다항식 출력 함수
void print_poly(struct polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        // 각 항 출력 (차수에 따라)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i - 1);
    }
    // 상수항 출력
    printf("%3.1f\n", p.coef[p.degree - 1]);
}

// 다항식 곱셈 함수
struct polynomial poly_mult(struct polynomial A, struct polynomial B) {
    struct polynomial C; // 결과 다항식
    C.degree = A.degree + B.degree - 2;
    for (int i = 0; i <= C.degree; i++) C.coef[i] = 0;  // 결과 다항식 계수 초기화
    
    // 두 다항식의 각 항을 곱하여 결과 다항식의 계수에 더함
    for (int i = 0; i < A.degree; i++) {
        for (int j = 0; j < B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }
    return C; // 결과 다항식 반환
}

int main(void) {
    // 예시 다항식 a, b 정의
    struct polynomial a = {4, {4, 3, 2, 1}};  // 4x^3 + 3x^2 + 2x + 1
    struct polynomial b = {3, {3, 2, 8}};    // 3x^2 + 2x + 8
    struct polynomial c;  // 곱셈 결과 저장할 다항식

    // 다항식 출력
    printf("Polynomial A: ");
    print_poly(a);
    printf("Polynomial B: ");
    print_poly(b);

    // 다항식 곱셈 수행 및 결과 출력
    c = poly_mult(a, b);     
    printf("------------------\n");
    printf("Result of A * B: ");
    print_poly(c);  

    // 두 번째 예시 다항식 a2, b2 정의 및 곱셈 결과 출력
    struct polynomial a2 = {7, {7, 0, 0, 5, 9, 0, 1}}; // 7x^6 + 5x^3 + 9x^2 + 1
    struct polynomial b2 = {4, {5, 2, 1, 10}};         // 5x^3 + 2x^2 + x + 10
    struct polynomial c2 = poly_mult(a2, b2);
    printf("\nPolynomial A2: ");
    print_poly(a2);
    printf("Polynomial B2: ");
    print_poly(b2);
    printf("------------------\n");
    printf("Result of A2 * B2: ");
    print_poly(c2);  // 결과 출력

    return 0;
}
