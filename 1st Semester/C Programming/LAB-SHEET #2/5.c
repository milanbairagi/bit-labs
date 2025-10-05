/*
Write a program to check odd or even number using 
(a) modulus operator 
(b) using bitwise operator 
(c) without using bitwise and modulus operator 
(d) using conditional operator.
*/

#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Using Modulus Operator, ");
    if (num % 2 == 0) {
        printf("%d is even.", num);
    } else {
        printf("%d is odd.", num);
    }

    printf("\nUsing Bitwise Operator, ");
    if (num & 1) {
        printf("%d is odd.", num);
    } else {
        printf("%d is even.", num);
    }

    printf("\nWithout using bitwise and modulus operator, ");
    if (num / 2 * 2 == num) {
        printf("%d is even.", num);
    } else {
        printf("%d is odd.", num);
    }

    printf("\nUsing Conditional Operator, ");
    (num % 2 == 0) ? printf("%d is even.", num) 
        : printf("%d is odd.", num);

    printf("\n\nProgrammed by Milan Bairagi");
    
    return 0;
}