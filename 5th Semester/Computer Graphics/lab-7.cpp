// Lab 7 - Write a program to implement 2D transformations on an object

#include <GL/glut.h>
#include <cmath>
#include <cstring>

int W = 800;
int H = 600;

struct Point2D {
	float x;
	float y;
};

Point2D originalObject[] = {
	{-80.0f, -50.0f},
	{80.0f, -50.0f},
	{80.0f, 50.0f},
	{-80.0f, 50.0f}
};

const int objectSize = sizeof(originalObject) / sizeof(originalObject[0]);

// Homogeneous transformation matrix for 2D operations.
float currentMatrix[3][3] = {
	{1.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 1.0f}
};

void drawText(float x, float y, const char* text) {
	glRasterPos2f(x, y);
	for (int i = 0; text[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}
}

void setIdentity(float m[3][3]) {
	std::memset(m, 0, sizeof(float) * 9);
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
}

void multiplyMatrix(const float a[3][3], const float b[3][3], float out[3][3]) {
	float temp[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = 0.0f;
			for (int k = 0; k < 3; k++) {
				temp[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out[i][j] = temp[i][j];
		}
	}
}

void prependTransform(const float t[3][3]) {
	float result[3][3];
	multiplyMatrix(t, currentMatrix, result);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			currentMatrix[i][j] = result[i][j];
		}
	}
}

Point2D transformPoint(const Point2D& p, const float m[3][3]) {
	Point2D out;
	out.x = m[0][0] * p.x + m[0][1] * p.y + m[0][2];
	out.y = m[1][0] * p.x + m[1][1] * p.y + m[1][2];
	return out;
}

void drawAxes() {
	glColor3f(0.85f, 0.85f, 0.85f);
	glBegin(GL_LINES);
	glVertex2f(-W / 2.0f, 0.0f);
	glVertex2f(W / 2.0f, 0.0f);
	glVertex2f(0.0f, -H / 2.0f);
	glVertex2f(0.0f, H / 2.0f);
	glEnd();
}

void drawPolygon(const Point2D points[], int n) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++) {
		glVertex2f(points[i].x, points[i].y);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	drawAxes();

	Point2D transformed[objectSize];
	for (int i = 0; i < objectSize; i++) {
		transformed[i] = transformPoint(originalObject[i], currentMatrix);
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	drawPolygon(originalObject, objectSize);

	glColor3f(1.0f, 0.0f, 0.0f);
	drawPolygon(transformed, objectSize);

	glColor3f(0.1f, 0.1f, 0.1f);
	drawText(-390.0f, 270.0f, "Keys: T-Translate, R-Rotate, S-Scale, H-ShearX, X-ReflectX, Y-ReflectY, O-Reset, Esc-Exit");
	drawText(-390.0f, 250.0f, "Black: original object, Red: transformed object");

	glFlush();
}

void applyTranslation(float tx, float ty) {
	float t[3][3] = {
		{1.0f, 0.0f, tx},
		{0.0f, 1.0f, ty},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(t);
}

void applyRotation(float degrees) {
	float rad = degrees * 3.14159265359f / 180.0f;
	float c = std::cos(rad);
	float s = std::sin(rad);

	float r[3][3] = {
		{c, -s, 0.0f},
		{s, c, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(r);
}

void applyScaling(float sx, float sy) {
	float s[3][3] = {
		{sx, 0.0f, 0.0f},
		{0.0f, sy, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(s);
}

void applyShearX(float shx) {
	float sh[3][3] = {
		{1.0f, shx, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(sh);
}

void applyReflectionX() {
	float rx[3][3] = {
		{1.0f, 0.0f, 0.0f},
		{0.0f, -1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(rx);
}

void applyReflectionY() {
	float ry[3][3] = {
		{-1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	prependTransform(ry);
}

void keyboard(unsigned char key, int, int) {
	switch (key) {
		case 't':
		case 'T':
			applyTranslation(30.0f, 20.0f);
			break;
		case 'r':
		case 'R':
			applyRotation(15.0f);
			break;
		case 's':
		case 'S':
			applyScaling(1.2f, 1.2f);
			break;
		case 'h':
		case 'H':
			applyShearX(0.2f);
			break;
		case 'x':
		case 'X':
			applyReflectionX();
			break;
		case 'y':
		case 'Y':
			applyReflectionY();
			break;
		case 'o':
		case 'O':
			setIdentity(currentMatrix);
			break;
		case 27:
			exit(0);
	}

	glutPostRedisplay();
}

void initGL() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-W / 2.0f, W / 2.0f, -H / 2.0f, H / 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setIdentity(currentMatrix);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lab 7 - 2D Transformation - Milan Bairagi");

	initGL();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
