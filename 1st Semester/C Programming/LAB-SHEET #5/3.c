/*
Write a program using for loop with a break statement to find the first prime number
between 1 and 100 and print it.
*/

#include <stdio.h>

int main() {
    printf("Prime numbers between 1 and 100: ");

    for (int i = 2; i <= 100; i++) {
        int isPrime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}