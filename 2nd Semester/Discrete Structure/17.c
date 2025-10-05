// Programs to implement Chinese Remainder Theorem.
#include <stdio.h>

// Function to find the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 0)
            return x;
    }
    return 1;
}

// Function to find the smallest x such that:
// x % num[i] = rem[i] for all i
int findMinX(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num) / sizeof(num[0]);
    printf("x is %d\n", findMinX(num, rem, k));

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}
