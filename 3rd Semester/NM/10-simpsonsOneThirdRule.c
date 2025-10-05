#include <stdio.h>
#include <math.h>

// f(x) = x^2
float f(float x) {
    return x * x;
}

float exact_integral_value(float a, float b) {
    return (b * b * b / 3) - (a * a * a / 3);
}

float simpson_one_third(float a, float b) {
    float h = (b - a) / 2;
    float m = (a + b) / 2;

    return (h / 3) * (f(a) + 4 * f(m) + f(b));
}

int main() {
    float a, b;

    printf("Enter the interval (a, b): ");
    scanf("%f %f", &a, &b);

    if (a >= b) {
        printf("Lower limit (a) must be less than higher limit (b)\n");
        return 1;
    }

    float integral = simpson_one_third(a, b);
    
    float exact_integral = exact_integral_value(a, b);

    // Display results
    printf("Approximate integral from %f to %f: %f\n", a, b, integral);
    printf("Exact integral from %f to %f: %f\n", a, b, exact_integral);
    printf("Absolute error: %f\n", fabs(integral - exact_integral));

    printf("\nProgrammed by Milan Bairagi...");
    
    return 0;
}