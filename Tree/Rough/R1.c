#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creatNode(int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    struct node *p = creatNode(2);
    struct node *p2 = creatNode(1);
    struct node *p3 = creatNode(4);

    p->left = p2;
    p->right = p2;

    printf("%d\n"  , p->data);
    printf("%d\n"  , p2->data);
    printf("%d\n"  , p3->data);

    return 0;
}
