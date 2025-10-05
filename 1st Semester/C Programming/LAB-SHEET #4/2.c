/*
2. Write a program to get input of two or higher digit integer number and 
display inverse order.
*/

#include <stdio.h>

int inverse(int num) {
    int inversedNum = 0;

    while (num != 0) {
        int remainder = num % 10;
        inversedNum = inversedNum * 10 + remainder;
        num /= 10;
    }
    return inversedNum;
}

int main() {
    int num, inversedNum;
    printf("Enter a number: ");
    scanf("%d", &num);

    inversedNum = inverse(num);
    printf("The inverse of %d is %d.", num, inversedNum);

    printf("\n\nProgrammed by Milan Bairagi");  // watermark

    return 0;
}