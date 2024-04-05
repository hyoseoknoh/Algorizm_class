#include <stdio.h>
#include <stdlib.h> // exit 함수 사용을 위해 추가
#define MAX_TERMS 101

struct term {
    float coef; // 계수
    int expon;  // 지수
};

struct term terms[MAX_TERMS] = {{8.0, 3}, {7.0, 1}, {1.0, 0}, {10.0, 3}, {3.0, 2}, {1.0, 0}};
int avail = 6;

void attach(float coef, int expon) {
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "항의 수가 너무 많습니다.\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void print_poly(int s, int e) {
    for (int i = s; i <= e; i++) {
        printf("%3.1fx^%d ", terms[i].coef, terms[i].expon);
        if (i < e) printf("+ ");
    }
    printf("\n");
}

void poly_mult(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
    float tempCoefs[MAX_TERMS] = {0}; // 임시 배열로 계수들의 합을 저장
    int tempExpons[MAX_TERMS] = {0};  // 임시 배열로 지수들을 저장
    int maxExpon = 0;                 // 결과 다항식의 최대 지수를 추적

    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int exponSum = terms[i].expon + terms[j].expon;
            tempCoefs[exponSum] += terms[i].coef * terms[j].coef;
            tempExpons[exponSum] = 1; // 지수가 사용되었음을 표시
            if (exponSum > maxExpon) {
                maxExpon = exponSum; // 최대 지수 업데이트
            }
        }
    }

    *Cs = avail;
    for (int i = maxExpon; i >= 0; i--) {
        if (tempExpons[i]) { // 지수가 사용된 경우
            attach(tempCoefs[i], i);
        }
    }
    *Ce = avail - 1;
}

int main() {
    int Cs, Ce;
    printf("A = ");
    print_poly(0, 2); // 첫 번째 다항식 출력
    printf("B = ");
    print_poly(3, 5); // 두 번째 다항식 출력

    poly_mult(0, 2, 3, 5, &Cs, &Ce); // 다항식 곱셈 수행
    printf("------------------\n");
    printf("Result of A * B = ");
    print_poly(Cs, Ce); // 결과 출력

    return 0;
}