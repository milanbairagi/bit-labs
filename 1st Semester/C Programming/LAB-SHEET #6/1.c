/*
Write a program to calculate sum of first 50 natural numbers using recursive function.
*/
#include <stdio.h>


int sumOfNaturalNumbers(int num) {
    if (num <= 1) {
        return num;
    } 
    return num + sumOfNaturalNumbers(num - 1);
}


int main() {
    int num = 50;
    int sum = sumOfNaturalNumbers(num);

    printf("The sum of first %d natural numbers is %d.", num, sum);

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}