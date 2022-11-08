#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *LinkList_Traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

// struct Node *DeleteFirst(struct Node *head)
// {
//     struct Node *ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }

// struct Node *DeleteBetween(struct Node *head, int index)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     for (int i = 0; i < index - 1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
//     return head;
// }

// struct Node *DeleteLast(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
//     return head;
// }

struct Node *DeleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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
    forth->next = NULL;

    printf("Link List Before Operation :\n");
    LinkList_Traversal(head);

    // head = DeleteFirst(head);
    // head = DeleteBetween(head, 2);
    // head = DeleteLast(head);
    head = DeleteAtValue(head, 33);

    printf("\nLink List After Operation :\n");
    LinkList_Traversal(head);
    return 0;
}