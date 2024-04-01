#include <stdio.h>
#include <string.h> // memset 함수 사용을 위해 추가
#define MAX_DEGREE 101

struct polynomial {
    int degree;
    float coef[MAX_DEGREE];
};

// 다항식을 출력하는 함수
void printf_poly(struct polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        printf("%3.1fx^%d + ", p.coef[i], i);
    }
    printf("%3.1f\n", p.coef[0]);
}

// 다항식 곱셈 함수
struct polynomial poly_mult(struct polynomial A, struct polynomial B) {
    struct polynomial C;
    memset(&C, 0, sizeof(C)); // 결과 다항식 C 초기화

    for (int i = 0; i <= A.degree; i++) {
        for (int j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }
    C.degree = A.degree + B.degree;
    return C;
}

int main(void) {
    struct polynomial a1 = {3, {1, 2, 3, 4}}; // 4x^3 + 3x^2 + 2x + 1
    struct polynomial b1 = {2, {8, 2, 3}};    // 3x^2 + 2x + 8

    struct polynomial a2 = {6, {1, 0, 9, 0, 0, 5, 7}}; // 7x^6 + 5x^3 + 9x^2 + 1
    struct polynomial b2 = {3, {10, 1, 2, 5}};         // 5x^3 + 2x^2 + x + 10

    printf("Condition 1:\nPolynomial A: ");
    printf_poly(a1);
    printf("Polynomial B: ");
    printf_poly(b1);
    struct polynomial result1 = poly_mult(a1, b1);
    printf("Result of A * B: ");
    printf_poly(result1);

    printf("\nCondition 2:\nPolynomial A: ");
    printf_poly(a2);
    printf("Polynomial B: ");
    printf_poly(b2);
    struct polynomial result2 = poly_mult(a2, b2);
    printf("Result of A * B: ");
    printf_poly(result2);

    return 0;
}
