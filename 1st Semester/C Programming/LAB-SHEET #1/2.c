/*
2. Write a program to enter two integers and then display their sum.
*/

#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    
    printf("The sum of is %d.", sum);
    
    printf("\n\nprogrammed by Milan Bairagi");
    
    return 0;
}
