// Write a program to implement 2D transformation on an object
#include <math.h>
#include <stdio.h>

#define MAX_VERTICES 20

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static void print_polygon(float x[], float y[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("V%d = (%.2f, %.2f)\n", i + 1, x[i], y[i]);
    }
}

int main(void) {
    int n;
    float x[MAX_VERTICES], y[MAX_VERTICES];
    float tx, ty, sx, sy, angle, shx, shy;
    float rad;
    int choice;
    int i;

    printf("Enter number of polygon vertices (max 20): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter vertices (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("\nChoose transformation:\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation (about origin)\n");
    printf("4. Reflection about X-axis\n");
    printf("5. Reflection about Y-axis\n");
    printf("6. Reflection about Origin\n");
    printf("7. Shearing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter tx ty: ");
            scanf("%f %f", &tx, &ty);
            for (i = 0; i < n; i++) {
                x[i] += tx;
                y[i] += ty;
            }
            break;

        case 2:
            printf("Enter sx sy: ");
            scanf("%f %f", &sx, &sy);
            for (i = 0; i < n; i++) {
                x[i] *= sx;
                y[i] *= sy;
            }
            break;

        case 3:
            printf("Enter rotation angle (degrees): ");
            scanf("%f", &angle);
            rad = angle * (float)M_PI / 180.0f;
            for (i = 0; i < n; i++) {
                float newX = x[i] * cosf(rad) - y[i] * sinf(rad);
                float newY = x[i] * sinf(rad) + y[i] * cosf(rad);
                x[i] = newX;
                y[i] = newY;
            }
            break;

        case 4:
            for (i = 0; i < n; i++) {
                y[i] = -y[i];
            }
            break;

        case 5:
            for (i = 0; i < n; i++) {
                x[i] = -x[i];
            }
            break;

        case 6:
            for (i = 0; i < n; i++) {
                x[i] = -x[i];
                y[i] = -y[i];
            }
            break;

        case 7:
            printf("Enter shx shy: ");
            scanf("%f %f", &shx, &shy);
            for (i = 0; i < n; i++) {
                float newX = x[i] + shx * y[i];
                float newY = y[i] + shy * x[i];
                x[i] = newX;
                y[i] = newY;
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("\nTransformed vertices:\n");
    print_polygon(x, y, n);

    printf("\nProgrammed by Milan Bairagi..\n");

    return 0;
}
