/*
Write a program using while loop to print the number from 10 to 1 to the console.
*/

#include <stdio.h>


int main() {
    int num = 10;

    while (num > 0) {
        printf("%d ", num);
        num--;
    }

    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}