#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define BUFFER_SIZE 100

// 스택 구조체 정의
typedef struct {
    char items[MAX_STACK_SIZE]; // 스택 내 아이템 저장
    int top;                    // 스택의 최상위 인덱스
} CharStack;

typedef struct {
    int items[MAX_STACK_SIZE];  // 스택 내 아이템 저장
    int top;                    // 스택의 최상위 인덱스
} IntStack;

// 스택 초기화 함수
void initCharStack(CharStack *s) {
    s->top = -1;
}

void initIntStack(IntStack *s) {
    s->top = -1;
}

// 스택이 가득 찼는지 확인
int isCharStackFull(CharStack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isIntStackFull(IntStack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 스택이 비었는지 확인
int isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

int isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

// 스택에 문자 추가
void pushChar(CharStack *s, char item) {
    if (isCharStackFull(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->items[++s->top] = item;
}

// 스택에 정수 추가
void pushInt(IntStack *s, int item) {
    if (isIntStackFull(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->items[++s->top] = item;
}

// 스택에서 문자 제거
char popChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        printf("스택이 비었습니다.\n");
        return '\0';
    }
    return s->items[s->top--];
}

// 스택에서 정수 제거
int popInt(IntStack *s) {
    if (isIntStackEmpty(s)) {
        printf("스택이 비었습니다.\n");
        return -1;
    }
    return s->items[s->top--];
}

// 연산자 우선순위 판단
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 중위 표현식을 후위 표현식으로 변환
void infixToPostfix(char* infix, char* postfix) {
    CharStack s;
    initCharStack(&s);
    int i, j = 0;
    char item;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (isdigit(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            pushChar(&s, '(');
        } else if (item == ')') {
            while (!isCharStackEmpty(&s) && (item = popChar(&s)) != '(') {
                postfix[j++] = item;
            }
        } else {
            while (!isCharStackEmpty(&s) && precedence(s.items[s.top]) >= precedence(item)) {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, item);
        }
    }

    while (!isCharStackEmpty(&s)) {
        postfix[j++] = popChar(&s);
    }
    postfix[j] = '\0';
}

// 후위 표현식 계산
int evaluatePostfix(char* postfix) {
    IntStack s;
    initIntStack(&s);
    char item;
    int i, val1, val2;

    for (i = 0; postfix[i] != '\0'; i++) {
        item = postfix[i];
        if (isdigit(item)) {
            pushInt(&s, item - '0');
        } else {
            val2 = popInt(&s);
            val1 = popInt(&s);
            switch(item) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
            }
        }
    }
    return popInt(&s);
}

int main() {
    char infix[BUFFER_SIZE], postfix[BUFFER_SIZE];
    int result, choice;

    do {
        printf("\n1. 중위식을 입력받음\n");
        printf("2. 중위식을 후위식으로 변환\n");
        printf("3. 후위식을 계산\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        getchar(); // 개행 문자 제거

        switch (choice) {
            case 1:
                printf("중위식을 입력하세요: ");
                fgets(infix, sizeof(infix), stdin);
                infix[strlen(infix) - 1] = '\0'; // 개행 문자 제거
                break;
            case 2:
                infixToPostfix(infix, postfix);
                printf("후위식: %s\n", postfix);
                break;
            case 3:
                result = evaluatePostfix(postfix);
                printf("계산 결과: %d\n", result);
                break;
            case 4:
                printf("프로그램 종료.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요...\n");
        }
    } while (choice != 4);

    return 0;
}
