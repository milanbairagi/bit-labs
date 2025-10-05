#include <stdio.h>
#include <math.h>

// f(x) = x^2
float f(float x) {
    return x * x;
}

// Actual derivative function: f'(x) - 2x
float f_dash(float x) {
    return 2 * x;
}

float forward_difference(float x, float h) {
    return (f(x + h) - f(x)) / h;
}

int main() {
    float x;
    float h;

    printf("Enter the point x: ");
    scanf("%f", &x);
    printf("Enter the step size h: ");
    scanf("%f", &h);

    // Check for invalid step size
    if (h <= 0) {
        printf("Step size h must be positive.\n");
        return 1;
    }

    float derivative = forward_difference(x, h);

    float exact_derivative = f_dash(x);

    printf("Approximate derivative at x = %f using h = %f: %f\n", x, h, derivative);
    printf("Exact derivative at x = %f: %f\n", x, exact_derivative);
    printf("Absolute error: %f\n", fabs(derivative - exact_derivative));

    printf("\nProgrammed by Milan Bairagi...");


    return 0;
}