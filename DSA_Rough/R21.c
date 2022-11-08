#include <stdio.h>

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int R[100];
    while (i < mid && j < high)
    {
        if (arr[i] < arr[j])
        {
            R[k] = arr[i];
            i++, k++;
        }
        else
        {
            R[k] = arr[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        R[k] = arr[i];
        i++, j++;
    }
    while (j <= high)
    {
        R[k] = arr[j];
        j++, k++;
    }
    for (int i = 0; i < high; i++)
    {
        R[k] = arr[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, high);
        mergeSort(arr, mid + 1, high);
        sort(arr, low, mid, high);
    }
}

int main()
{
    // int arr[] = {2, 4, 6, 9, 11};
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int size = 7;

    printarray(arr, size);
    mergeSort(arr, 0, 6);
    printarray(arr, size);

    return 0;
}