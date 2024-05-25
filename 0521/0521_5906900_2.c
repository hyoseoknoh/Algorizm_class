#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 // 최대 문자열 크기 정의

// 노드 구조체 정의
typedef struct Node {
    char fruit[MAX_SIZE];
    struct Node* next;
} Node;

// 리스트 구조체 정의
typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

// 새로운 노드 생성 함수
Node* createNode(const char* fruit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->fruit, fruit);
    newNode->next = NULL;
    return newNode;
}

// 리스트 초기화 함수
void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// 리스트의 마지막에 과일 추가 함수
void addFruit(LinkedList* list, const char* fruit) {
    Node* newNode = createNode(fruit);

    // 리스트가 비어 있는 경우
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        printf("%s가 추가되었습니다.\n", fruit);
        return;
    }

    // 중복 과일 검사
    Node* temp = list->head;
    while (temp != NULL) {
        if (strcmp(temp->fruit, fruit) == 0) {
            printf("이미 존재하는 과일입니다.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    // 리스트의 마지막에 새 노드 추가
    list->tail->next = newNode;
    list->tail = newNode;
    printf("%s가 추가되었습니다.\n", fruit);
}

// 리스트에서 과일 삭제 함수
void deleteFruit(LinkedList* list, const char* fruit, LinkedList* deletedList) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* temp = list->head;
    Node* prev = NULL;

    // 삭제할 과일 탐색
    while (temp != NULL && strcmp(temp->fruit, fruit) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("해당 과일이 리스트에 없습니다.\n");
        return;
    }

    // 리스트의 첫 번째 노드 삭제
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    // 리스트의 마지막 노드가 삭제된 경우 tail 업데이트
    if (temp == list->tail) {
        list->tail = prev;
    }

    // 삭제된 과일을 deletedList에 추가
    temp->next = NULL;
    if (deletedList->head == NULL) {
        deletedList->head = temp;
        deletedList->tail = temp;
    } else {
        deletedList->tail->next = temp;
        deletedList->tail = temp;
    }

    printf("%s가 삭제되었습니다.\n", fruit);
}

// 삭제된 과일 목록 출력 함수
void printDeletedFruits(LinkedList* deletedList) {
    if (deletedList->head == NULL) {
        printf("삭제된 과일이 없습니다.\n");
        return;
    }
    printf("삭제된 과일 목록:\n");
    Node* temp = deletedList->head;
    while (temp != NULL) {
        printf("%s\n", temp->fruit);
        temp = temp->next;
    }
}

// 리스트 출력 함수
void printList(LinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%s -> ", temp->fruit);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    LinkedList deletedList;
    initList(&list);
    initList(&deletedList);

    int choice;
    char fruit[MAX_SIZE];

    // 초기 과일 리스트
    char* initialFruits[] = {
        "Mango", "Orange", "Apple", "Grape", "Cherry",
        "Plum", "Guava", "Raspberry", "Banana", "Peach"
    };

    for (int i = 0; i < 10; i++) {
        addFruit(&list, initialFruits[i]);
    }

    do {
        printf("\n메뉴:\n");
        printf("(1) 리스트의 맨 마지막에 새로운 과일 추가\n");
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
                addFruit(&list, fruit);
                break;
            case 2:
                printf("삭제할 과일을 입력하세요: ");
                fgets(fruit, sizeof(fruit), stdin);
                fruit[strcspn(fruit, "\n")] = '\0'; // 개행 문자 제거
                deleteFruit(&list, fruit, &deletedList);
                break;
            case 3:
                printDeletedFruits(&deletedList);
                break;
            case 4:
                printList(&list);
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
    while (list.head != NULL) {
        temp = list.head;
        list.head = list.head->next;
        free(temp);
    }
    while (deletedList.head != NULL) {
        temp = deletedList.head;
        deletedList.head = deletedList.head->next;
        free(temp);
    }

    return 0;
}