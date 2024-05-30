#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode{
    element data;
    struct listNode* link;
} listNode;

// 리스트의 첫 번째 위치에 노드를 삽입하는 함수
listNode *insert_first(listNode *tail, element data) {
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    } else {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

// 리스트의 마지막 위치에 노드를 삽입하는 함수
listNode *insert_last(listNode *tail, element data) {
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = node;
    } else {
        node->link = tail->link;
        tail->link = node;
        tail = node;
    }
    return tail;
}

// 리스트의 첫 번째 노드를 삭제하는 함수
listNode *delete_first(listNode *tail) {
    if (tail == NULL) {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }
    listNode *removed = tail->link;
    if (tail == removed) { // 리스트에 노드가 하나만 있는 경우
        free(removed);
        return NULL;
    } else {
        tail->link = removed->link;
        free(removed);
        return tail;
    }
}

// 리스트의 마지막 노드를 삭제하는 함수
listNode *delete_last(listNode *tail) {
    if (tail == NULL) {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }
    listNode *current = tail->link;
    if (tail == current) { // 리스트에 노드가 하나만 있는 경우
        free(current);
        return NULL;
    } else {
        while (current->link != tail) {
            current = current->link;
        }
        current->link = tail->link;
        free(tail);
        return current;
    }
}

// 리스트를 출력하는 함수
void print_list(listNode *tail) {
    if (tail == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    listNode *p = tail->link;
    do {
        printf("[%2d] -> ", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("NULL\n");
}

int main() {
    listNode *tail = NULL;
    int choice, value;

    do {
        printf("\n메뉴:\n");
        printf("(1) 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("(2) 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("(3) 리스트 처음 노드 삭제\n");
        printf("(4) 리스트 마지막 노드 삭제\n");
        printf("(5) 리스트 프린트\n");
        printf("(6) 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("숫자를 입력하세요: ");
                scanf("%d", &value);
                tail = insert_first(tail, value);
                break;
            case 2:
                printf("숫자를 입력하세요: ");
                scanf("%d", &value);
                tail = insert_last(tail, value);
                break;
            case 3:
                tail = delete_first(tail);
                break;
            case 4:
                tail = delete_last(tail);
                break;
            case 5:
                print_list(tail);
                break;
            case 6:
                printf("프로그램 종료.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}