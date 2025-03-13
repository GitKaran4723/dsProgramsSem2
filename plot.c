#include <stdio.h>

// Function to compute the sum of cubes of individual digits
int sum_of_digit_cubes(int n) {
    int sum = 0, digit;
    while (n > 0) {
        digit = n % 10;  // Extract last digit
        sum += digit * digit * digit;  // Cube and add
        n /= 10;  // Remove last digit
    }
    return sum;
}

int main() {
    int start = 369, end = 390;
    
    // Open file to store data
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data points to file
    for (int x = start; x < end; x++) {
        fprintf(file, "%d %d %d\n", x, x, sum_of_digit_cubes(x));
    }

    fclose(file); // Close file

    // Call GNUplot
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Error opening GNUplot!\n");
        return 1;
    }

    // GNUplot commands to visualize data
    fprintf(gnuplot, "set title 'Comparison of f(x) = x and Sum of Cubes of Digits'\n");
    fprintf(gnuplot, "set xlabel 'x values'\n");
    fprintf(gnuplot, "set ylabel 'Function values'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "plot 'data.txt' using 1:2 with linespoints title 'f(x) = x' lc rgb 'blue', \\\n");
    fprintf(gnuplot, "     'data.txt' using 1:3 with linespoints title 'Sum of Cubes of Digits' lc rgb 'red'\n");

    pclose(gnuplot);  // Close GNUplot

    return 0;
}
