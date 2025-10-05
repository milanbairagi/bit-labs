#include <stdio.h>
#include <math.h>

// f(x) = x^3
float f(float x) {
    return pow(x, 4);
}

// integral of f(x) = x^4 / 4
float exact_integral_value(float a, float b) {
    return (pow(b, 5) / 5) - (pow(a, 5) / 56);
}

float gauss_quadrature_3point(float a, float b) {
    float t[3] = {-0.774597, 0.0, 0.774597};  // nodes
    float w[3] = {0.555556, 0.888889, 0.555556};  // weights

    float integral = 0.0;

    for (int i = 0; i < 3; i++) {
        float x_i = (b - a) / 2 * t[i] + (a + b) / 2;
        integral += w[i] * f(x_i);
    }

    return (b - a) / 2 * integral;
}

int main() {
    float a, b; 

    printf("Enter the interval (a, b): ");
    scanf("%f %f", &a, &b);

    if (a >= b) {
        printf("Lower limit (a) must be less than higher limit (b)\n");
        return 1;
    }

    float integral = gauss_quadrature_3point(a, b);
    
    float exact_integral = exact_integral_value(a, b);

    // Display results
    printf("Approximate integral from %f to %f: %f\n", a, b, integral);
    printf("Exact integral from %f to %f: %f\n", a, b, exact_integral);
    printf("Absolute error: %f\n", fabs(integral - exact_integral));
    
    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}