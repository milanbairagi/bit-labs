// Lab 6 - Flood Fill Algorithm using OpenGL GLUT

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

bool isSameColor(const GLubyte a[3], const GLubyte b[3]) {
	return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

void floodFill(int x, int y, const GLubyte targetColor[3]) {
	if (x < 0 || x >= W || y < 0 || y >= H) {
		return;
	}

	glReadBuffer(GL_FRONT);
	GLubyte pixel[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

	if (!isSameColor(pixel, targetColor)) {
		return;
	}

	putPixel(x, y, FILL_COLOR);
	usleep(delay);

	floodFill(x + 1, y, targetColor);
	floodFill(x - 1, y, targetColor);
	floodFill(x, y + 1, targetColor);
	floodFill(x, y - 1, targetColor);
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
		int seedY = H - y - 1;
		GLubyte targetColor[3];
		glReadBuffer(GL_FRONT);
		glReadPixels(x, seedY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, targetColor);

		if (!isSameColor(targetColor, FILL_COLOR)) {
			floodFill(x, seedY, targetColor);
		}
	}
}

void init() {
	glClearColor(BACKGROUND_COLOR[0] / 255.0f, BACKGROUND_COLOR[1] / 255.0f, BACKGROUND_COLOR[2] / 255.0f, 1.0f);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	gluOrtho2D(0, W, 0, H);
	// glMatrixMode(GL_MODELVIEW);
	// glPointSize(1.0f);
	// glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(W, H);
	// glutInitWindowPosition(100, 100);
	glutCreateWindow("Lab 6 - Flood Fill Algorithm - Milan Bairagi");

	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
