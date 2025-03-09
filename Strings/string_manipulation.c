#include <stdio.h>
#include <string.h>

int main() {
    // Define the strings
    char S1[] = "Flowers";
    char S2[] = "are beautiful";
    char concatenated[50]; // Buffer for concatenation

    // I. Find the length of S1
    printf("Length of S1: %lu\n", strlen(S1));

    // II. Concatenate S1 and S2
    strcpy(concatenated, S1);  // Copy S1 to concatenated
    strcat(concatenated, " "); // Add space for readability
    strcat(concatenated, S2);  // Append S2
    printf("Concatenated String: %s\n", concatenated);

    // III. Extract the substring "low" from S1
    char substring[4]; // "low" + null terminator
    strncpy(substring, S1 + 1, 3); // Copy from index 1 to 3 characters
    substring[3] = '\0'; // Null terminate the string
    printf("Extracted substring: %s\n", substring);

    // IV. Replace "are" with "is" in S2
    char modifiedS2[50]; // Buffer for modified string
    if (strncmp(S2, "are", 3) == 0) { // Check if S2 starts with "are"
        strcpy(modifiedS2, "is");
        strcat(modifiedS2, S2 + 3); // Append the rest of S2 after "are"
    } else {
        strcpy(modifiedS2, S2); // No change
    }
    printf("Modified S2: %s\n", modifiedS2);

    return 0;
}

