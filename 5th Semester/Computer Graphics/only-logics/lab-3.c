// Write a program to implement mid-point circle drawing algorithm
#include <stdio.h>

void print_symmetric_points(int xc, int yc, int x, int y) {
    printf("(%d, %d)\n", xc + x, yc + y);
    printf("(%d, %d)\n", xc - x, yc + y);
    printf("(%d, %d)\n", xc + x, yc - y);
    printf("(%d, %d)\n", xc - x, yc - y);
    printf("(%d, %d)\n", xc + y, yc + x);
    printf("(%d, %d)\n", xc - y, yc + x);
    printf("(%d, %d)\n", xc + y, yc - x);
    printf("(%d, %d)\n", xc - y, yc - x);
}

int main() {
    int xc, yc, r;
    int x = 0;
    int y;
    int p;

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    if (r < 0) {
        printf("Radius cannot be negative.\n");
        return 1;
    }

    y = r;
    p = 1 - r;

    printf("Points generated using Mid-point Circle Algorithm:\n");
    while (x <= y) {
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        print_symmetric_points(xc, yc, x, y);

        x++;
    }

    printf("\nProgrammed by Milan Bairagi..\n");

    return 0;
}
