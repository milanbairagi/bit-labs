/*
Write a program that creates a one-dimensional array of 5 integers. 
Assign value to each element of an array and print them to the console.
*/

#include <stdio.h>

int main() {
    int arr[5];

    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 8;
    arr[4] = 9;

    // print arr array elements
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}