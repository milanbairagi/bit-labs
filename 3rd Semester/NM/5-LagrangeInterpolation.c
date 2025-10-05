#include <stdio.h>

float li(float x_interp, float x[], int i, int n) {
    float res = 1;

    for (int j = 0; j < n; j++) {
        if (j != i) {
            res *= (x_interp - x[j]) / (x[i] - x[j]);
        }
    }

    return res;
}

float lagrange_interpolation(float x_interp, float x[], float y[], int n) {
    float res = 0;

    for (int i = 0; i < n; i++) {
        float l_i = li(x_interp, x, i, n);
        res += y[i] * l_i;
    }

    return res;
}

int main() {
    int n;
    float x_interp;
    
    printf("Enter number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d, y_%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the x value to interpolate at: ");
    scanf("%f", &x_interp);

    float result = lagrange_interpolation(x_interp, x, y, n);
    printf("Interpolated value at x=%f is %f\n", x_interp, result);
    
    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}