#include <stdio.h>

void booleanJoin(int A[][3], int B[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] || B[i][j];
        }
    }
}

void booleanMeet(int A[][3], int B[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] && B[i][j];
        }
    }
}

void booleanProduct(int A[][3], int B[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }
}

void printMatrix(int matrix[][3], int rows, int cols) {
    printf("+-     -+\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0) printf("| ");
            printf("%d ", matrix[i][j]);
            if (j == cols - 1) printf("|");
        }
        printf("\n");
    }
    printf("+-     -+\n");
}

int main() {
    int A[3][3] = {{0, 0, 1}, {0, 1, 0}, {0, 1, 0}};
    int B[3][3] = {{0, 1, 1}, {1, 1, 1}, {0, 0, 0}};

    int resultBooleanJoin[3][3];
    int resultBooleanMeet[3][3];
    int resultBooleanProduct[3][3];

    booleanJoin(A, B, resultBooleanJoin, 3, 3);
    booleanMeet(A, B, resultBooleanMeet, 3, 3);
    booleanProduct(A, B, resultBooleanProduct, 3, 3);

    printf("Boolean Join (Union) of A and B:\n");
    printMatrix(resultBooleanJoin, 3, 3);

    printf("Boolean Meet (Intersection) of A and B:\n");
    printMatrix(resultBooleanMeet, 3, 3);

    printf("Boolean Product of A and B:\n");
    printMatrix(resultBooleanProduct, 3, 3);

    printf("\nProgrammed by Milan Bairagi");

    return 0;
}