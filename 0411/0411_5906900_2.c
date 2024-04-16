#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
    element *stack; // 스택 요소를 담을 동적 배열
    int top;        // 스택의 최상위 인덱스
    int capacity;   // 현재 스택의 용량
} StackType;

// 스택 초기화 함수
void init_stack(StackType *sptr, int capacity) {
    sptr->top = -1;
    sptr->capacity = capacity; // 초기 설정된 용량
    sptr->stack = (element *)malloc(sptr->capacity * sizeof(element));
    if (sptr->stack == NULL) {
        perror("Failed to initialize stack");
        exit(EXIT_FAILURE);
    }
}

// 스택이 가득 찼는지 확인
int is_full(StackType *sptr) {
    return (sptr->top >= sptr->capacity - 1);
}

// 스택이 비어 있는지 확인
int is_empty(StackType *sptr) {
    return (sptr->top == -1);
}

// 스택에 항목 추가
void push(StackType *sptr, element item) {
    // 스택이 가득 찼다면, 용량 확장
    if (is_full(sptr)) {
        sptr->capacity *= 2; // 용량을 2배로 증가
        sptr->stack = (element *)realloc(sptr->stack, sptr->capacity * sizeof(element));
        if (sptr->stack == NULL) {
            perror("Failed to expand stack");
            exit(EXIT_FAILURE);
        }
    }
    sptr->stack[++(sptr->top)] = item;
    printf("Push: %d\n", item);
}

// 스택에서 항목 제거
element pop(StackType *sptr) {
    if (is_empty(sptr)) {
        printf("Stack Underflow\n");
        return -1; // 에러 값
    } else {
        return sptr->stack[(sptr->top)--];
    }
}

// 스택 출력
void print_stack(StackType *sptr) {
    if (is_empty(sptr)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= sptr->top; i++) {
            printf("%d ", sptr->stack[i]);
        }
        printf("\n");
    }
}

int main() {
    StackType s;
    init_stack(&s, 5); // 초기 크기를 5로 설정

    srand(time(NULL)); // 난수 생성기 초기화

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1; // 1~100 사이의 난수 생성
        printf("\ncurrent rand_num: %d | ", rand_num);
        
        if (rand_num % 2 == 0) { // 짝수인 경우
            printf("Even\n");
            push(&s, rand_num);
        } else { // 홀수인 경우
            printf("Odd\n");
            if (!is_empty(&s)) pop(&s);
        }
        print_stack(&s);
    }
    
    free(s.stack); // 동적 할당된 스택 메모리 해제
    return 0;
}
