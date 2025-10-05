#include <stdio.h>
#include <math.h>

#define SIZE 10
#define TOLERANCE 0.0001

void solveLaplace(float grid[SIZE][SIZE], int n) {
    int converged = 0;
    while (!converged) {
        converged = 1;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                float old_value = grid[i][j];
                float new_value = 0.25 * (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]);
                if (fabs(new_value - old_value) > TOLERANCE) {
                    converged = 0;
                }
                grid[i][j] = new_value;
            }
        }
    }
}

void printGrid(float grid[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    float grid[SIZE][SIZE] = {0};
    
    printf("Enter the grid size: ");
    scanf("%d", &n);

    printf("Enter boundary conditions (edges of the grid):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                printf("grid[%d][%d] = ", i, j);
                scanf("%f", &grid[i][j]);
            }
        }
    }
    
    printf("\nGrid:\n");
    printGrid(grid, n);
    
    solveLaplace(grid, n);
    
    printf("\nSolution:\n");
    printGrid(grid, n);

    printf("\nProgrammed by Milan Bairagi...");
    
    return 0;
}