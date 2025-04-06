#include <stdio.h> 
 
// Recursive function to solve Tower of Hanoi 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) { 
    if (n == 1) { 
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod); 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 
 
int main() { 
    int n; 
    printf("Enter number of disks: "); 
    scanf("%d", &n); 
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C are rod names 
    return 0; 
}