#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Linklist_Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *Head;
    struct Node *Second;
    struct Node *SecondThird;
    struct Node *Third;
    struct Node *fourth;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Second = (struct Node *)malloc(sizeof(struct Node));
    SecondThird = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    Head->data = 66;
    Head->next = Second;

    Second->data = 77;
    Second->next = SecondThird;

    SecondThird->data = 88;
    SecondThird->next = Third;

    Third->data = 0;
    Third->next = fourth;

    fourth->data = 99;
    fourth->next = NULL;

    Linklist_Traversal(Head);

    return 0;
}