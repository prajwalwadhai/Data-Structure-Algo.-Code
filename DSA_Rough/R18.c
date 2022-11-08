#include <stdio.h>

void arrayTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void InsertSorting(int arr[], int n)
{
    for (int i = 0; i < n -1; i++)
    {
        int key = arr[i+1];
        int j = i;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key ;
    }
}

int main()
{
    int n;
    int arr[] = {7, 12, 3, 4, 1};
    n = 5;

    arrayTraversal(arr, n);
    InsertSorting(arr, n);
    arrayTraversal(arr, n);

    return 0;
}