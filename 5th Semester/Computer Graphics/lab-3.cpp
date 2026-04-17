// Lab 3 - Write a program to implement mid-point circle drawing algorithm

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


void print_symmetric_points(int xc, int yc, int x, int y) {
    putPixel(xc + x, yc + y);
    putPixel(xc - x, yc + y);
    putPixel(xc + x, yc - y);
    putPixel(xc - x, yc - y);
    putPixel(xc + y, yc + x);
    putPixel(xc - y, yc + x);
    putPixel(xc + y, yc - x);
    putPixel(xc - y, yc - x);
    
}

void midPointCircle(int xc, int yc, int r) {
    int x = 0;
    int y;
    int p;

    if (r < 0) {
        return;
    }

    y = r;
    p = 1 - r;

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
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xc = 200, yc = 200, r = 100;

    midPointCircle(xc, yc, r);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("Lab 3 - Milan Bairagi");

    initGL();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}