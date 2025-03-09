#include <stdio.h>

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {  // Copy characters until null terminator
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Append null character at the end
}

int main() {
    char source[100], destination[100];

    // Input the source string
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);  // Using gets() for simplicity (not recommended in real programs, use fgets instead)

    // Copy the string manually
    copyString(destination, source);

    // Print the copied string
    printf("Copied String: %s\n", destination);

    return 0;
}
