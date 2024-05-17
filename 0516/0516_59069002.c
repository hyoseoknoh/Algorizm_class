#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 리스트 초기화 함수
Node* initList() {
    return NULL;
}

// 리스트의 길이 반환 함수
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->next;
        length++;
    }
    return length;
}

// 리스트에 숫자 삽입 함수
void insert(Node** head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        printf("노드 삽입 완료 (이동 횟수: 0)\n");
        return;
    }

    Node* temp = *head;
    int count = 0;

    // 삽입할 위치가 리스트의 길이보다 큰 경우 리스트의 끝에 삽입
    if (position >= getLength(*head)) {
        printf("삽입 위치가 리스트의 범위를 벗어났습니다. 리스트의 끝에 삽입합니다.\n");
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        temp->next = newNode;
    } else {
        while (count < position - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("노드 삽입 완료 (이동 횟수: %d)\n", count);
}

// 리스트에서 숫자 삭제 함수
void delete(Node** head, int position) {
    if (*head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("노드 삭제 완료 (이동 횟수: 0)\n");
        return;
    }

    int count = 0;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("삭제 위치가 리스트의 범위를 벗어났습니다.\n");
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;

    printf("노드 삭제 완료 (이동 횟수: %d)\n", count);
}

// 리스트 출력 함수
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 프로그램 메인 함수
int main() {
    Node* head = initList();
    int choice, data, position;

    while (1) {
        printf("\n메뉴:\n");
        printf("(1) 리스트에 추가\n");
        printf("(2) 리스트에서 삭제\n");
        printf("(3) 리스트 출력\n");
        printf("(0) 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 숫자와 위치를 입력하세요: ");
                scanf("%d %d", &data, &position);
                insert(&head, data, position);
                break;
            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                delete(&head, position);
                break;
            case 3:
                printList(head);
                break;
            case 0:
                printf("프로그램 종료.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}