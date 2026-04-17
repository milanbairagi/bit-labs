// Write a program to implement mid-point ellipse drawing algorithm
#include <stdio.h>

void print_ellipse_points(int xc, int yc, int x, int y) {
    printf("(%d, %d)\n", xc + x, yc + y);
    printf("(%d, %d)\n", xc - x, yc + y);
    printf("(%d, %d)\n", xc + x, yc - y);
    printf("(%d, %d)\n", xc - x, yc - y);
}

int main() {
    int xc, yc, rx, ry;
    int x = 0;
    int y;

    float dx, dy;
    float d1, d2;

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radii (rx ry): ");
    scanf("%d %d", &rx, &ry);

    if (rx < 0 || ry < 0) {
        printf("Radii cannot be negative.\n");
        return 1;
    }

    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25f * rx * rx);
    dx = 2.0f * ry * ry * x;
    dy = 2.0f * rx * rx * y;

    printf("Points generated using Mid-point Ellipse Algorithm:\n");

    while (dx < dy) {
        print_ellipse_points(xc, yc, x, y);

        x++;
        // dx += 2.0f * ry * ry;  // It is also correct way to update dx, but we can also calculate it in each iteration as shown below
        dx = 2.0f * ry * ry * x;

        if (d1 < 0) {
            d1 += dx + (ry * ry);
        } else {
            y--;
            // dy -= 2.0f * rx * rx;
            dy = 2.0f * rx * rx * y;
            d1 += dx - dy + (ry * ry);
        }
    }

    d2 = (ry * ry * (x + 0.5f) * (x + 0.5f)) +
         (rx * rx * (y - 1.0f) * (y - 1.0f)) -
         (rx * rx * ry * ry);

    while (y >= 0) {
        print_ellipse_points(xc, yc, x, y);

        y--;
        // dy -= 2.0f * rx * rx;
        dy = 2.0f * rx * rx * y;

        if (d2 > 0) {
            d2 += (rx * rx) - dy;
        } else {
            x++;
            // dx += 2.0f * ry * ry;
            dx = 2.0f * ry * ry * x;
            d2 += dx - dy + (rx * rx);
        }
    }

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}
