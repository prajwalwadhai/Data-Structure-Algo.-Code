// #41
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct Queue *q, int size)
{
    return (q->r == size - 1);
}

int isEmpty(struct Queue *q)
{
    return (q->r == q->f);
}

void Enqueue(struct Queue *q, int val)
{
    if (isfull(q, q->size))
    {
        printf("Queue is full now!!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty now!!!\n");
    }
    else
    {
        int a = -1;
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

int main()
{
    struct Queue *q;
    // struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = malloc(q->size *sizeof(int));

    Enqueue(q , 11);
    Enqueue(q , 12);
    Enqueue(q , 13);
    Enqueue(q , 14);
    Enqueue(q , 15);


    printf("The Dequeue value is %d\n" , Dequeue(q));
    printf("The Dequeue value is %d\n" , Dequeue(q));
    printf("The Dequeue value is %d\n" , Dequeue(q));
    printf("The Dequeue value is %d\n" , Dequeue(q));
    printf("The Dequeue value is %d\n" , Dequeue(q));
    printf("The Dequeue value is %d\n" , Dequeue(q));
    return 0;
}