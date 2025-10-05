/*
Write a recursive function to general Fibonacci series.
*/

#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int noOfTerms = 10;
    
    printf("Fibonacci series up to %d terms:\n", noOfTerms);
    for (int i = 0; i < noOfTerms; i++) {
        printf("%d ", fib(i));
    }

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}