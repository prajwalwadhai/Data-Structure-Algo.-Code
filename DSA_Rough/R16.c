// #46
// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// int isfull(struct Node *q)
// {
//     struct Node *n = malloc(sizeof(struct Node));
//     return (n->next == NULL);
// }

// int isEmpty(struct Node *q)
// {
//     return (q->next == NULL);
// }

// struct Node *enqueue(struct Node *q, int val)
// {
//     struct Node *ptr = malloc(sizeof(struct Node));
//     if (isfull(q))
//     {
//         printf("Queue is full now !!!\n");
//         // return -1;
//     }

//     else
//     {
//         ptr->data = val;
//         ptr->next = NULL;
//         if(q == NULL)
//         {
//             q->f =q->r =ptr;
//         }
//         else 
//         {
//             q->r = n;
//         }
//         q->next = ptr;
//         q->r = ptr->data;

//         return ptr;
//     }
// }

// int main()
// {
//     struct Node *f  = NULL ;
//     struct Node *r  = NULL ;
   

//     printf("The queue is full  %d\n", isfull(q));
//     printf("The queue is empty %d\n", isEmpty(q));

//     // enqueue(q , 77);
//     printf("%d\n", enqueue(q, 77));

//     return 0;
// }