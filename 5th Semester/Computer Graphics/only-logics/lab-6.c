// Write a program to implement flood fill algorithm
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int r;
    int c;
} Point;

static int in_bounds(int r, int c, int rows, int cols) {
    return (r >= 0 && r < rows && c >= 0 && c < cols);
}

static void print_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int rows, cols;
    int grid[MAX_SIZE][MAX_SIZE];
    int sr, sc, newColor;
    int oldColor;
    Point stack[MAX_SIZE * MAX_SIZE];
    int top = -1;
    int i, j;

    printf("Enter rows and columns (max 50 50): ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        printf("Invalid grid size.\n");
        return 1;
    }

    printf("Enter grid values row-wise:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter seed point (row col): ");
    scanf("%d %d", &sr, &sc);

    if (!in_bounds(sr, sc, rows, cols)) {
        printf("Seed point is out of bounds.\n");
        return 1;
    }

    printf("Enter new color: ");
    scanf("%d", &newColor);

    oldColor = grid[sr][sc];
    if (oldColor == newColor) {
        printf("No fill needed.\n");
        print_grid(grid, rows, cols);
        return 0;
    }

    stack[++top] = (Point){sr, sc};

    while (top >= 0) {
        Point p = stack[top--];
        int r = p.r;
        int c = p.c;

        if (!in_bounds(r, c, rows, cols)) {
            continue;
        }
        if (grid[r][c] != oldColor) {
            continue;
        }

        grid[r][c] = newColor;

        if (top + 4 >= MAX_SIZE * MAX_SIZE) {
            printf("Stack overflow risk: grid too large for fill traversal.\n");
            break;
        }

        stack[++top] = (Point){r + 1, c};
        stack[++top] = (Point){r - 1, c};
        stack[++top] = (Point){r, c + 1};
        stack[++top] = (Point){r, c - 1};
    }

    printf("Grid after flood fill:\n");
    print_grid(grid, rows, cols);

    printf("\nProgrammed by Milan Bairagi..\n");

    return 0;
}
