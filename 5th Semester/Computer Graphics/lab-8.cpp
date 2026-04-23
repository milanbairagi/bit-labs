// Lab 8 - Cohen-Sutherland Line Clipping Algorithm

#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>


int W = 800;
int H = 600;

struct RegionCode {
	int T;
	int B;
	int R;
	int L;
};

struct Line {
	float x1, y1, x2, y2;
};

float xmin, ymin, xmax, ymax;
Line line, clipped;
int accepted = 0;

RegionCode getCode(float x, float y) {
	RegionCode code = {0, 0, 0, 0};
	if (y > ymax) code.T = 1;
	else if (y < ymin) code.B = 1;
	if (x > xmax) code.R = 1;
	else if (x < xmin) code.L = 1;
	return code;
}

int codeValue(const RegionCode& code) {
	return code.T || code.B || code.R || code.L;
}

int clipLine(Line in, Line* out) {
	while (1) {
		RegionCode code1 = getCode(in.x1, in.y1);
		RegionCode code2 = getCode(in.x2, in.y2);
		int orValue = codeValue(code1) || codeValue(code2);
		int andValue = (code1.T && code2.T) || (code1.B && code2.B) || (code1.R && code2.R) || (code1.L && code2.L);

		if (orValue == 0) {
			*out = in;
			return 1;
		}

		if (andValue != 0) {
			return 0;
		}

		RegionCode codeOut = codeValue(code1) ? code1 : code2;
		float dx = in.x2 - in.x1;
		float dy = in.y2 - in.y1;
		float m = dy / dx;
		float x = 0.0f;
		float y = 0.0f;

		if (codeOut.T) {
			if (std::fabs(dy) < 1e-6f) return 0;
			x = in.x1 + (ymax - in.y1) / m;
			y = ymax;
		} else if (codeOut.B) {
			if (std::fabs(dy) < 1e-6f) return 0;
			x = in.x1 + (ymin - in.y1) / m;
			y = ymin;
		} else if (codeOut.L) {
			if (std::fabs(m) < 1e-6f) return 0;
			y = in.y1 + (xmin - in.x1) * m;
			x = xmin;
		} else if (codeOut.R) {
			if (std::fabs(m) < 1e-6f) return 0;
			y = in.y1 + (xmax - in.x1) * m;
			x = xmax;
		}

		if (codeValue(codeOut) == codeValue(code1)) {
			in.x1 = x;
			in.y1 = y;
		} else {
			in.x2 = x;
			in.y2 = y;
		}
	}
}

void drawText(float x, float y, const char* text) {
	glRasterPos2f(x, y);
	for (int i = 0; text[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();

	glColor3f(0.5f, 0.5f, 0.5f);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(line.x1, line.y1);
	glVertex2f(line.x2, line.y2);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	if (accepted) {
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(clipped.x1, clipped.y1);
		glVertex2f(clipped.x2, clipped.y2);
		glEnd();
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	drawText(20.0f, 580.0f, "Cohen-Sutherland Line Clipping");
	drawText(20.0f, 560.0f, "Blue: window, Gray: original line, Red: clipped line");
	if (accepted) {
		char msg[120];
		snprintf(msg, sizeof(msg), "Accepted: (%.2f, %.2f) to (%.2f, %.2f)", clipped.x1, clipped.y1, clipped.x2, clipped.y2);
		drawText(20.0f, 540.0f, msg);
	} else {
		drawText(20.0f, 540.0f, "Rejected: line outside the window");
	}

	drawText(20.0f, 520.0f, "Programmed by: Milan Bairagi");

	glFlush();
}

void keyboard(unsigned char key, int, int) {
	if (key == 27) {
		exit(0);
	}
}

int main(int argc, char** argv) {
	printf("Enter clipping window (xmin ymin xmax ymax): ");
	if (scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax) != 4) {
		printf("Invalid input.\n");
		return 1;
	}

	if (xmin > xmax || ymin > ymax) {
		printf("Invalid clipping window.\n");
		return 1;
	}

	printf("Enter line endpoints (x1 y1 x2 y2): ");
	if (scanf("%f %f %f %f", &line.x1, &line.y1, &line.x2, &line.y2) != 4) {
		printf("Invalid input.\n");
		return 1;
	}

	accepted = clipLine(line, &clipped);

	if (accepted) {
		printf("Line accepted after clipping.\n");
		printf("Clipped line: (%.2f, %.2f) to (%.2f, %.2f)\n", clipped.x1, clipped.y1, clipped.x2, clipped.y2);
	} else {
		printf("Line rejected (outside clipping window).\n");
	}

	glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lab 8 - Cohen-Sutherland - Milan Bairagi");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	gluOrtho2D(0, W, 0, H);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
