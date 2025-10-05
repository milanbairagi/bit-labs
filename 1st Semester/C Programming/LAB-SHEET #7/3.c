/*
Write a program to read two matrices of order 3*2,
add them and display the resultant matrix in matrix form.
*/

#include <stdio.h>

void printMatrix(int matrix[3][2]) {
    printf("+--  --+\n");
    for (int i = 0; i < 3; i++) {
        printf("|%-2d  %2d|\n", matrix[i][0], matrix[i][1]);
    }
    printf("+--  --+\n");
}

void readMatrix(int matrix[3][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrix(int mat1[3][2], int mat2[3][2], int result[3][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
int main() {
    int matrix1[3][2];
    int matrix2[3][2];
    int sumMatrix[3][2];

    printf("Enter the elements of 1st matrix:\n");
    readMatrix(matrix1);
    printf("Enter the elements of 2nd matrix:\n");
    readMatrix(matrix2);
    
    addMatrix(matrix1, matrix2, sumMatrix);

    printf("\nSum of matrix:\n");
    printMatrix(sumMatrix);

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}