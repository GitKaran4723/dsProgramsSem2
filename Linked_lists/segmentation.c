#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int hello = 0;
    int hello1 = 0;

    // Correct way to print address
    printf("%p \n", (void *)&arr[0]);  // Print address of the first element
    printf("%d \n", &arr[0]);  // Print address of the first element
    printf("%p \n", (void *)arr);      // Print base address of array
    printf("%d \n", arr);      // Print base address of array

    // Correct way to print array elements
    printf("Array Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
