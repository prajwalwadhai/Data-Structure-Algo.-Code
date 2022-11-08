// Doubly Linked Lists Explained With Code in C Language #21

// ye mene create kiya hua code hai kiv ki code HW diya hai

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *Doubly_LinkList_Traversal_From_first(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
   
}

struct Node *Doubly_LinkList_Traversal_From_last(struct Node *fourth)
{
    struct Node *p = fourth;
    while(p != NULL)
    {
        printf("%d\t" , p->data);
        p = p->prev;
    }
    printf("\n");
}



int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second= (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->prev = NULL;
    head->next = second;

    second->data = 22;
    second->prev = head;
    second->next = third;

    third->data = 33;
    third->prev = second;
    third->next = fourth;

    fourth->data = 44;
    fourth->prev = third;
    fourth->next = NULL;

    Doubly_LinkList_Traversal_From_first(head);
    Doubly_LinkList_Traversal_From_last(fourth);

    return 0;
}