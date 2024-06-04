#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode *llink, *rlink;
} DListNode;

// 리스트 초기화 함수
void init(DListNode *phead) {
    phead->llink = phead->rlink = phead;
}

// 리스트의 특정 위치에 노드를 추가하는 함수
void dinsert(DListNode *before, element data) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// 리스트 처음에 노드를 추가하는 함수
void insert_first(DListNode *phead, element data) {
    dinsert(phead, data);
}

// 리스트 마지막에 노드를 추가하는 함수
void insert_last(DListNode *phead, element data) {
    dinsert(phead->llink, data);
}

// 리스트의 특정 위치에 노드를 삭제하는 함수
void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// 리스트 처음 노드를 삭제하는 함수
void delete_first(DListNode *phead) {
    if (phead->rlink != phead) {
        ddelete(phead, phead->rlink);
    } else {
        printf("리스트가 비어있습니다.\n");
    }
}

// 리스트 마지막 노드를 삭제하는 함수
void delete_last(DListNode *phead) {
    if (phead->rlink != phead) {
        ddelete(phead, phead->llink);
    } else {
        printf("리스트가 비어있습니다.\n");
    }
}

// 리스트를 출력하는 함수
void print_dlist(DListNode* phead) {
    DListNode* p;
    if (phead->rlink == phead) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("%d -> ", p->data);
    }
    printf("head\n");
}

int main() {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    int choice, data;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("3. 리스트 처음 노드 삭제\n");
        printf("4. 리스트 마지막 노드 삭제\n");
        printf("5. 리스트 프린트\n");
        printf("6. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 숫자를 입력하세요: ");
                scanf("%d", &data);
                insert_first(head, data);
                break;
            case 2:
                printf("추가할 숫자를 입력하세요: ");
                scanf("%d", &data);
                insert_last(head, data);
                break;
            case 3:
                delete_first(head);
                break;
            case 4:
                delete_last(head);
                break;
            case 5:
                print_dlist(head);
                break;
            case 6:
                printf("프로그램 종료.\n");
                // 동적 할당된 메모리 해제
                while (head->rlink != head) {
                    delete_first(head);
                }
                free(head);
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                break;
        }
    }
    return 0;
}