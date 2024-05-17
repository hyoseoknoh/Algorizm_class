#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode *link;
} ListNode;

// 리스트의 첫 번째 위치에 노드 삽입
ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 리스트의 특정 위치에 노드 삽입
ListNode* insert(ListNode *head, int position, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;

    if (position == 0) {
        p->link = head;
        head = p;
        printf("이동 횟수: 0\n");
        return head;
    }

    ListNode *pre = head;
    int count = 0;
    while (count < position - 1 && pre != NULL) {
        pre = pre->link;
        count++;
    }

    if (pre == NULL) {
        printf("삽입 위치가 리스트의 범위를 벗어났습니다.\n");
        free(p);
        return head;
    }

    p->link = pre->link;
    pre->link = p;
    printf("이동 횟수: %d\n", count + 1);
    return head;
}

// 리스트의 첫 번째 노드 삭제
int delete_first(ListNode **head) {
    ListNode *removed;
    if (*head == NULL) return 0;
    removed = *head;
    *head = removed->link;
    free(removed);
    return 0;
}

// 리스트의 특정 위치의 노드 삭제
int delete(ListNode **head, int position) {
    if (*head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return -1;
    }

    if (position == 0) {
        int moves = delete_first(head);
        printf("이동 횟수: %d\n", moves);
        return 0;
    }

    ListNode *pre = *head;
    int count = 0;
    while (count < position - 1 && pre->link != NULL) {
        pre = pre->link;
        count++;
    }

    if (pre->link == NULL) {
        printf("삭제 위치가 리스트의 범위를 벗어났습니다.\n");
        return -1;
    }

    ListNode *removed = pre->link;
    pre->link = removed->link;
    free(removed);
    printf("이동 횟수: %d\n", count + 1);
    return count + 1;
}

// 리스트 출력
void print_list(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main(void) {
    ListNode *head = NULL;
    int choice, value, position;

    do {
        printf("\n메뉴:\n");
        printf("(1) 리스트에 추가\n");
        printf("(2) 리스트에서 삭제\n");
        printf("(3) 리스트 출력\n");
        printf("(0) 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 숫자를 입력하세요 : ");
                scanf("%d", &value);
                printf("삽입할 위치를 입력하세요 : ");
                scanf("%d", &position);
                head = insert(head, position, value);
                break;
            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                delete(&head, position);
                break;
            case 3:
                print_list(head);
                break;
            case 0:
                printf("프로그램 종료.\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}