/*
Define a function named fact() to calculate factorial of a number n and then 
write a program that uses this function fact() to calculate combination and
permutation.
*/

#include <stdio.h>

int fact(int n) {
    if (n <= 1) {
        return n;
    }
    return n * fact(n - 1);
}

int permutation(int n, int r) {
    return fact(n) / fact(n - r);
}

int combination(int n, int r) {
    return fact(n) / (fact(n - r) * fact(r));
}

int main() {
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    printf("Permutation: %d\n", permutation(n, r));
    printf("Combination: %d\n", combination(n, r));

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}