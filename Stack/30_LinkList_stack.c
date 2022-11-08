// Implementing all the Stack Operations using Linked List (With Code in C)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
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

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top; // Yaha hamesha yad rakh ki hum return top Kar raha hai, top jo ki 1 struct Node ka datatype hai to fuction ke pehele struct Node* lagega
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

/*
// Ye mera kiya hua pop ka fuction hai jo ki thoda easy hai :

int pop(struct stackNode *top)
{
    if (isempty(top))
    {
        printf("The stack is empty now!!!\n");
    }
    else
    {
        int data;
        struct stackNode *ptr;
        data = top->data;

        ptr = top;
        top = top->next;
        free(ptr);
        return data;
    }
}
*/

int main()
{
    struct Node *top = NULL;

    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);

    linkedListTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);

    return 0;
}
