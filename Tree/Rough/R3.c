#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creatnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void PreOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d\t", root->data);
        InOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d\t", root->data);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *Search(struct node *root, int key)
{
    if (key == root->data)
    {
        return root;
    }
    if (key < root->data)
    {
        return Search(root->left, key);
    }
    if (key > root->data)
    {
        return Search(root->right, key);
    }
}

struct node *SearchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        if (key < root->data)
        {
            root = root->left;
        }
        if (key > root->data)
        {
            root = root->right;
        }
    }
}

int main()
{
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    struct node *p = creatnode(5);
    struct node *p1 = creatnode(3);
    struct node *p2 = creatnode(6);
    struct node *p3 = creatnode(1);
    struct node *p4 = creatnode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // PreOrderTraversal(p);
    // printf("\n");
    // InOrderTraversal(p);
    // printf("\n");
    // PostOrderTraversal(p);
    // printf("\n");

    // printf("%d", isBST(p));

    struct node *n = Search(p, 7);

    if (n != NULL)
    {
        printf("%d Element is found", n->data);
    }
    else
    {
        printf("%d Element is Not found", n->data);
    }
    
    return 0;
}