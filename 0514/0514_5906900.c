// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_LIST_SIZE 100

// typedef int element;
// typedef struct {
//     element array[MAX_LIST_SIZE];
//     int size;
// } ArrayListType;

// void init(ArrayListType* L) {
//     L->size = 0;
// }

// int is_empty(ArrayListType* L) {
//     return L->size == 0;
// }

// int is_full(ArrayListType* L) {
//     return L->size == MAX_LIST_SIZE;
// }

// void error(char* message) {
//     fprintf(stderr, "%s\n", message);
//     exit(1);
// }

// element get_entry(ArrayListType* L, int pos) {
//     if (pos < 0 || pos >= L->size) {
//         error("위치 오류");
//     }
//     return L->array[pos];
// }

// void print_list(ArrayListType* L) {
//     for (int i = 0; i < L->size; i++) {
//         printf("%d->", L->array[i]);
//     }
//     printf("NULL\n");
// }

// void insert_last(ArrayListType* L, element item) {
//     if (L->size >= MAX_LIST_SIZE) {
//         error("리스트 오버플로우");
//     }
//     L->array[L->size++] = item;
// }

// void insert(ArrayListType* L, int pos, element item) {
//     if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//         for (int i = (L->size - 1); i >= pos; i--) {
//             L->array[i + 1] = L->array[i];
//         }
//         L->array[pos] = item;
//         L->size++;
//     } else {
//         error("삽입 위치 오류");
//     }
// }

// element delete(ArrayListType* L, int pos) {
//     element item;

//     if (pos < 0 || pos >= L->size) {
//         error("위치 오류");
//     }
//     item = L->array[pos];
//     for (int i = pos; i < (L->size - 1); i++) {
//         L->array[i] = L->array[i + 1];
//     }
//     L->size--;
//     return item;
// }

// int main(void) {
//     ArrayListType list;

//     init(&list);

//     insert(&list, 0, 10); print_list(&list);
//     insert(&list, 0, 20); print_list(&list);
//     insert(&list, 0, 30); print_list(&list);

//     insert_last(&list, 40); print_list(&list);
//     delete(&list, 0); print_list(&list);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void init(ArrayListType* L) {
    L->size = 0;
}

int is_empty(ArrayListType* L) {
    return L->size == 0;
}

int is_full(ArrayListType* L) {
    return L->size == MAX_LIST_SIZE;
}

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void print_list(ArrayListType* L) {
    for (int i = 0; i < L->size; i++) {
        printf("%d -> ", L->array[i]);
    }
    printf("NULL\n");
}

void insert(ArrayListType* L, int pos, element item) {
    int move_count = 0;

    if (is_full(L)) {
        error("리스트 오버플로우");
    }
    if (pos < 0 || pos > L->size) {
        error("삽입 위치 오류");
    }
    for (int i = L->size - 1; i >= pos; i--) {
        L->array[i + 1] = L->array[i];
        move_count++;
    }
    L->array[pos] = item;
    L->size++;
    
    printf("삽입 시 데이터 이동 횟수: %d\n", move_count);
}

element delete(ArrayListType* L, int pos) {
    element item;
    int move_count = 0;

    if (is_empty(L)) {
        error("리스트 언더플로우");
    }
    if (pos < 0 || pos >= L->size) {
        error("삭제 위치 오류");
    }
    item = L->array[pos];
    for (int i = pos; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
        move_count++;
    }
    L->size--;

    printf("삭제 시 데이터 이동 횟수: %d\n", move_count);

    return item;
}

int main(void) {
    ArrayListType list;
    int choice, position, value;

    init(&list);

    while (1) {
        printf("메뉴:\n");
        printf("1: 리스트에 추가\n");
        printf("2: 리스트에서 삭제\n");
        printf("3: 리스트 출력\n");
        printf("0: 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("추가할 값과 위치를 입력하세요: ");
                scanf("%d %d", &value, &position);
                insert(&list, position, value);
                break;
            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                delete(&list, position);
                break;
            case 3:
                print_list(&list);
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}