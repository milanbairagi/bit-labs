// Lab 5 - Boundary fill algorithm using OpenGL GLUT

#include <GL/glut.h>
#include <unistd.h>

int W = 600;
int H = 400;
int delay = 2000; // Delay in microseconds (2 milliseconds)

const GLubyte FILL_COLOR[3] = {0, 255, 0};
const GLubyte BOUNDARY_COLOR[3] = {0, 0, 0};
const GLubyte BACKGROUND_COLOR[3] = {255, 255, 255};

void putPixel(int x, int y, const GLubyte color[3]) {
	glColor3ub(color[0], color[1], color[2]);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void boundaryFill(int x, int y) {
	if (x < 0 || x >= W || y < 0 || y >= H) {
		return;
	}

	glReadBuffer(GL_FRONT);
	GLubyte pixel[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

	if ((pixel[0] == BOUNDARY_COLOR[0] && pixel[1] == BOUNDARY_COLOR[1] && pixel[2] == BOUNDARY_COLOR[2]) ||
		(pixel[0] == FILL_COLOR[0] && pixel[1] == FILL_COLOR[1] && pixel[2] == FILL_COLOR[2])) {
		return;
	}

	putPixel(x, y, FILL_COLOR);
    usleep(delay);

	boundaryFill(x + 1, y);
	boundaryFill(x - 1, y);
	boundaryFill(x, y + 1);
	boundaryFill(x, y - 1);
}

void drawBoundary() {
	glColor3ub(BOUNDARY_COLOR[0], BOUNDARY_COLOR[1], BOUNDARY_COLOR[2]);
	glBegin(GL_LINE_LOOP);
	glVertex2i(120, 90);
	glVertex2i(120, 250);
	glVertex2i(280, 250);
	glVertex2i(280, 340);
	glVertex2i(480, 340);
	glVertex2i(480, 180);
	glVertex2i(340, 180);
	glVertex2i(340, 90);
	glEnd();

	glFlush();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawBoundary();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		boundaryFill(x, H - y - 1);
	}
}

void init() {
	glClearColor(BACKGROUND_COLOR[0] / 255.0f, BACKGROUND_COLOR[1] / 255.0f, BACKGROUND_COLOR[2] / 255.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, W, 0, H);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(1.0f);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lab 5 - Boundary Fill Algorithm - Milan Bairagi");

	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
