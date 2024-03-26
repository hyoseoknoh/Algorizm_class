#include <stdio.h>

// 먼저, 구조체와 함께 typedef를 사용하여 새로운 타입을 정의합니다.
typedef struct new {
    int a, b;
} new;

int main(void) {
    // 구조체 new의 인스턴스 p1, p2를 생성하고 초기화합니다.
    new p1 = {1, 2};
    new p2 = {9, 8};

    // p1의 멤버 a의 값을 출력합니다.
    printf("%d", p1.a);

    return 0;
}
