#include <stdio.h>

#define MAX_SIZE 10  // Maximum matrix size

void gauss_jordan(float A[MAX_SIZE][MAX_SIZE + 1], int n) {
    // A is the augmented matrix [A | b], with n rows and n+1 columns
    for (int k = 0; k < n; k++) {
        // Normalize pivot row (make pivot = 1)
        float pivot = A[k][k];
        for (int j = k; j < n + 1; j++) {
            A[k][j] /= pivot;
        }

        // Eliminate column k above and below the pivot
        for (int i = 0; i < n; i++) {
            if (i != k) {
                float factor = A[i][k];
                for (int j = k; j < n + 1; j++) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }
    }
}

int main() {
    int n;  // Size of the system
    float A[MAX_SIZE][MAX_SIZE + 1];  // Augmented matrix [A | b]
    float x[MAX_SIZE];  // Solution vector

    // Input size of the system
    printf("Enter the number of equations (n): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Input coefficient matrix A and constants vector b
    printf("Enter the coefficients of matrix A and constants b (row-wise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
        printf("b[%d] = ", i);
        scanf("%f", &A[i][n]);
    }

    // Solve the system using Gauss-Jordan
    gauss_jordan(A, n);

    // Extract solution from the augmented matrix
    for (int i = 0; i < n; i++) {
        x[i] = A[i][n];
    }

    // Display the solution
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}