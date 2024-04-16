#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>
 
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
	// element data[];
	element *data;
	int capacity;
	int top;
} StackType;


// create : 이미 만들었음, StackType의 변수를 선언하면 만들어짐
// delete : 할수 없음

// init 
void init(StackType* sptr, int ofs) {
	sptr->data = (element *)malloc(sizeof(StackType) * ofs);
	sptr->top = -1;
	sptr->capacity = ofs;
}

// is_full
int is_full( StackType *sptr) {
	if (sptr->top == sptr->capacity - 1) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
	}
}

int is_empty(StackType *sptr) {
	return (sptr->top == -1);
}

// push
void push(StackType *sptr, element item) {

	if (is_full(sptr)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		sptr->top = sptr->top + 1;
		sptr->data[sptr->top] = item;
	}
}

element pop(StackType *sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = sptr->stack[sptr->top];
		// sptr->top = sptr->top - 1;
		// return r;
		return (sptr->data[(sptr->top)--]);
	}
}

element peek(StackType * sptr) {
	
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = stack[top];
		// top = top - 1;
		// return r;
		return (sptr->data[sptr->top]);
	}
}

int eval(char expr[]){
    StackType s;

    init(&s, 20);

    int len = strlen(expr);

    for(int i=0; i<len; i++){
        int ch = expr[i];
        int value;
        int op1,op2;
        int result;

        if( (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') ){
            op2 = pop(&s);
            op1 = pop(&s);
            // if(ch=='+'){
            //     value = op1 + op2;
            //     push(&s, result);
            // }else if(ch=='-'){
            //     value = op1 - op2;
            //     push(&s, result);
            // }else if(ch=='*'){
            //     value = op1 * op2;
            //     push(&s, result);
            // }else if(ch=='/'){
            //     value = op1 / op2;
            //     push(&s, result);
            // }

            switch(ch){
                case '+':   push(&s, op1 + op2);    break;
                case '-':   push(&s, op1 - op2);    break;
                case '*':   push(&s, op1 * op2);    break;
                case '/':   push(&s, op1 / op2);    break;
                
            }

        }
        else if( (ch>='0') && (ch<='9') ){
            value = ch - '0';
            push(&s, value);
        }
        else{
            printf(" Abnomal character in expr\n");
        }
    }
    return pop(&s);
}


int main() {
    int result;

    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf(" 계산결과 : %d\n", result);
}