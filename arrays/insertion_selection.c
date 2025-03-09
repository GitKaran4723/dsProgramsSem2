#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {  // Sorting in descending order
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {  // Sorting in descending order
                max_idx = j;
            }
        }
        // Swap
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {75, 8, 1, 16, 48, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int insertionSorted[n], selectionSorted[n];

    // Copy original array for both sorting methods
    for (int i = 0; i < n; i++) {
        insertionSorted[i] = arr[i];
        selectionSorted[i] = arr[i];
    }

    // Perform Insertion Sort
    insertionSort(insertionSorted, n);
    printf("Insertion Sort (Descending): ");
    printArray(insertionSorted, n);

    // Perform Selection Sort
    selectionSort(selectionSorted, n);
    printf("Selection Sort (Descending): ");
    printArray(selectionSorted, n);

    return 0;
}
