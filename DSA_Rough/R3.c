#include <stdio.h>

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int delition(int arr[], int size, int capacity, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // arr[index] = element;
}

int main()
{
    int arr[100] = {11, 12, 13, 14, 15};

    int size = 5;
    int capacity = 100;
    int element = 2;
    int index = 2;

    print(arr, size);
    delition(arr, size, capacity, index);
    size -= 1;
    print(arr, size);

    return 0;
}