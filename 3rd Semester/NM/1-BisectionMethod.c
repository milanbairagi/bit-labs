#include <stdio.h>

#define tolerance 0.0001
#define maxIteration 100

// Equation: x^2 - 3 = 0
float f(float x) {
    return x * x - 3;
}

int main() {
    float a, b, m;
    int iteration = 0;

    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);
    
    if (f(a) * f(b) > 0) {
        printf("Root does not exist in the given interval\n");
        return 1;
    }


    while (iteration < maxIteration) {
        m = (a + b) / 2;
        if (f(m) == 0 || (b - a) < tolerance) {
            printf("Root: %f", m);

            printf("\nProgrammed by Milan Bairagi...");
            return 0;
        }

        if (f(a) * f(m) < 0) {
            b = m;
        } else {
            a = m;
        }

        iteration++;
    }

    printf("Maximum iteration reached. Best approximation: %f", m);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}