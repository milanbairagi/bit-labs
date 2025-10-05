// Write a C program to demonstrate the floor and ceiling function

#include <stdio.h>
#include <math.h>

int main() {
    double num1 = 3.7;
    double num2 = -2.3;

    printf("Number: %.2f\n", num1);
    printf("Floor: %.2f\n", floor(num1));
    printf("Ceil: %.2f\n", ceil(num1));

    printf("\nNumber: %.2f\n", num2);
    printf("Floor: %.2f\n", floor(num2));
    printf("Ceil: %.2f\n", ceil(num2));

    printf("\n\nProrgrammed by Milan Bairai.");

    return 0;
}