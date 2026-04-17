// Lab 2 - Write a program to implement Bresenham's Line Drawing Algorithm

#include <GL/glut.h>
#include <cmath>

int W = 400, H = 400;

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, W, 0, H);
    glPointSize(4.0f);
}


void putPixel(int x, int y, float r = 0.0f, float g = 0.0f, float b = 0.0f) {
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2d(x, y);
    glEnd();
}

void drawBresenhamLine(int x1, int y1, int x2, int y2) {
    int dx, dy, p;

    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;

    while (x1 < x2) {
        putPixel(x1, y1);
        x1++;

        if (p < 0) {
            p += 2 * dy;
        } else {
            p += 2 * (dy - dx);
            y1++;
        }
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int x1 = 50, y1 = 50, x2 = 350, y2 = 350;

    drawBresenhamLine(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("Lab 2 - Milan Bairagi");

    initGL();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}