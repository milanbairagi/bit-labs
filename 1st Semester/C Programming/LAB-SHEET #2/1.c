/*
1. Write a program to prompt the user to input 3 integer values and 
print these values in forward and reversed order.
*/

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("Forward Order: %d, %d, %d\n", a, b, c);
    printf("Reversed Order: %d, %d, %d\n", c, b, a);

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}