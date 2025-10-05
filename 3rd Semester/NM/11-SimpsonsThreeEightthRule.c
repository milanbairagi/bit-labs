#include <stdio.h>
#include <math.h>

// f(x) = x^3
float f(float x) {
    return x * x * x;
}

// integral of f(x) is x^4 / 4
float exact_integral_value(float a, float b) {
    return (pow(b, 4) / 4) - (pow(a, 4) /4);
}

float simpson_three_eighth(float a, float b) {
    float h = (b - a) / 3;

    return (3.0 / 8.0) * h * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

int main() {
    float a, b;

    printf("Enter the interval (a, b): ");
    scanf("%f %f", &a, &b);

    if (a >= b) {
        printf("Lower limit (a) must be less than higher limit (b)\n");
        return 1;
    }

    float integral = simpson_three_eighth(a, b);
    
    float exact_integral = exact_integral_value(a, b);

    // Display results
    printf("Approximate integral from %f to %f: %f\n", a, b, integral);
    printf("Exact integral from %f to %f: %f\n", a, b, exact_integral);
    printf("Absolute error: %f\n", fabs(integral - exact_integral));
    
    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}