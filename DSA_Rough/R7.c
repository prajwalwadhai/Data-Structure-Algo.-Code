#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Link_List_Traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

// struct Node *DeleteAtFirst(struct Node *head)
// {
//     struct Node *ptr;
//     ptr = head;

//     // ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }

struct Node DeleteInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    // return p;
}

// struct Node *DeleteAtEnd(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = (struct node *)malloc(sizeof(struct Node));
//     int i = 0;
//     while (p != NULL)
//     {
//         p = p->next;
//     }
//     q->next = NULL;
//     p->next = q->next;
//     free(p);
// }

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = NULL;

    printf("Before the Operation :\n");
    Link_List_Traversal(head);

    // head = DeleteAtFirst(head);
    DeleteInBetween(head, 1);
    // DeleteAtEnd(head);

    printf("After the operation :\n");
    Link_List_Traversal(head);

    return 0;
}