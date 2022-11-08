#include <stdio.h>

void arrayTraversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// void BubbleSort(int arr[], int size)
// {
//     int temp;
//     int adaptive;
//     for (int i = 0; i < size - 1; i++)
//     {
//         printf("Working on pass number %d\n", i + 1);
//         adaptive = 1;
//         for (int j = 0; j < size - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 adaptive = 0;
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//         if (adaptive)
//         {
//             return;
//         }
//     }
// }

// void insertionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int j = i;
//         int key = i + 1;
//         while (j >= 0 && arr[j] > arr[key])
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// void SelectionSort(int arr[], int n)
// {
//     int indexofMin;
//     for (int i = 0; i < n - 1; i++)
//     {
//         indexofMin = i;
//         for (int j = i + 1; j < n ; j++)
//         {
//             if (arr[indexofMin] > arr[j])
//             {
//                 indexofMin = j;
//             }
//         }
//         int temp = arr[indexofMin];
//         arr[indexofMin] = arr[i];
//         arr[i] = temp;
//         // int temp = arr[i];
//         // arr[i] = arr[indexofMin];
//         // arr[indexofMin] = temp;
//     }
// }

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int left = low + 1;
//     int right = high;
//     int temp;
//     do
//     {
//         while (arr[left] <= pivot)
//         {
//             left++;
//         }
//         while (arr[right] > pivot)
//         {
//             right--;
//         }

//         if (left < right)
//         {
//             temp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = temp;
//         }
//     } while (left < right);

//     temp = arr[low];
//     arr[low] = arr[right];
//     arr[right] = temp;
//     return right;
// }

// void quickSort(int arr[], int low, int high)
// {
//     int pivot;
//     if (low < high)
//     {
//         pivot = partition(arr, low, high);
//         quickSort(arr, low, pivot - 1);
//         quickSort(arr, pivot + 1, high);
//     }
// }

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        i++, k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++, k++;
    }
    for(int i =low ; i<=high ; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {6, 8, 4, 3, 2, 7};
    // int arr[] = {1, 2, 3, 4, 6, 5};
    int size = sizeof(arr) / sizeof(int);

    arrayTraversal(arr, size);
    // BubbleSort(arr, size);
    // insertionSort(arr, size);
    // SelectionSort(arr, size);
    // quickSort(arr, 0, size - 1);
    mergeSort(arr, 0, size - 1);
    arrayTraversal(arr, size);

    return 0;
}

