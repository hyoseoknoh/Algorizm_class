#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode{
    element data;
    struct listNode* link;
}listNode;


listNode *insert_first(listNode *tail, element data){
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    if(tail == NULL){
        tail = node;
        node->link = tail;
    }
    else{
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

void print_list(listNode *tail){
    listNode *p;

    if(tail == NULL)    return ;
    p = tail->link;
    do
    {
        printf("[%2d]", p->data);
        p = p->link;
    } while (p != tail->link);   
}

listNode *insert_last(listNode* tail, element data){
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    if(tail == NULL){
        tail = node;
        node->link = node;
    }
    else{
        node->link = tail->link;
        tail->link = node;
        tail = node;
    }
    
}

int main(){
    listNode *tail = NULL;

    tail = insert_first(tail,30);
    tail = insert_first(tail,20);
    tail = insert_first(tail,10);
    print_list(tail);
    printf("\n");
    tail = insert_last(tail,40);
    tail = insert_last(tail,50);
    tail = insert_last(tail,60);
    print_list(tail);
    
}