// Write a program to implement DDA Line Drawing Algorithm
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2;
    float dx, dy, xInc, yInc, x, y;
    int steps;

    printf("Enter x1 y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%f %f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (fabsf(dx) > fabsf(dy)) {
        steps = (int)fabsf(dx);
    } else {
        steps = (int)fabsf(dy);
    }

    if (steps == 0) {
        printf("Plotted point: (%d, %d)\n", (int)roundf(x1), (int)roundf(y1));
        return 0;
    }

    xInc = dx / steps;
    yInc = dy / steps;

    x = x1;
    y = y1;

    printf("Points generated using DDA:\n");
    for (int i = 0; i <= steps; i++) {
        printf("(%d, %d)\n", (int)roundf(x), (int)roundf(y));
        x += xInc;
        y += yInc;
    }

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}