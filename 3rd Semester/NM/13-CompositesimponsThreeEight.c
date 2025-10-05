#include <stdio.h>
#include <math.h>

// f(x) = x^3
float f(float x) {
    return x * x * x;
}

// integral of f(x) = x^4 / 4
float exact_integral_value(float a, float b) {
    return (pow(b, 4) / 4) - (pow(a, 4) / 4);
}

float simpsons_three_eighth(float a, float b, int n) {
    float h = (b - a) / n;
    float sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        float x_i = a + i * h;

        if (i % 3 == 0)
            sum += 2 * f(x_i);
        else
            sum += 3 * f(x_i);
    }

    return (3.0 / 8.0) * h * sum;
}

int main() {
    float a, b;
    int n;   

    printf("Enter the interval (a, b): ");
    scanf("%f %f", &a, &b);

    printf("Enter the number of sub-intervals (n): ");
    scanf("%d", &n);

    if (a >= b) {
        printf("Lower limit (a) must be less than higher limit (b)\n");
        return 1;
    }

    if (n <= 0) {
        printf("The sub-intervals must be positive.\n");
        return 1;
    }

    if (n % 3 != 0) {
        printf("Number of subintervals (n) must be multiple of 3.\n");
        return 1;
    }

    float integral = simpsons_three_eighth(a, b, n);
    
    float exact_integral = exact_integral_value(a, b);

    // Display results
    printf("Approximate integral from %f to %f with n = %d: %f\n", a, b, n, integral);
    printf("Exact integral from %f to %f: %f\n", a, b, exact_integral);
    printf("Absolute error: %f\n", fabs(integral - exact_integral));

    printf("\nProgrammed by Milan Bairagi...");
    
    return 0;
}