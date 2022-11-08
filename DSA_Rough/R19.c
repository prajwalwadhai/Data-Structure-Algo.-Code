#include <stdio.h>

void arrayTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int indexofMin = i;
        for (int j = i+1; j < n ; j++)
        {
            if (arr[j] < arr[indexofMin])
            {
                indexofMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexofMin];
        arr[indexofMin] = temp;
    }
}

int main()
{
    int arr[] = {8, 0, 7, 1, 3};
    int n = 5;

    arrayTraversal(arr, n);
    selectionSort(arr, n);
    arrayTraversal(arr, n);

    return 0;
}