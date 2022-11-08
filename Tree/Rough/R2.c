#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creatTree(int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void PreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\t", root->data);
    }
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d\t", root->data);
        InOrder(root->right);
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

struct node *SearchinBST(struct node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        return root;
    }

    else if (root->data > val)
    {
        return (SearchinBST(root->left, val));
    }
    else
    {
        return (SearchinBST(root->right, val));
    }
}

struct node *SearchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == key)
        {
            return root;
        }

        else if (root->data > key)
        {
            root = root->left;
        }

        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void Insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("The %d element already present in tree you can not inset again\n", key);
            return;
        }

        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = creatTree(key);
    if (key < prev->data)
    {
        // creatTree(key);
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct node *p = creatTree(5);
    struct node *p1 = creatTree(3);
    struct node *p2 = creatTree(6);
    struct node *p3 = creatTree(1);
    struct node *p4 = creatTree(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // PreOrder(p);
    // printf("\n");
    // PostOrder(p);
    // printf("\n");
    // InOrder(p);
    // printf("\n");
    // printf("%d" , isBST(p));

    // struct node *n = SearchinBST(p, 7);
    // if (n != NULL)
    // {
    //     printf("The %d Element is found\n", n->data);
    // }
    // else
    // {
    //     printf("The given element is not found\n");
    // }

    // printf("%d" , SearchinBST(p , 5));

    // struct node *n = SearchIter(p , 9);
    // if(n == NULL)
    // {
    //     printf("Your given element is not fount in this tree\n");
    // }
    // else
    // {
    //     printf("Your %d element is found\n" , n->data);
    // }

    Insert(p, 7);
    printf("Your %d Element is inserted sucessfully", p->right->right->data);

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    return 0;
}