#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // tolower() 함수 사용을 위한 헤더 파일
#include <string.h> // strlen() 함수 사용을 위한 헤더 파일

#define MAX_SIZE 100 // 최대 문자열 크기 정의

// 스택 구조체 정의
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// 큐 구조체 정의
typedef struct {
    char items[MAX_SIZE];
    int front, rear;
} Queue;

// 스택 초기화 함수
void initStack(Stack *s) {
    s->top = -1;
}

// 큐 초기화 함수
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFullStack(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 스택이 비었는지 확인하는 함수
int isEmptyStack(Stack *s) {
    return s->top == -1;
}

// 큐가 가득 찼는지 확인하는 함수
int isFullQueue(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// 큐가 비었는지 확인하는 함수
int isEmptyQueue(Queue *q) {
    return q->front > q->rear;
}

// 스택에 원소를 푸시하는 함수
void push(Stack *s, char item) {
    if (isFullStack(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->items[++s->top] = item;
}

// 스택에서 원소를 팝하는 함수
char pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("스택이 비었습니다.\n");
        return '\0';
    }
    return s->items[s->top--];
}

// 큐에 원소를 인큐하는 함수
void enqueue(Queue *q, char item) {
    if (isFullQueue(q)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->items[++q->rear] = item;
}

// 큐에서 원소를 디큐하는 함수
char dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("큐가 비었습니다.\n");
        return '\0';
    }
    return q->items[q->front++];
}

// 주어진 문자열이 회문인지 검사하는 함수
int isPalindrome(char *str) {
    Stack s;
    Queue q;
    initStack(&s);
    initQueue(&q);

    char c;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) { // 알파벳인 경우만 고려
            c = tolower(str[i]); // 소문자로 변환
            push(&s, c); // 스택에 푸시
            enqueue(&q, c); // 큐에 인큐
        }
    }

    while (!isEmptyStack(&s)) {
        if (pop(&s) != dequeue(&q)) {
            return 0; // 회문이 아님
        }
    }
    return 1; // 회문임
}

int main() {
    int choice;
    char text[MAX_SIZE];

    do {
        printf("\n1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);
        getchar(); // 개행 문자 소비

        switch (choice) {
            case 1:
                printf("회문을 입력하세요 : ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // 개행 문자 제거
                break;
            case 2:
                if (isPalindrome(text)) { // 입력된 텍스트가 회문인지 검사
                    printf("\"%s\" 은 회문입니다.\n", text);
                } else {
                    printf("\"%s\" 은 회문이 아닙니다.\n", text);
                }
                break;
            case 3:
                printf("프로그램 종료.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    } while (choice != 3); // 사용자가 '3'을 입력하여 종료를 선택할 때까지 반복

    return 0;
}
