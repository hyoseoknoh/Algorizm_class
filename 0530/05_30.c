#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode
{
    element data;
    struct listNode *link;
} ListNode;

ListNode *insert_first(ListNode *tail, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL)
    {
        tail = node;
        node->link = tail;
    }
    else
    {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

void print_list(ListNode *tail)
{
    ListNode *p;

    if (tail == NULL)
        return;
    p = tail->link;
    do
    {
        printf("[%2d] ", p->data);
        p = p->link;
    } while (p != tail->link);
}

ListNode *insert_last(ListNode *tail, element data)
{

    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // <1>
    node->data = data;                                     // <2>

    if (tail == NULL)
    {
        tail = node;
        node->link = node;
    }
    else
    {
        node->link = tail->link; //<3>
        tail->link = node;       //<4>
        tail = node;             //<5>
    }
    return tail; //<5>
}

ListNode *delete_first(ListNode *tp, element *pop_data)
{
    ListNode *fp;

    if (tp == NULL)
    {
        fprintf(stderr,"스택이 비어있음\n");
        exit(1);
    }
    else
    {
        fp = tp->link;
        tp->link = fp->link;
        *pop_data = fp->data;
        if (tp == fp)
        {
            free(fp);
        }
        else
        {
            
            return tp;
        }
    }
}

main()
{
    ListNode *tail = NULL;

    tail = insert_first(tail, 10);
    tail = insert_first(tail, 20);
    tail = insert_first(tail, 30);
    // print_list(tail);

    // tail = insert_last(tail, 40);
    // tail = insert_last(tail, 50);
    // tail = insert_last(tail, 60);
    print_list(tail);

    element pop_data;

    tail = delete_first(tail, &pop_data);
}