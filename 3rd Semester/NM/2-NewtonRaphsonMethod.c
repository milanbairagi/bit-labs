#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.0001
#define MAX_ITERATION 50

// f(x) = x^3 - x - 2
float f(float x) {
    return x * x * x - x - 2;
}

// f'(x) = 3x^2 - 1
float f_dash(float x) {
    return 3 * x * x - 1;
}

int main() {
    float x0, x1;
    int iteration = 0;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    x1 = x0;

    while (iteration < MAX_ITERATION) {
        float fx = f(x1);
        float fdx = f_dash(x1);

        x0 = x1;  // update previous approximation (x_i)
        x1 = x0 - fx / fdx;  // update approximationm using newton raphson method (x_(i=1))

        if (fabs(x1 - x0) < TOLERANCE || fabs(x1) < TOLERANCE) {
            printf("Root: %f", x1);
            printf("\nProgrammed by Milan Bairagi...");
            return 0;
        }

        iteration++;
    }

    printf("Maximum iteration reached. Best approximation: %f", x1);

    return 0;
}