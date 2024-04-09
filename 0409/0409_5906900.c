#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// 스택이 가득 찼는지 확인하는 함수
int is_full() {
    return top >= MAX_STACK_SIZE - 1;
}

// 스택이 비어 있는지 확인하는 함수
int is_empty() {
    return top == -1;
}

// 스택에 항목을 추가하는 함수
void push(element item) {
    if (is_full()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
        printf("push: %d\n", item);
    }
}

// 스택에서 항목을 제거하고 반환하는 함수
element pop() {
    if (is_empty()) {
        printf("Stack Underflow\nStack is empty\n");
        return -1; // 스택이 비었을 때 반환되는 에러 값을 나타냄
    } else {
        printf("pop: %d\n", stack[top]);
        return stack[top--];
    }
}

// 스택의 최상단 항목을 출력하는 함수
void print_stack() {
    if (is_empty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // 난수 생성기 초기화
    
    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1; // 1~100 사이의 난수 생성
        printf("\ncurrent rand_num: %d | ", rand_num);
        if (rand_num % 2 == 0) { // 난수가 짝수이면
            printf("Even\n");
            push(rand_num);
        } else { // 난수가 홀수이면
            printf("Odd\n");
            pop();
        }
        print_stack();
    }
    
    return 0;
}
 