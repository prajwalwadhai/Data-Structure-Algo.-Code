#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct Queue *q)
{
    return (q->r == q->size);
}

int isEmpty(struct Queue *q)
{
    return (q->r == q->f);
}

void enqueueR(struct Queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue is full now !!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

void enqueueF(struct Queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue is full now !!!\n");
    }
    else
    {
        if (q->f == -1)
        {
            printf("enqueinf is not possible at front try of Rare side\n");
        }
        else
        {
            q->f--;
            q->arr[q->f] = val;
        }
    }
}

int dequeueF(struct Queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty now !!!\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int dequeueR(struct Queue *q)
{
    int val = -1;
    if (isfull(q))
    {
        printf("Queue is full now !!!\n");
    }
    else
    {
        val = q->arr[q->r];
        q->r--;
    }
    return val;
}

int main()
{
    struct Queue *q;
    q->size = 10;
    q->f = q->r = -1;
    q->arr = malloc(sizeof(int));

    enqueueR(q, 11);
    printf("%d\n", dequeueR(q));

    return 0;
}