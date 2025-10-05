/*
Write a program that defines a variable and then increments 
and decreents the value of the variable useing the 
++(increment) and --(decrement) operators. Print the value of 
the variable after each operation to the console.
*/

#include <stdio.h>

int main() {
    int var = 5;
    printf("Original Value: %d\n", var);

    var++;
    printf("After increment: %d\n", var);

    var--;
    printf("After decrement: %d\n", var);

    printf("\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}