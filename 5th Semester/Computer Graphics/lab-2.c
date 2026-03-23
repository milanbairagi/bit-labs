// Write a program to implement Bresenham's Line Drawing Algorithm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x1, y1, x2, y2;
    int dx, dy, p;

    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;

    printf("Points generated using Bresenham:\n");
    while (x1 < x2) {
        printf("(%d, %d)\n", x1, y1);
        x1++;

        if (p < 0) {
            p += 2 * dy;
        } else {
            p += 2 * (dy - dx);
            y1++;
        }
    }

    printf("\nProgrammed by Milan Bairagi..\n");

    return 0;
}
