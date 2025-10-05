#include <stdio.h>

void gauss_elimination(int n, float A[n][n], float B[n]) {
    float factor;

    // Forward Elimination
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            factor = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
        }
    }

    // Back Substitution
    float x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Displaying the solution
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float A[n][n], B[n];
    printf("Enter the coefficients matrix A (row by row):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the constants vector B:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%f", &B[i]);
    }

    gauss_elimination(n, A, B);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}