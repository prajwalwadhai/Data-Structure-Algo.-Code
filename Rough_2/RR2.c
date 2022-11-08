#include <stdio.h>
#include <malloc.h>

struct node
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct node *q)
{
    return q->f == q->r;
}
int isFull(struct node *q)
{
    return q->r == q->size - 1;
}

void Enqueue(struct node *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full Now!!!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
    }
}

int Dequeue(struct node *q)
{
    int data = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty now!!!");
    }
    else
    {
        q->f++;
        data = q->arr[q->f];
    }
    return data;
}

int main()
{
    struct node *q;
    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // Staring our Graph Traversal
    int node;
    int i = 9;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int arr[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d", i);
    visited[i] = 1;
    Enqueue(q, i);

    while (!isEmpty(q))
    {
        node = Dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (arr[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                Enqueue(q, j);
            }
        }
    }

    return 0;
}