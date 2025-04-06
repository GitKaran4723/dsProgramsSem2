#include <stdio.h> 
 
// Recursive function to find GCD of three numbers 
int gcd(int a, int b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
 
int main() { 
    int num1, num2, num3; 
    printf("Enter three numbers: "); 
    scanf("%d %d %d", &num1, &num2, &num3); 
    
    int result = gcd(num1, gcd(num2, num3)); 
    printf("GCD of %d, %d, and %d is: %d\n", num1, num2, num3, result); 
    
    return 0; 
}