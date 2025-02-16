#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swaps occurred, the array is already sorted
        if (swapped == 0)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    
    // Taking input for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Taking input for array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array using Bubble Sort
    bubbleSort(arr, n);
    
    // Displaying the sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
