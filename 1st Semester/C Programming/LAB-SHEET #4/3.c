/*
3.Write a program to read the values of coefficient a, b and c of a quadratic equation
ax^2+bx+c=0 and find roots of the equation.
*/

#include <stdio.h>
#include <math.h>

void root(float a, float b, float c, float *root1, float *root2, float *imaginary) {
    /*
    get a, b, c of quadratic eqn and put the value of root1, root2 and imaginary part
    */
    // x = (-b ± √ (b^2 - 4ac) )/2a
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        *root1 = *root2 = -b / (2 * a);
        *imaginary = sqrt(-discriminant)/ (2 * a);
    } else {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
        *imaginary = 0;
    }
}

int main() {
    float a, b, c;
    float root1, root2;
    float imaginary;

    printf("Enter a, b, c of quadratic equation: ");
    scanf("%f %f %f", &a, &b, &c);
    
    // printf("%.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);

    root(a, b, c, &root1, &root2, &imaginary);

    if (imaginary != 0) {  // root contain imaginary part
        printf("1st root: %.2f + %.2fi\n", root1, imaginary);
        printf("2nd root: %.2f - %.2fi\n", root2, imaginary);
    } else {
        printf("1st root: %.2f\n", root1);
        printf("2nd root: %.2f\n", root2);
    }

    printf("\n\nProgrammed by Milan Bairagi");  // watermart

    return 0;
}