#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *ptr, char exp)
{
    ptr->top++;
    ptr->arr[ptr->top] = exp;
}

char pop(struct stack *ptr)
{
    // struct stack *temp = ptr;
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    // char exp[] = "7-(8(3*4)+11+12))8)";
    char exp[] = "3*2-(8+5)";
    // sp->arr="3*2-(8+5)";
    sp->size = strlen(exp);
    sp->top = -1;

    for (int i = 0; i < strlen(exp); i++)
    {
        printf("%c", exp[i]);
        if (exp[i] == '(')
        {
            push(sp,'(');
        }
        if (exp[i] == ')')
        {
            pop(sp);
        }
    }

    if(sp->top == -1)
    {
        printf("\nThis expression is valid\n");
    }
    else
    {
        printf("\nYour given expression is Not valid\n");
    }
    return 0;
}