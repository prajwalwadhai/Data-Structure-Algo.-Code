// Linear and Binaary searching in DSA
#include <stdio.h>

int LinearSearching(int arr[], int size, int element)
{
    printf("We are in LinearSearching\n");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearching(int arr[], int size, int element)
{
    printf("We are in Binary Searching \n");
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] <= element)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66};
    int size = sizeof(arr) / sizeof(int);
    int element = 44;
    int SearchIndexLinear;
    SearchIndexLinear = LinearSearching(arr, size, element);
    printf("The element %d is found at index %d\n\n", element, SearchIndexLinear);

    int SearchIndexBinary;
    SearchIndexBinary = BinarySearching(arr, size, element);
    printf("The element %d is found at index %d\n", element, SearchIndexBinary);

    return 0;
}