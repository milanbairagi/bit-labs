// Write a program to compute a^n an using recursion
#include <stdio.h>

// Function to compute a^n using recursion
int power(int a, int n) {
    // Base case: a^0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: a^n = a * a^(n-1)
    return a * power(a, n - 1);
}

int main() {
    int a, n;
    
    // Input base and exponent from the user
    printf("Enter the base (a): ");
    scanf("%d", &a);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);
    
    // Compute a^n using the recursive function
    int result = power(a, n);
    
    // Print the result
    printf("%d^%d = %d\n", a, n, result);

    printf("\nProgrammed by Milan Bairagi");
    
    return 0;
}