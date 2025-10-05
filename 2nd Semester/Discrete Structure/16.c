#include <stdio.h>

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y) {
    // Base case: if b is 0, then GCD is a, and x = 1, y = 0
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1; // Coefficients for recursive call
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    // Update x and y using the results of the recursive call
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}


int main() {
    int a, b, s, t;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extendedGCD(a, b, &s, &t);

    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients s and t are %d and %d respectively\n", s, t);
    printf("Linear combination: %d*%d + %d*%d = %d\n", a, s, b, t, gcd);

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
