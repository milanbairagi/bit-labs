/*
Write a program to input two integer numbers and
display the sum of even numbers between these two
input numbers.
*/

#include <stdio.h>

int main() {
    int num1, num2, sum;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // num1 is to be less than or equal to num2
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("Even Numbers (%d-%d): \n", num1, num2);
    sum = 0;
    for (int i = num1; i < num2; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            sum += i;
        }
    }

    printf("\nThe sum of even number is %d.", sum);

    printf("\n\nProgrammed by Milan Bairagi");


    return 0;
}