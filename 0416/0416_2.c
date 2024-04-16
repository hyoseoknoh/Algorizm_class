#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isdigit function

#define MAX_STACK_SIZE 100
#define BUFFER_SIZE 100

typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Push an element onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        fprintf(stderr, "Stack is full\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = item;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(const char *expr) {
    Stack s;
    initStack(&s);
    char buffer[BUFFER_SIZE];
    strcpy(buffer, expr); // Copy the expression to a buffer for tokenization

    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&s, atoi(token));
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (token[0]) {
            case '+': push(&s, val1 + val2); break;
            case '-': push(&s, val1 - val2); break;
            case '*': push(&s, val1 * val2); break;
            case '/': push(&s, val1 / val2); break;
            default:
                fprintf(stderr, "Unknown operator: %c\n", token[0]);
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(&s);
}

int main() {
    char expr[BUFFER_SIZE];
    printf("Postfix Expression: ");
    fgets(expr, BUFFER_SIZE, stdin); // Read input with fgets

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}


