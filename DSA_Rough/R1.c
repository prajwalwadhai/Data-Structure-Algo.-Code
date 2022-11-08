#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int ind_Insertion(int arr[], int size, int capacity, int element, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
}

int main()
{
    int arr[100] = {11, 12, 13, 14, 15};

    int size = 5;
    int capacity = 100;
    int element = 33;
    int index = 1;

    // display(arr, size);
    ind_Insertion(arr, size, capacity, element, index);

    return 0;
}