/*
Wap that access the members of a structure using dot
operator. Create a structure to store information about
a rectangle, including its length and width. Compute
its area and print to the console.
*/

#include <stdio.h>

struct rectangle {
    float length;
    float width;
} rct;

int main() {
    printf("Enter the length of Rectangle: ");
    scanf("%f", &rct.length);
    printf("Enter the width of the Rectangle: ");
    scanf("%f", &rct.width);

    printf("Area of rectangle: %.2f", rct.length * rct.width);
    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}