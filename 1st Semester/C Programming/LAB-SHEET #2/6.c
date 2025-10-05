/*
5. Write a program that declares variables of different
data types (int, float, char etc.) and prints their sizes
using the size of operator.
*/

#include <stdio.h>

int main() {

    int integerVar;
    float floatVar;
    double doubleVar;
    char charVar;

    printf("Size of int: %d bytes\n", sizeof(integerVar));
    printf("Size of float: %d bytes\n", sizeof(floatVar));
    printf("Size of double: %d bytes\n", sizeof(doubleVar));
    printf("Size of char: %d bytes\n", sizeof(charVar));

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}