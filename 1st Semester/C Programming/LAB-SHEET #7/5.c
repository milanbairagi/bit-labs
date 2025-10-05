/*
Write a program to multiply two 3*3 matrix.
*/

#include <stdio.h>

void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[3][3]) {
    printf("+--           --+\n");
    for (int i = 0; i < 3; i++) {
        printf("| %-3d  %-3d  %3d |\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
    printf("+--           --+\n");
}

int main() {
    int matrix1[3][3] = {
        {2, 5, 3},
        {6, 8, 4},
        {7, 9, 4}
    };
    int matri2[3][3] = {
        {2, 5, 3},
        {6, 9, 4},
        {8, 9, 4}
    };
    int product[3][3];

    multiplyMatrices(matrix1, matri2, product);

    printf("The product of the two matrices is: \n");
    printMatrix(product);

    printf("\n\nProgrammed by Milan Bairagi");
    return 0;
}