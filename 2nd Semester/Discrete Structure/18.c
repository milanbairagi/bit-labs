// Write a C program to generate permutations and combinations
#include <stdio.h>

// Function to calculate fac
int fac(int num) {
    if (num == 0)
        return 1;
    return num * fac(num - 1);
}

// Function to calculate permutation
int permutation(int n, int r) {
    return fac(n) / fac(n - r);
}

// Function to calculate combination
int combination(int n, int r) {
    return fac(n) / (fac(n - r) * fac(r));
}

// Driver code
int main() {
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);
    printf("Permutation = %d\n", permutation(n, r));
    printf("Combination = %d\n", combination(n, r));

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
