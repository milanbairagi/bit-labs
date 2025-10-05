// Solving Ordinary Differential Equations Using 4th Order Runge-Kutta Method

#include <stdio.h>

// Function to represent the differential equation dy/dx = f(x, y) = x + y
float f(float x, float y) {
    return x + y;
}

void rk4(float x0, float y0, float h, float xn) {
    float x = x0, y = y0;

    printf("x\t\ty\n");
    printf("%f\t%f\n", x, y);

    while (x <= xn) {
        float k1 = f(x, y);
        float k2 = f(x + (h / 2.0), y + (h / 2.0) * k1);
        float k3 = f(x + (h / 2.0), y + (h / 2.0) * k2);
        float k4 = f(x + h, y + h * k3);

        y = y + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

        printf("%f\t%f\n", x, y);
        x += h;
    }
}

int main() {
    float x0, y0, h, xn;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);

    printf("Enter initial value y0: ");
    scanf("%f", &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter final value xn: ");
    scanf("%f", &xn);

    rk4(x0, y0, h, xn);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}