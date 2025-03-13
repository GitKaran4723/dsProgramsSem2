#include <stdio.h>

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    int arr[] = {23, 1, 10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[1]);
    insertion(arr, n);
    printArray(arr, n);
}