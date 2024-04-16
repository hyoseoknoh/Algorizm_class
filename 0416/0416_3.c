#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 숫자를 확인하기 위해 ctype 헤더 포함

#define MAX_STACK_SIZE 100
#define BUFFER_SIZE 100

// 스택 구조체 정의
typedef struct {
    int items[MAX_STACK_SIZE]; // 스택의 데이터를 저장할 배열
    int top;                   // 스택의 최상위 요소 인덱스
} Stack;

// 스택 초기화 함수
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFull(Stack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// 스택에 요소를 추가하는 함수
void push(Stack *s, int item) {
    if (isFull(s)) {
        fprintf(stderr, "스택이 가득 찼습니다.\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = item;
}

// 스택에서 요소를 제거하는 함수
int pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택이 비었습니다.\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// 후위 표현식을 계산하는 함수
int evaluatePostfix(const char *expr) {
    Stack s;
    initStack(&s);
    char buffer[BUFFER_SIZE];
    strcpy(buffer, expr); // 표현식을 버퍼에 복사

    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (isdigit(token[0])) { // 토큰이 숫자인 경우
            push(&s, atoi(token)); // 정수로 변환 후 스택에 푸시
        } else { // 연산자인 경우
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (token[0]) { // 연산 수행
            case '+': push(&s, val1 + val2); break;
            case '-': push(&s, val1 - val2); break;
            case '*': push(&s, val1 * val2); break;
            case '/': push(&s, val1 / val2); break;
            default:
                fprintf(stderr, "알 수 없는 연산자입니다: %c\n", token[0]);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " "); // 다음 토큰으로 이동
    }

    return pop(&s); // 결과 반환
}

int main() {
    char expr[BUFFER_SIZE];
    printf("후위 표현식을 입력하세요: ");
    fgets(expr, BUFFER_SIZE, stdin); // 후위 표현식 입력 받기

    int result = evaluatePostfix(expr);
    printf("결과: %d\n", result);
    return 0;
}
