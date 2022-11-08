// #44
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

int isEmpty(struct queue *q)
{
    return (q->r == q->f);
}

void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue is Full now !!!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty now !!!\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct queue *q;
    q->size = 10;
    q->f = q->r = -1;
    q->arr = malloc(q->size * sizeof(int));

    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
        enqueue(q, 16);
    enqueue(q, 17);
    enqueue(q, 18);
    enqueue(q, 19);
    enqueue(q, 20);

    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));

    enqueue(q, 21);
    enqueue(q, 22);
    enqueue(q, 23);

    printf("The Dequeue is : %d\n" , dequeue(q));
    printf("The Dequeue is : %d\n" , dequeue(q));

    



    return 0;
}