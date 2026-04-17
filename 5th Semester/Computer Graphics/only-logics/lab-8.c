// Write a program to implement Cohen-Sutherland Line Clipping Algorithm
#include <stdio.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

static int compute_code(float x, float y, float xmin, float ymin, float xmax, float ymax) {
    int code = INSIDE;

    if (x < xmin) {
        code |= LEFT;
    } else if (x > xmax) {
        code |= RIGHT;
    }

    if (y < ymin) {
        code |= BOTTOM;
    } else if (y > ymax) {
        code |= TOP;
    }

    return code;
}

int main(void) {
    float xmin, ymin, xmax, ymax;
    float x1, y1, x2, y2;
    int code1, code2;
    int accept = 0;

    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);

    if (xmin > xmax || ymin > ymax) {
        printf("Invalid clipping window.\n");
        return 1;
    }

    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    code1 = compute_code(x1, y1, xmin, ymin, xmax, ymax);
    code2 = compute_code(x2, y2, xmin, ymin, xmax, ymax);

    while (1) {
        if ((code1 | code2) == 0) {
            accept = 1;
            break;
        }

        if (code1 & code2) {
            break;
        }

        {
            int out_code = code1 ? code1 : code2;
            float x, y;

            if (out_code & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (out_code & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (out_code & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (out_code == code1) {
                x1 = x;
                y1 = y;
                code1 = compute_code(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = compute_code(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        printf("Line accepted after clipping.\n");
        printf("Clipped line: (%.2f, %.2f) to (%.2f, %.2f)\n", x1, y1, x2, y2);
    } else {
        printf("Line rejected (outside clipping window).\n");
    }

    printf("\nProgrammed by Milan Bairagi..\n");

    return 0;
}
