/*
4. Write a program to swap two variables values with and without using 
third variable.
*/

#include <stdio.h>

int main() {
    int a = 10, b = 5;

    printf("Values Before Swapping:\n");
    printf("a = %d, b = %d", a, b);

    // Swap with third variable
    int temp = a;
    a = b;
    b = temp;

    printf("\n\nSwap using third variable:\n");
    printf("a = %d, b = %d", a, b);

    // Swap without third variable
    int x = 2, y = 3;
    printf("\nValues Before Swapping: \n");
    printf("x = %d, y = %d", x, y);

    x = x + y;
    y = x - y;
    x = x - y;

    printf("\n\nSwap without using third variable: \n");
    printf("x = %d, y = %d", x , y);

    printf("\n\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}