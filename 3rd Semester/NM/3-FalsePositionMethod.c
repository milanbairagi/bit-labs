#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.0001
#define MAX_ITERATION 100

// f(x) = x^3 - x - 2
float f(float x) {
    return x * x * x - x - 2;
}


int main() {
    float a, b, c;
    int iteration = 0;

    printf("Enter the initial interval [a, b]: ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) >= 0) {
        printf("There is no roots in the interval.\n");
        return 1;
    }

    while (iteration < MAX_ITERATION) {
        c = a - (f(a) * (b - a)) / (f(b) - f(a));

        if (fabs(f(c)) < TOLERANCE || fabs(b - a) < TOLERANCE) {
            printf("Root: %f\n", c);
            printf("\nProgrammed by Milan Bairagi...");
            return 0;
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    return 0;
}