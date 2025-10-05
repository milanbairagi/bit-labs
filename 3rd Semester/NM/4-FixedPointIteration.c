#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.0001
#define MAX_ITERATION 50

// g(x) = (x + 2)^(1/3)
float g(float x) {
    return pow(x + 2, 1.0 / 3.0);
}

// f(x) = x^3 - x - 2
float f(float x) {
    return x * x * x - x - 2;
}

int main() {
    float x0, x1;  // current and next approximations
    int iteration = 0;

    printf("Enter the initial guess: ");
    scanf("%f", &x0);

    x1 = x0;

    // Fixed point iteration loop
    while (iteration < MAX_ITERATION) {
        x0 = x1;
        x1 = g(x0);

        // Check stopping condition
        if (fabs(x1 - x0) < TOLERANCE) {
            printf("Root found: %f\n", x1);
            printf("f(x) at root: %f\n", f(x1));
            printf("\nProgrammed by Milan Bairagi...");
            return 0;
        }

        iteration++;
    }

    // If max iterations reached without convergence
    printf("Maximum iterations reached. Best approximation: %f\n", x1);
    printf("f(x) at approximation: %f\n", f(x1));
    return 0;
}