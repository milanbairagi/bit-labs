// Lab 1 - Write a program to implement DDA Line Drawing Algorithm

#include <GL/glut.h>
#include <cmath>

int W = 400, H = 400;

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(0, W, 0, H);

    glPointSize(4.0f);
}

void putPixel(int x, int y, float r = 0.0f, float g = 0.0f, float b = 0.0f) {
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2d(x, y);
    glEnd();
}

void drawDDALine(int x1, int y1, int x2, int y2, float r, float g, float b) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    if (steps == 0) {
        putPixel(x1, y1, r, g, b);
        return;
    }

    float x = (float)x1;
    float y = (float)y1;
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    for (int i = 0; i <= steps; i++) {
        putPixel((int)roundf(x), (int)roundf(y), r, g, b);
        x += xInc;
        y += yInc;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int x1 = 50, y1 = 50, x2 = 350, y2 = 350;

    drawDDALine(x1, y1, x2, y2, 1.0f, 0.0f, 0.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(W, H);
    glutCreateWindow("Lab 1 - Milan Bairagi");

    initGL();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}