// Solving Ordinary Differential Equations Using Euler’s Method

#include <stdio.h>

// Function to represent the differential equation dy/dx = f(x, y) = x + y
float f(float x, float y) {
    return x + y;
}

void euler_method(float x0, float y0, float h, float xn) {
    float x = x0, y = y0;

    printf("x\t\ty\n");
    printf("%f\t%f\n", x, y);

    while (x < xn) {
        y = y + h * f(x, y);
        x = x + h;
        printf("%f\t%f\n", x, y);
    }
}

int main() {
    float x0, y0, h, xn;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);

    printf("Enter initial value y0: ");
    scanf("%f", &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter final value xn: ");
    scanf("%f", &xn);

    euler_method(x0, y0, h, xn);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}