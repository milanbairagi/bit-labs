/*
4. Write a program to calculate simple interest for given P=4000, T=2 , R=5.5
*/

#include <stdio.h>

int main() {
    float p, t, r, i;
    p = 4000;
    t = 2;
    r = 5.5;

    i = p * t * r / 100;
    printf("The simple interest is %f.", i);
    printf("\n\nprogrammed by Milan Bairagi");
    return 0;
}