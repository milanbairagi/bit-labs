#include <stdio.h>
#include <math.h>
#define SIZE 10  // Maximum matrix size
#define TOLERANCE 0.0001 // Convergence criteria

void jacobiIteration(float A[SIZE][SIZE], float B[SIZE], float X[SIZE], int n) {
    float tempX[SIZE];
    int iterations = 0;
    int converged;
    
    do {
        converged = 1;
        for (int i = 0; i < n; i++) {
            float sum = B[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            tempX[i] = sum / A[i][i];
        }
        
        for (int i = 0; i < n; i++) {
            if (fabs(tempX[i] - X[i]) > TOLERANCE) {
                converged = 0;
            }
            X[i] = tempX[i];
        }
        iterations++;
    } while (!converged);
    
    printf("Solution after %d iterations:\n", iterations);
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, X[i]);
    }
}

int main() {
    int n;
    float A[SIZE][SIZE], B[SIZE], X[SIZE] = {0};
    
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    
    printf("Enter the elements of vector B:\n");
    for (int i = 0; i < n; i++) {
        printf("B[%d] = ", i);
        scanf("%f", &B[i]);
    }
    
    jacobiIteration(A, B, X, n);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}