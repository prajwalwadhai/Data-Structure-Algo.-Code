#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{ 
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void Push(struct stack *sp, int value)
{
    if (isFull(sp))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

char Pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("The stack is Underflow\n");
        return -1;
    }
    else
    {
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

int isoperator(char Infix)
{
    if (Infix == '*' || Infix == '/' || Infix == '+' || Infix == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int OperatorPrecidence(char Infix)
{
    if (Infix == '*' || Infix == '/')
    {
        return 3;
    }
    else if (Infix == '+' || Infix == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

char InfixtoPrefix(char *Infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *Postfix = (char *)malloc((strlen(Infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (Infix[i] != '\0')
    {
        if (!isoperator(Infix[i]))
        {
            Postfix[j] = Infix[i];
            i++;
            j++;
        }
        else
        {
            if (OperatorPrecidence(Infix[i]) > OperatorPrecidence(stackTop(sp)))
            {
                Push(sp, Infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = Pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        Postfix[j] = Pop(sp);
        j++;
    }
    Postfix[j] = '\0';
    return Postfix;
}

int main()
{
    char *Infix = "a+b*c";

    printf("postfix is %s\n", InfixtoPrefix(Infix));

    return 0;
}