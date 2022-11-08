#include <stdio.h>

void printarray(int A[], int B[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }

    printf("\n");
    for (int j = 0; j < m; j++)
    {
        printf("%d\t", B[j]);
    }
    printf("\n");
}

void mergSorting(int A[], int B[], int C[], int m, int n, int o)
{
    printf("kfhahdhsdf\n");
    int i, j, k;
    i = j = k = 0;
    // int C[8];

    while (i < n && j < m)
    {

        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++, k++;
        }
        else
        {
            C[k] = B[j];
            j++, k++;
        }
    }

    while (i < n)
    {
        C[k] = A[i];
        i++, k++;
    }

    while (j < m)
    {
        C[k] = B[j];
        i++, k++;
    }

    printf("The new merg sorted array is\n");
    for (int z = 0; z < k; z++)
    {
        printf("%d\t", C[z]);
    }
    // printf("\n");
}

int main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {5, 6, 7, 8};

    int m = 4;
    int n = 4;
    int o = 8;
    int C[o];

    printarray(A, B, n, m);
    mergSorting(A, B, C, m, n, o);
    return 0;
}