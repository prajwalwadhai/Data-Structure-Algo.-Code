// #20
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *LinkList_Traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    // printf("%d\t" , ptr->data);
}

// struct Node *InsertFirst(struct Node *head, int value)
// {
//     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = value ;
//     struct Node * p = head ->next;
//     while(p->next != head)
//     {
//         p = p->next ;
//     }
//     p ->next = ptr ;
//     ptr->next = head ;
//     head = ptr ;
//     return head;
// }

// struct Node *InsertBetween(struct Node *head, int index, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;
//     for (int i = 0; i != index - 1; i++)
//     {
//         p = p->next;
//     }
//     ptr->next = p->next ;
//     p->next = ptr ;
//     return head ;

// }

struct Node *InsertLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next= ptr ;
    return head ; 
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = forth;

    forth->data = 44;
    forth->next = head;

    printf("Link list traversal Before operation \n");
    LinkList_Traversal(head);

    // head = InsertFirst(head, 89);
    // head = InsertBetween(head , 2 , 58);
    head = InsertLast(head, 34);

    printf("\nLink list traversal After operation \n");
    LinkList_Traversal(head);

    return 0;
}