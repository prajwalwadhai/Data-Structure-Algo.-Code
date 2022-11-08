// #26
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *stk)
{
    if (stk->top == stk->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct stack *stk)
{
    if (stk->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack *stk, int value)
{
    if (isFull(stk))
    {
        printf("Stack is overflow\n");
        // return 1;
    }
    else
    {
        // for push operation

        stk->top++;
        stk->arr[stk->top] = value;
        // printf("%d\n" , stk->arr[stk->top]);
        // return value;
    }
}

int Pop(struct stack *stk)
{
    if (isEmpty(stk))
    {
        printf("The stack is underflow\n");
        return -1;
    }
    else
    {
        int ptr = stk->arr[stk->top];
        stk->top--;
        return ptr;
    }
}

int main()
{
    int value;
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 100;
    stk->top = -1;
    stk->arr = (int *)malloc(stk->size * sizeof(int));
    // stk->arr[0] = 11;
    // stk->arr[1] = 22;
    // printf("Enter the value you want to push in stack\n");
    // scanf("%d", &value);

    Push(stk, 33);
    Push(stk, 33);
    Push(stk, 33);
    Push(stk, 334);
    Push(stk, 998);
    Push(stk, 3);
    // Pop(stk);
    printf("The %d value is pop\n", Pop(stk));

    printf("after puhing in the stack stackfull : %d\n", isFull(stk));
    printf("after puhing in the stack stackEmpty : %d\n", isEmpty(stk));

    return 0;
}