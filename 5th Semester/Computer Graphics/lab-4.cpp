// Lab 4 - Write a program to implement mid-point ellipse drawing algorithm

#include <GL/glut.h>
#include <cmath>

int W = 400, H = 400;

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, W, 0, H);
    glPointSize(4.0f);
}


void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x, y);
    glEnd();
}


void print_symmetric_points(int xc, int yc, int x, int y) {
    putPixel(xc + x, yc + y);
    putPixel(xc - x, yc + y);
    putPixel(xc + x, yc - y);
    putPixel(xc - x, yc - y);
    
}

void midPointEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y;

    float dx, dy;
    float d1, d2;

    if (rx < 0 || ry < 0) {
        return;
    }

    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25f * rx * rx);
    dx = 2.0f * ry * ry * x;
    dy = 2.0f * rx * rx * y;

    while (dx < dy) {
        print_symmetric_points(xc, yc, x, y);

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
        print_symmetric_points(xc, yc, x, y);

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
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xc = 200, yc = 200, rx = 130, ry = 50;

    midPointEllipse(xc, yc, rx, ry);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("Lab 4 - Milan Bairagi");

    initGL();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}