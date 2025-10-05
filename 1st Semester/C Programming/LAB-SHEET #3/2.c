/*
Given the three numbers a(=8) , b(=4) and constant value of PI = 3.1415, 
calculate and display the following using macros (preprocessor directives).
*/

#include <stdio.h>

#define PI 3.1415
#define CIRCLE_AREA(r) (PI * r * r)


int main() {
    int a = 8, b = 4;

    printf("Area of circle with radius %d: %.2f\n", a, CIRCLE_AREA(a));
    printf("Area of circle with radius %d: %.2f\n", b, CIRCLE_AREA(b));
        
    printf("\n\nProgrammed by Milan Bairagi");

    return 0;
}