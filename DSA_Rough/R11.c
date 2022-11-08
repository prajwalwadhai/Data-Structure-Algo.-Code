#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkListTraversal(struct Node *top)
{
    while (top != NULL)
    {
        printf("%d\t", top->data);
        top = top->next;
    }
    printf("\n");
}
int isFull(struct Node *top)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *Push(struct Node *top, int value)
{
    if (isFull(top))
    {
        printf("The stack is Overflow\n");
    }

    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = value;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

int Pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("The stack is underflow\n");
    }
    else
    {
        struct Node *ptr = *top;
        *top = (*top)->next;
        int x = ptr->data;
        free(ptr);
        return x;
    }
}

int peek(struct Node **top, int index)
{
    struct Node *ptr = *top;
    for (int i = 0; (i < index - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct Node *top = NULL;
    top = Push(top, 11);
    top = Push(top, 22);
    top = Push(top, 33);
    top = Push(top, 44);

    // LinkListTraversal(top);

    // int element = Pop(&top);
    // printf("The value %d is popped\n", element);

    LinkListTraversal(top);

    for (int i = 1; i <= 4; i++)
    {
        printf("The %d element found at position %d\n", peek(&top, i), i);
    }

    return 0;
}