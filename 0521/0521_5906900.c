#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트 노드 구조체 정의
typedef struct Node {
    char fruit[100];
    struct Node* next;
} Node;

// 노드 생성 함수
Node* createNode(const char* fruit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->fruit, fruit);
    newNode->next = NULL;
    return newNode;
}

// 리스트의 마지막에 과일 추가
void addFruit(Node** head, const char* fruit) {
    Node* newNode = createNode(fruit);
    if (*head == NULL) {
        *head = newNode;
        printf("%s가 추가되었습니다.\n", fruit);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        if (strcmp(temp->fruit, fruit) == 0) {
            printf("이미 존재하는 과일입니다.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (strcmp(temp->fruit, fruit) == 0) {
        printf("이미 존재하는 과일입니다.\n");
        free(newNode);
        return;
    }
    temp->next = newNode;
    printf("%s가 추가되었습니다.\n", fruit);
}

// 리스트에서 과일 삭제
void deleteFruit(Node** head, const char* fruit, Node** deletedHead) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->fruit, fruit) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("해당 과일이 리스트에 없습니다.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    temp->next = *deletedHead;
    *deletedHead = temp;
    printf("%s가 삭제되었습니다.\n", fruit);
}

// 삭제된 과일 목록 출력
void printDeletedFruits(Node* deletedHead) {
    if (deletedHead == NULL) {
        printf("삭제된 과일이 없습니다.\n");
        return;
    }
    printf("삭제된 과일 목록:\n");
    Node* temp = deletedHead;
    while (temp != NULL) {
        printf("%s\n", temp->fruit);
        temp = temp->next;
    }
}

// 현재 리스트 출력
void printList(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->fruit);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    Node* deletedHead = NULL;
    int choice;
    char fruit[100];

    // 초기 과일 리스트
    char* initialFruits[] = {
        "Mango", "Orange", "Apple", "Grape", "Cherry",
        "Plum", "Guava", "Raspberry", "Banana", "Peach"
    };

    for (int i = 0; i < 10; i++) {
        addFruit(&head, initialFruits[i]);
    }

    do {
        printf("\n메뉴:\n");
        printf("(1) 리스트의 매 마지막에 새로운 과일 추가\n");
        printf("(2) 리스트에 있는 과일 삭제\n");
        printf("(3) 삭제된 과일 목록 출력\n");
        printf("(4) 리스트 출력\n");
        printf("(0) 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); // 개행 문자 소비

        switch (choice) {
            case 1:
                printf("추가할 과일을 입력하세요: ");
                fgets(fruit, sizeof(fruit), stdin);
                fruit[strcspn(fruit, "\n")] = '\0'; // 개행 문자 제거
                addFruit(&head, fruit);
                break;
            case 2:
                printf("삭제할 과일을 입력하세요: ");
                fgets(fruit, sizeof(fruit), stdin);
                fruit[strcspn(fruit, "\n")] = '\0'; // 개행 문자 제거
                deleteFruit(&head, fruit, &deletedHead);
                break;
            case 3:
                printDeletedFruits(deletedHead);
                break;
            case 4:
                printList(head);
                break;
            case 0:
                printf("프로그램 종료.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                break;
        }
    } while (choice != 0);

    // 메모리 해제
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    while (deletedHead != NULL) {
        temp = deletedHead;
        deletedHead = deletedHead->next;
        free(temp);
    }

    return 0;
}