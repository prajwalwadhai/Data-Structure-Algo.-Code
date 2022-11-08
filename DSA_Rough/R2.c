#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int ind_Insertion(int arr[], int size, int capacity, int element, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = (size - 1); i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {11, 12, 13, 14, 15};

    int size = 5;
    int capacity = 100;
    int element = 3;
    int index = 1;

    display(arr, size);
    ind_Insertion(arr, size, capacity, element, index);
    size = size + 1;
    display(arr, size);

    return 0;
}