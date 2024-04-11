#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
void init_stack(StackType *sptr){
    sptr->top = -1;
}
// 스택이 가득 찼는지 확인하는 함수
int is_full(StackType *sptr) {
    return (sptr->top == MAX_STACK_SIZE - 1);
}

// 스택이 비어 있는지 확인하는 함수
int is_empty(StackType *sptr) {
    return (sptr->top == -1);
}

// 스택에 항목을 추가하는 함수
void push(StackType *sptr, element item) {
    if (is_full(sptr)) {
        printf("Stack Overflow\n");
    } else {
        sptr->stack[++(sptr->top)] = item;
        printf("Push: %d\n", item);
    }
}

// 스택에서 항목을 제거하고 반환하는 함수
element pop(StackType *sptr) {
    if (is_empty(sptr)) {
        printf("Stack Underflow\nStack is empty\n");
        return -1; // 스택이 비었을 때 반환되는 에러 값을 나타냄
    } else {
        printf("Pop: %d\n", sptr->stack[sptr->top]);
        return sptr->stack[(sptr->top)--];
    }
}

// 스택의 최상단 항목을 출력하는 함수
void print_stack(StackType *sptr) {
    if (is_empty(sptr)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = sptr->top; i >= 0; i--) {
            printf("%d ", sptr->stack[i]);
        }
        printf("\n");
    }
}

int main() {
    StackType s;
    init_stack(&s);


    srand(time(NULL)); // 난수 생성기 초기화
    
    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1; // 1~100 사이의 난수 생성
        printf("\ncurrent rand_num: %d | ", rand_num);
        if (rand_num % 2 == 0) { // 난수가 짝수이면
            push(&s, rand_num);
        } else { // 난수가 홀수이면
            pop(&s);
        }
        print_stack(&s);
    }
    
    return 0;
}
