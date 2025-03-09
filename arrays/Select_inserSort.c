#include <stdio.h>

// Function for Insertion Sort in Descending Order
void insertionSortDesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {  // Change condition for descending order
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function for Selection Sort in Descending Order
void selectionSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {  // Change condition for descending order
                maxIndex = j;
            }
        }
        // Swap elements
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
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
    int arr[] = {75, 8, 1, 16, 48, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform Insertion Sort
    int insertionArr[n];
    for (int i = 0; i < n; i++) insertionArr[i] = arr[i];  // Copy original array
    insertionSortDesc(insertionArr, n);
    printf("Insertion Sort (Descending): ");
    printArray(insertionArr, n);

    // Perform Selection Sort
    int selectionArr[n];
    for (int i = 0; i < n; i++) selectionArr[i] = arr[i];  // Copy original array
    selectionSortDesc(selectionArr, n);
    printf("Selection Sort (Descending): ");
    printArray(selectionArr, n);

    return 0;
}
