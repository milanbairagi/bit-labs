/*
Write a program to display Fibonacci series of last term up to 300.
*/

#include <stdio.h>

int main() {
    int t1, t2, nextTerm;
    t1 = 0;
    t2 = 1;
    printf("Fibonacci Series: %d %d ", t1, t2);

    nextTerm = t1 + t2;
    while (nextTerm <= 300) {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    
    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}