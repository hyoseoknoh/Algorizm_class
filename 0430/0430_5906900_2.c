#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6 //     원형큐에서 한칸을 항상 비워두기 때문에 6으로 지정 
                          //     실제로는 (6-1)=5개까지 저장가능
                          //     만약 모든 슬롯을 채우면 'front == (rear + 1) % MAX_QUEUE_SIZE 조건이 참이 되어버리기 때문

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE) == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("큐가 포화상태입니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
    } else {
        printf("큐 내용: ");
        int i = q->front;
        while (1) {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d ", q->data[i]);
            if (i == q->rear) break;
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, item;

    while (1) {
        printf("\n1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 숫자를 입력하세요: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1) {
                    printf("삭제된 원소: %d\n", item);
                }
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("프로그램 종료.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    }
    return 0;
}
