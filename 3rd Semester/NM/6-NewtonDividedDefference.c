#include <stdio.h>

// Recursive function to calculate divided differences
float divided_difference(float x[], float y[], int i, int j) {
    if (i == j) {
        return y[i];
    }
    return (divided_difference(x, y, i + 1, j) - divided_difference(x, y, i, j - 1)) / (x[j] - x[i]);
}

float newton_interpolation(float x[], float y[], int n, float value) {
    float result = y[0];
    float term = 1;

    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]);
        result += term * divided_difference(x, y, 0, i);
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d, y_%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    float value;
    printf("\nEnter the value to interpolate: ");
    scanf("%f", &value);

    float result = newton_interpolation(x, y, n, value);
    printf("\nInterpolated value at x = %.4f is %.4f\n", value, result);
    
    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}