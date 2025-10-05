#include <stdio.h>
#define SIZE 10  // Maximum matrix size

void do_little_LU(float A[SIZE][SIZE], float L[SIZE][SIZE], float U[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        // Upper triangular matrix U
        for (int j = i; j < n; j++) {
            float sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }
        
        // Lower triangular matrix L
        for (int j = i; j < n; j++) {
            if (i == j) {
                L[i][i] = 1;  // Diagonal elements of L are 1
            } else {
                float sum = 0;
                for (int k = 0; k < i; k++) {
                    sum += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

void display_matrix(float matrix[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    float A[SIZE][SIZE], L[SIZE][SIZE] = {0}, U[SIZE][SIZE] = {0};
    
    printf("Enter the order of matrix (n): ");
    scanf("%d", &n);
    
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    
    do_little_LU(A, L, U, n);
    
    printf("\nLower Triangular Matrix (L):\n");
    display_matrix(L, n);
    
    printf("\nUpper Triangular Matrix (U):\n");
    display_matrix(U, n);
    
    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}