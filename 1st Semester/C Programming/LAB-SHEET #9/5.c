/*
Write a program that creates a pointer to an integer
variable and prints its value to the console. Use the *
operator to declare the pointer.
*/

#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Value of the pointer is %d.", ptr);

    printf("\n\nProgrammed by Milan Bairagi");
}