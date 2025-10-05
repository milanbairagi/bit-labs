#include <stdio.h>
#include <math.h>

// f(x) = x^2
float f(float x) {
    return x * x;
}

float exact_integral_value(float a, float b) {
    return (pow(b, 3) / 3) - (pow(a, 3) / 3);
}

// Trapezoidal Rule
float trapezoidal_rule(float a, float b, int steps) {
    float h = (b - a) / steps;
    float sum = f(a) + f(b);

    for (int i = 1; i < steps; i++) {
        float x_i = a + i * h;
        sum += 2 * f(x_i);
    }

    return (h / 2) * sum;
}

// Romberg Integration
float romberg(float a, float b, int n) {
    float R[n][n];

    // First column using trapezoidal rule
    for (int i = 0; i < n; i++) {
        int steps = pow(2, i);
        R[i][0] = trapezoidal_rule(a, b, steps);
    }

    // Richardson Extrapolation
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            R[i][j] = (pow(4, j) * R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    // printf("Recursive Table:\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i + 1; j++) {
    //         printf("%f\t", R[i][j]);
    //     }
    //     printf("\n");
    // }

    return R[n-1][n-1];
}

int main() {
    float a, b;
    int n ;

    printf("Enter the interval (a, b): ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of sub-intervals (n): ");
    scanf("%d", &n);

    float integral = romberg(a, b, n);
    
    float exact_integral = exact_integral_value(a, b);

    // Display results
    printf("Approximate integral from %f to %f with n = %d: %f\n", a, b, n, integral);
    printf("Exact integral from %f to %f: %f\n", a, b, exact_integral);
    printf("Absolute error: %f\n", fabs(integral - exact_integral));

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}