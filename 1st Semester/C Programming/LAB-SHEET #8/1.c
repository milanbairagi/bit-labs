/*
Write a program to swap value of two variables using pointer.
*/

#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}